#include <gtk/gtk.h>
#include "vdctypes.h"

void vdc_handler_save(GtkWidget *widget, gpointer data) {
    // TODO: save handler
}
void vdc_handler_cancel(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}
void vdc_handler_orientation(GtkWidget *widget, gpointer data) {
    enum orientation orientation;

    // only handle newly-selected orientation
    if(!gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget))) {
        return;
    }

    // names are like "orientation_1", so choose 12th character to switch by
    orientation = (enum orientation) (gtk_widget_get_name(widget)[12] - '0');

    // TODO: save orientation
}
void vdc_handler_scda(GtkWidget *widget, gpointer data) {
    struct select_data select_data;

    select_area(&select_data);

    g_print("%i %i %i %i\n", select_data.rect.x, select_data.rect.y,
                             select_data.rect.width, select_data.rect.height);

    // TODO: update labels and save select data
}
