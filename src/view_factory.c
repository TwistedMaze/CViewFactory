#include"view_factory.h"



ViewFactory *factory = NULL;

/**
 * @brief Create a pointer view factory object
 * 
 * @return ViewFactory* 
 */
ViewFactory *create_view_factory(){
factory = g_malloc(sizeof(ViewFactory));
if (!factory) {
        fprintf(stderr, "Memory allocation for ViewFactory failed!\n");
        return NULL;
    }
factory->stack = gtk_stack_new();
if (!factory->stack) {
        fprintf(stderr, "Memory allocation for ViewFactory Stack failed!\n");
        return NULL;
    }
    if (!GTK_IS_STACK(factory->stack)) {
        g_printerr("Factory stack creation failed!\n");
        g_free(factory);
        return NULL;
    }

return factory;
}


/**
 * @brief destroys an existing ViewFactory object
 * 
 * @param factory 
 */
void destroy_view_factory(ViewFactory *factory){

    if(factory == NULL){
        return;
    }
    if(factory->stack == NULL){
        g_free(factory);
        return;    
    }
    g_object_unref(factory->stack);
    g_free(factory);
}

/**
 * @brief adds a widget with a view to the factory's stack
 * 
 * @param factory 
 * @param name 
 * @param view 
 */
void view_factory_add_view(ViewFactory *factory, const char *name, GtkWidget *view){
    if((factory == NULL) || (factory->stack == NULL ) || (name == NULL) || (view == NULL) ){
        return;
    }   
    gtk_stack_add_named(GTK_STACK((factory->stack)), view,name);
}



/**
 * @brief switches the visible child to the view with name name
 * 
 * @param factory 
 * @param name 
 */
void view_factory_switch(ViewFactory *factory, const char *name) {
    if(factory == NULL || name == NULL){
        g_printerr("%s\n", "nonexisting factory or view");
    }
    gtk_stack_set_visible_child_name(GTK_STACK(factory->stack), name);
}