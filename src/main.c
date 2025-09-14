#include<stdio.h>
#include<gtk/gtk.h>
#include"callbacks.h"



int main(int argc, char **argv){

     
    int status;
    GtkApplication *app = gtk_application_new("com.example.factory", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate),NULL);
    status = g_application_run(G_APPLICATION(app),argc, argv);
    g_object_unref(app);
    
    return status;


}