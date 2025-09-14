#include<gtk/gtk.h>


typedef struct view_factory {
    GtkWidget *stack;
}ViewFactory;

extern ViewFactory *factory;

ViewFactory *create_view_factory();

void destroy_view_factory(ViewFactory *factory);

void view_factory_add_view(ViewFactory *factory, const char *name, GtkWidget *view);

void view_factory_switch(ViewFactory *factory, const char *name);