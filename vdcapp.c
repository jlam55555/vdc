#include <gtk/gtk.h>

// set up window using gtkbuilder
void vdc_activate(GtkApplication *app, gpointer user_data) {
    GtkBuilder *builder;
    GtkWidget *window;

    builder = gtk_builder_new_from_resource(
                  "/com/github/jlam55555/vdc/vdcui.glade");
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);


    /** TODO: working here **/

    GtkImage *image = GTK_IMAGE(gtk_image_new_from_file("image.jpeg"));
    GdkPixbuf *pixbuf = gtk_image_get_pixbuf(image);

    GObject *list_store = gtk_builder_get_object(builder, "orientation_list_store");

    GtkTreeIter *tree_iter;
//    gtk_tree_model_get_iter_first(GTK_TREE_MODEL(list_store), tree_iter);
//    gtk_list_store_set(GTK_LIST_STORE(list_store), tree_iter, pixbuf);

    /** TODO: end working here **/

    g_object_unref(builder);

    gtk_widget_show(window);
    gtk_main();
}

// start gtk application
int main(int argc, char **argv) {

    GtkApplication *app;
    int status;

    gtk_init(&argc, &argv);
    app = gtk_application_new("com.github.jlam55555.vdc",
                              G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(vdc_activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
