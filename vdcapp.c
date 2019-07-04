#include <gtk/gtk.h>

// set up window using gtkbuilder
void vdc_activate(GtkApplication *app, gpointer user_data) {
    GtkBuilder *builder;
    GtkWidget *window;

    builder = gtk_builder_new_from_resource(
                  "/com/github/jlam55555/vdc/vdcui.glade");
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);

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
