#ifndef VEIKK_DRIVER_CONFIG_VDCAPP_H
#define VEIKK_DRIVER_CONFIG_VDCAPP_H

enum setting {
    SET_ORIENTATION,
    SET_MAP_SCREEN,
    SET_MAP_PRESSURE
};
enum orientation {
    ORI_DEFAULT,
    ORI_ROT_RIGHT,
    ORI_REVERSED,
    ORI_ROT_LEFT,
};

// store all settings in a global struct
struct vdc_settings {
    // orientation
    enum orientation orientation;

    // screen mapping
    GdkRectangle rect;
    GdkRectangle screen;
};
extern struct vdc_settings vdc_settings;
void vdc_settings_set_default(void);
void vdc_write_setting(enum setting, const gchararray);

// make gtk widgets available
struct vdc_gtk_widgets {
    GtkWidget *screen_width, *screen_height,
              *da_x, *da_y, *da_width, *da_height;
};
extern struct vdc_gtk_widgets vdc_gtk_widgets;

// for screen area selection
struct select_data {
    GdkRectangle rect;
    GdkRectangle screen;
    gboolean started;
    GtkWidget *window;
};
void select_area(struct select_data *);

#endif //VEIKK_DRIVER_CONFIG_VDCAPP_H
