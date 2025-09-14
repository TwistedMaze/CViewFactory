#include<gtk/gtk.h>
#include"callbacks.h"
#include"view_factory.h"





void load_css(void) {
    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(provider, "style.css");

    gtk_style_context_add_provider_for_display(
        gdk_display_get_default(),
        GTK_STYLE_PROVIDER(provider),
        GTK_STYLE_PROVIDER_PRIORITY_USER
    );

    g_object_unref(provider);
}


void activate(GtkApplication *app){
    load_css();
    GtkWidget *window;

    factory = create_view_factory();
    if (!factory)
    {
        fprintf(stderr, "%s\n", "factory not properly created");
    }
    
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window),"View Factory Test");
    gtk_window_set_default_size(GTK_WINDOW(window), 640, 480);
    gtk_window_set_child(GTK_WINDOW(window), factory->stack);
    
    GtkWidget *main_view = create_main_view(window);
    GtkWidget *second_view = create_second_view(window);
     // Add main_view to factory's stack so it becomes switchable
    view_factory_add_view(factory, "main_view", main_view);
    view_factory_add_view(factory, "second_view", second_view);

    // Set main_view as the visible view
    view_factory_switch(factory, "main_view");

    gtk_window_present(GTK_WINDOW(window));

}


void on_button_clicked(GtkWidget *button, gpointer data){
    g_print("I was clicked");
    view_factory_switch((ViewFactory *)data, "second_view");
}



GtkWidget *create_main_view(GtkWidget *window){
    
    
    GtkWidget *grid = NULL;
    grid = gtk_grid_new();
    gtk_widget_set_valign(grid, GTK_ALIGN_START);
    gtk_widget_set_halign(grid, GTK_ALIGN_CENTER);
    GtkWidget *button = NULL;

    GtkTextBuffer *textBuffer = NULL;
    GtkWidget *view = NULL;

    view = gtk_text_view_new();
    textBuffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (view));
    gtk_text_buffer_set_text(textBuffer,"TEST TEXT ", -1);

    gtk_grid_attach(GTK_GRID(grid), view,3, 1, 1, 1);

    button = gtk_button_new_with_label("test button");
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), factory);
    gtk_grid_attach(GTK_GRID(grid), button, 3, 3, 1, 1);



    return grid;


}

GtkWidget *create_second_view(GtkWidget *window){
     GtkWidget *grid = NULL;
    grid = gtk_grid_new();
    gtk_widget_set_valign(grid, GTK_ALIGN_START);
    gtk_widget_set_halign(grid, GTK_ALIGN_CENTER);
    GtkWidget *button = NULL;

    button = gtk_button_new_with_label("second test button");
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), factory);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 1, 1);



    return grid;

}




