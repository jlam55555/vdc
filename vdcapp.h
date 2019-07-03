#ifndef VEIKK_DRIVER_CONFIG_VDCAPP_H
#define VEIKK_DRIVER_CONFIG_VDCAPP_H

#define VDC_APP_TYPE vdc_app_get_type()
G_DECLARE_FINAL_TYPE(VDCApp, vdc_app, VDC, APP, GtkApplication)

VDCApp *vdc_app_new(void);

#endif //VEIKK_DRIVER_CONFIG_VEIKKCONFIGAPP_H
