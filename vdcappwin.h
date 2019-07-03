#ifndef VEIKK_DRIVER_CONFIG_VDCAPPWIN_H
#define VEIKK_DRIVER_CONFIG_VDCAPPWIN_H

#define VDC_APP_WINDOW_TYPE vdc_app_window_get_type()
G_DECLARE_FINAL_TYPE(VDCAppWindow, vdc_app_window, VDC, APP_WINDOW, GtkApplicationWindow)

VDCAppWindow *vdc_app_window_new(VDCApp *app);

#endif //VEIKK_DRIVER_CONFIG_VDCAPPWIN_H
