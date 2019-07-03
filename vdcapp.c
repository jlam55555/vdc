#include <gtk/gtk.h>
#include "vdcapp.h"
#include "vdcappwin.h"

struct _VDCApp {
    GtkApplication parent;
};

G_DEFINE_TYPE(VDCApp, vdc_app, GTK_TYPE_APPLICATION);

static void vdc_app_init(VDCApp *app) {
    // pass
}

static void vdc_app_activate(GApplication *app) {
    VDCAppWindow *win;

    win = vdc_app_window_new(VDC_APP(app));
    gtk_window_present(GTK_WINDOW(win));
}

static void vdc_app_class_init(VDCAppClass *class) {
    G_APPLICATION_CLASS(class)->activate = vdc_app_activate;
}

VDCApp *vdc_app_new(void) {
    return g_object_new(VDC_APP_TYPE,
                        "application-id", "com.github.jlam55555.vdc",
                        "flags", G_APPLICATION_FLAGS_NONE,
                        NULL);
}