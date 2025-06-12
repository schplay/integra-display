#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *affirmation;
    lv_obj_t *awareness;
    lv_obj_t *breathing;
    lv_obj_t *more;
    lv_obj_t *posture;
    lv_obj_t *power_massage;
    lv_obj_t *strengthen_intuition;
    lv_obj_t *affirmation_button;
    lv_obj_t *awareness_button;
    lv_obj_t *breathing_button;
    lv_obj_t *more_button;
    lv_obj_t *posture_button;
    lv_obj_t *massage_button;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_AFFIRMATION = 2,
    SCREEN_ID_AWARENESS = 3,
    SCREEN_ID_BREATHING = 4,
    SCREEN_ID_MORE = 5,
    SCREEN_ID_POSTURE = 6,
    SCREEN_ID_POWER_MASSAGE = 7,
    SCREEN_ID_STRENGTHEN_INTUITION = 8,
};

void create_screen_main();
void tick_screen_main();

void create_screen_affirmation();
void tick_screen_affirmation();

void create_screen_awareness();
void tick_screen_awareness();

void create_screen_breathing();
void tick_screen_breathing();

void create_screen_more();
void tick_screen_more();

void create_screen_posture();
void tick_screen_posture();

void create_screen_power_massage();
void tick_screen_power_massage();

void create_screen_strengthen_intuition();
void tick_screen_strengthen_intuition();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/