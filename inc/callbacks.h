#include<gtk/gtk.h>



void activate(GtkApplication *app);

GtkWidget *create_main_view(GtkWidget *window);

GtkWidget *create_second_view(GtkWidget *window);

void on_button_clicked(GtkWidget *button, gpointer data);