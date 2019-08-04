#include <gtk/gtk.h>
#include "vdcapp.h"

struct vdc_settings vdc_settings;
struct vdc_gtk_widgets vdc_gtk_widgets;

// (re)set vdc_settings
void vdc_settings_set_default(void) {
    vdc_settings = (struct vdc_settings) {
        .orientation = ORI_DEFAULT,
        .rect = { x: 0, y: 0, width: 0, height: 0 },
        .screen = { x: 0, y: 0, width: 0, height: 0 }
    };
}

// initialize gtk widgets
#define expose(gtk_id) (vdc_gtk_widgets.gtk_id = \
                        GTK_WIDGET(gtk_builder_get_object(builder, #gtk_id)))
static void vdc_gtk_widgets_init(GtkBuilder *builder) {
    // TODO: make this DRYer?
    expose(screen_width);
    expose(screen_height);
    expose(da_x);
    expose(da_y);
    expose(da_width);
    expose(da_height);
}

// write to a setting
void vdc_write_setting(enum setting setting, const gchararray setting_text) {
    FILE *sysfs_param_handle = NULL;

    switch(setting) {
        case SET_ORIENTATION:
            sysfs_param_handle = fopen("/sys/module/veikk/parameters/orientation",
                                       "w");
            break;
        case SET_MAP_SCREEN:
            sysfs_param_handle = fopen("/sys/module/veikk/parameters/screen_map",
                                       "w");
            break;
        default:
            return g_print("Write to other settings not implemented yet.\n");
    }

    if(sysfs_param_handle == NULL) {
        g_print("Error: could not open file. Make sure to run as root.\n");
    } else {
        fprintf(sysfs_param_handle, "%s", setting_text);
        fclose(sysfs_param_handle);
        g_print("Setting written: %s.\n", setting_text);
    }
}

// set up window using gtkbuilder
void vdc_activate(GtkApplication *app, gpointer user_data) {
    GtkBuilder *builder;
    GtkWidget *window;

    builder = gtk_builder_new_from_resource(
                  "/com/github/jlam55555/vdc/vdcui.glade");
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);

    // initialize globally-visible widgets
    vdc_gtk_widgets_init(builder);

    g_object_unref(builder);

    gtk_widget_show(window);
    gtk_main();
}

// start gtk application
int main(int argc, char **argv) {

    GtkApplication *app;
    int status;

    vdc_settings_set_default();

    gtk_init(&argc, &argv);
    app = gtk_application_new("com.github.jlam55555.vdc",
                              G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(vdc_activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
