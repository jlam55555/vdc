#include <gtk/gtk.h>

void vdc_handler_save(GtkWidget * widget, gpointer data) {
    g_print("Hello world from save\n");
}
void vdc_handler_cancel(GtkWidget * widget, gpointer data) {
    gtk_main_quit();
}
