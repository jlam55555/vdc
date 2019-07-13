#include <gtk/gtk.h>
#include "vdcapp.h"

// useful for writing to labels
#define MAX_LABEL_LEN 30
#define write_label(label_id, format_string, data)                     \
            gchararray text_##label_id = (gchararray)                  \
                              g_malloc(MAX_LABEL_LEN * sizeof(gchar)); \
            g_snprintf(text_##label_id, MAX_LABEL_LEN,                 \
                       format_string, vdc_settings.data);              \
            gtk_label_set_text(GTK_LABEL(vdc_gtk_widgets.label_id),    \
                               text_##label_id);                       \
            g_free(text_##label_id)

void vdc_handler_save(GtkWidget *widget, gpointer data) {
    // TODO: save handler
}
void vdc_handler_restore(GtkWidget *widget, gpointer data) {
    vdc_settings_set_default();

    // TODO: update this as more settings are added
    write_label(da_x, "%i", rect.x);
    write_label(da_y, "%i", rect.y);
    write_label(da_width, "%i", rect.width);
    write_label(da_height, "%i", rect.height);
    write_label(screen_width, "%i", screen.width);
    write_label(screen_height, "%i", screen.height);
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
    vdc_settings.orientation = orientation;
}

void vdc_handler_scda(GtkWidget *widget, gpointer data) {
    struct select_data select_data;

    select_area(&select_data);

    // save settings to vdc_settings
    vdc_settings.rect = select_data.rect;
    vdc_settings.screen = select_data.screen;

    // set label texts
    write_label(da_x, "%i", rect.x);
    write_label(da_y, "%i", rect.y);
    write_label(da_width, "%i", rect.width);
    write_label(da_height, "%i", rect.height);
    write_label(screen_width, "%i", screen.width);
    write_label(screen_height, "%i", screen.height);
}
