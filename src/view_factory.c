#include"view_factory.h"



ViewFactory *factory = NULL;


 /**
 * @brief Creates and initializes a new ViewFactory instance.
 *
 * Allocates memory for a ViewFactory object and sets up its internal GtkStack.
 * If allocation or initialization fails, prints an error and returns NULL.
 *
 * @return Pointer to the newly created ViewFactory, or NULL on failure.
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
 * @brief Destroys a ViewFactory instance and frees its resources.
 *
 * Unreferences the internal GtkStack and frees the ViewFactory memory.
 * If the factory or its stack is NULL, the function exits safely.
 *
 * @param factory Pointer to the ViewFactory to be destroyed.
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
 * @brief Adds a named view (widget) to the factory's stack.
 *
 * Registers a GtkWidget with a unique name in the GtkStack managed by the factory.
 * If any parameter is NULL, the function exits without action.
 *
 * @param factory Pointer to the ViewFactory.
 * @param name Unique name for the view.
 * @param view GtkWidget to be added.
 */
void view_factory_add_view(ViewFactory *factory, const char *name, GtkWidget *view){
    if((factory == NULL) || (factory->stack == NULL ) || (name == NULL) || (view == NULL) ){
        return;
    }   
    gtk_stack_add_named(GTK_STACK((factory->stack)), view,name);
}



/**
 * @brief Switches the visible view in the factory's stack.
 *
 * Sets the visible child of the GtkStack to the view associated with the given name.
 * If the factory or name is NULL, prints an error message.
 *
 * @param factory Pointer to the ViewFactory.
 * @param name Name of the view to be displayed.
 */
void view_factory_switch(ViewFactory *factory, const char *name) {
    if(factory == NULL || name == NULL){
        g_printerr("%s\n", "nonexisting factory or view");
    }
    gtk_stack_set_visible_child_name(GTK_STACK(factory->stack), name);
}