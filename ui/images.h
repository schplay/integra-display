#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_background;
extern const lv_img_dsc_t img_absolute_freedom;
extern const lv_img_dsc_t img_affirmation_button;
extern const lv_img_dsc_t img_affirmation_button_highlight;
extern const lv_img_dsc_t img_affirmation_logo;
extern const lv_img_dsc_t img_awareness_button;
extern const lv_img_dsc_t img_awareness_button_highlight;
extern const lv_img_dsc_t img_awareness_logo;
extern const lv_img_dsc_t img_back_button;
extern const lv_img_dsc_t img_battery;
extern const lv_img_dsc_t img_breathing_exit_demo;
extern const lv_img_dsc_t img_breathing_prep_1_demo;
extern const lv_img_dsc_t img_breathing_techniques_button;
extern const lv_img_dsc_t img_breathing_techniques_button_highlight;
extern const lv_img_dsc_t img_breathing_techniques_logo;
extern const lv_img_dsc_t img_brightness_icon_bright;
extern const lv_img_dsc_t img_brightness_icon_dark;
extern const lv_img_dsc_t img_button_next;
extern const lv_img_dsc_t img_button_no;
extern const lv_img_dsc_t img_button_preparation_info;
extern const lv_img_dsc_t img_button_yes;
extern const lv_img_dsc_t img_more_button;
extern const lv_img_dsc_t img_more_button_highlight;
extern const lv_img_dsc_t img_more_icon;
extern const lv_img_dsc_t img_more_logo;
extern const lv_img_dsc_t img_posture_button;
extern const lv_img_dsc_t img_posture_button_highlight;
extern const lv_img_dsc_t img_posture_logo;
extern const lv_img_dsc_t img_power_massage_button;
extern const lv_img_dsc_t img_power_massage_button_highlight;
extern const lv_img_dsc_t img_power_massage_logo;
extern const lv_img_dsc_t img_primary_button;
extern const lv_img_dsc_t img_settings_brightness_button;
extern const lv_img_dsc_t img_settings_brightness_header;
extern const lv_img_dsc_t img_settings_language_button;
extern const lv_img_dsc_t img_settings_text;
extern const lv_img_dsc_t img_slider_background;
extern const lv_img_dsc_t img_slider_background_full;
extern const lv_img_dsc_t img_slider_indicator;
extern const lv_img_dsc_t img_strengthen_intuition_button;
extern const lv_img_dsc_t img_subconscious_thoughts_button;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[41];


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/