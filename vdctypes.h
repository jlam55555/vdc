#ifndef VEIKK_DRIVER_CONFIG_VDCTYPES_H
#define VEIKK_DRIVER_CONFIG_VDCTYPES_H

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

// for screen area selection
struct select_data {
    GdkRectangle rect;
    gboolean started;
    GtkWidget *window;
};
void select_area(struct select_data *);

#endif //VEIKK_DRIVER_CONFIG_VDCTYPES_H
