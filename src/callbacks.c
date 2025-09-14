#include<gtk/gtk.h>
#include"callbacks.h"
#include"view_factory.h"




/**
 * @brief Loads CSS styling from an external file.
 *
 * Applies the styles defined in "style.css" to the GTK application using
 * GtkCssProvider. The provider is added with user-level priority.
 */
void load_css(void) {
    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(provider, "../style.css");

    gtk_style_context_add_provider_for_display(
        gdk_display_get_default(),
        GTK_STYLE_PROVIDER(provider),
        GTK_STYLE_PROVIDER_PRIORITY_USER
    );

    g_object_unref(provider);
}



/**
 * @brief Activates the GTK application and sets up the main window.
 *
 * Initializes the ViewFactory, creates the main and second views,
 * adds them to the factory's stack, and sets the initial visible view.
 *
 * @param app Pointer to the GtkApplication instance.
 */
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



/**
 * @brief Callback triggered when a button is clicked.
 *
 * Prints a message and switches the visible view to "second_view".
 *
 * @param button Pointer to the clicked GtkWidget.
 * @param data Pointer to the ViewFactory instance.
 */
void on_button_clicked(GtkWidget *button, gpointer data){
    g_print("I was clicked");
    view_factory_switch((ViewFactory *)data, "second_view");
}



/**
 * @brief Creates the main view layout.
 *
 * Constructs a GtkGrid containing a GtkTextView and a button.
 * The button switches to the second view when clicked.
 *
 * @param window Pointer to the parent GtkWindow.
 * @return GtkWidget* representing the main view.
 */
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



/**
 * @brief Creates the second view layout.
 *
 * Constructs a GtkGrid containing a single button.
 * The button switches to the second view when clicked.
 *
 * @param window Pointer to the parent GtkWindow.
 * @return GtkWidget* representing the second view.
 */
GtkWidget *create_second_view(GtkWidget *window){
     GtkWidget *grid = NULL;
    grid = gtk_grid_new();
    gtk_widget_set_valign(grid, GTK_ALIGN_START);
    gtk_widget_set_halign(grid, GTK_ALIGN_CENTER);
    GtkWidget *button = NULL;

    button = gtk_button_new_with_label("second test button");
    // g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), factory);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 1, 1);



    return grid;

}




