#include <gtk/gtk.h>
#include "vdcapp.h"
#include "vdcappwin.h"

struct _VDCAppWindow {
    GtkApplicationWindow parent;
};

G_DEFINE_TYPE(VDCAppWindow, vdc_app_window, GTK_TYPE_APPLICATION_WINDOW);

static void vdc_app_window_init(VDCAppWindow *app) {
    // pass
}

static void vdc_app_window_class_init(VDCAppWindowClass *class) {
    // pass
}

VDCAppWindow *vdc_app_window_new(VDCApp *app) {
    return g_object_new(VDC_APP_WINDOW_TYPE, "application", app, NULL);
}
