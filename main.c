#include <gtk/gtk.h>
#include "vdcapp.h"

int main(int argc, char **argv) {
    return g_application_run(G_APPLICATION(vdc_app_new()), argc, argv);
}