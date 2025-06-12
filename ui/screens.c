#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

void create_screen_main() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_background);
        }
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 47, 12);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_absolute_freedom);
            lv_image_set_scale(obj, 128);
        }
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 167, 32);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        }
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 224, 61);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_battery);
        }
        {
            // affirmationButton
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.affirmation_button = obj;
            lv_obj_set_pos(obj, 300, 329);
            lv_obj_set_size(obj, 100, 117);
            lv_obj_set_style_bg_image_src(obj, &img_affirmation_button, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_affirmation_button_highlight, LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            // awarenessButton
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.awareness_button = obj;
            lv_obj_set_pos(obj, 313, 70);
            lv_obj_set_size(obj, 100, 117);
            lv_obj_set_style_bg_image_src(obj, &img_awareness_button, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_awareness_button_highlight, LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            // breathingButton
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.breathing_button = obj;
            lv_obj_set_pos(obj, 17, 196);
            lv_obj_set_size(obj, 100, 117);
            lv_obj_set_style_bg_image_src(obj, &img_breathing_techniques_button, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_breathing_techniques_button_highlight, LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            // moreButton
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.more_button = obj;
            lv_obj_set_pos(obj, 67, 70);
            lv_obj_set_size(obj, 100, 117);
            lv_obj_set_style_bg_image_src(obj, &img_more_button, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_more_button_highlight, LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            // postureButton
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.posture_button = obj;
            lv_obj_set_pos(obj, 350, 196);
            lv_obj_set_size(obj, 100, 117);
            lv_obj_set_style_bg_image_src(obj, &img_posture_button, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_posture_button_highlight, LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            // massageButton
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.massage_button = obj;
            lv_obj_set_pos(obj, 97, 329);
            lv_obj_set_size(obj, 100, 117);
            lv_obj_set_style_bg_image_src(obj, &img_power_massage_button, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_power_massage_button_highlight, LV_PART_MAIN | LV_STATE_PRESSED);
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
}

void create_screen_affirmation() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.affirmation = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_background);
        }
    }
    
    tick_screen_affirmation();
}

void tick_screen_affirmation() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
}

void create_screen_awareness() {
    void *flowState = getFlowState(0, 2);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.awareness = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_background);
        }
    }
    
    tick_screen_awareness();
}

void tick_screen_awareness() {
    void *flowState = getFlowState(0, 2);
    (void)flowState;
}

void create_screen_breathing() {
    void *flowState = getFlowState(0, 3);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.breathing = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_background);
        }
    }
    
    tick_screen_breathing();
}

void tick_screen_breathing() {
    void *flowState = getFlowState(0, 3);
    (void)flowState;
}

void create_screen_more() {
    void *flowState = getFlowState(0, 4);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.more = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_background);
        }
    }
    
    tick_screen_more();
}

void tick_screen_more() {
    void *flowState = getFlowState(0, 4);
    (void)flowState;
}

void create_screen_posture() {
    void *flowState = getFlowState(0, 5);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.posture = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_background);
        }
    }
    
    tick_screen_posture();
}

void tick_screen_posture() {
    void *flowState = getFlowState(0, 5);
    (void)flowState;
}

void create_screen_power_massage() {
    void *flowState = getFlowState(0, 6);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.power_massage = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_background);
        }
    }
    
    tick_screen_power_massage();
}

void tick_screen_power_massage() {
    void *flowState = getFlowState(0, 6);
    (void)flowState;
}

void create_screen_strengthen_intuition() {
    void *flowState = getFlowState(0, 7);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.strengthen_intuition = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_background);
        }
    }
    
    tick_screen_strengthen_intuition();
}

void tick_screen_strengthen_intuition() {
    void *flowState = getFlowState(0, 7);
    (void)flowState;
}


static const char *screen_names[] = { "Main", "Affirmation", "Awareness", "Breathing", "More", "Posture", "PowerMassage", "StrengthenIntuition" };
static const char *object_names[] = { "main", "affirmation", "awareness", "breathing", "more", "posture", "power_massage", "strengthen_intuition", "affirmation_button", "awareness_button", "breathing_button", "more_button", "posture_button", "massage_button" };


typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_affirmation,
    tick_screen_awareness,
    tick_screen_breathing,
    tick_screen_more,
    tick_screen_posture,
    tick_screen_power_massage,
    tick_screen_strengthen_intuition,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    eez_flow_init_screen_names(screen_names, sizeof(screen_names) / sizeof(const char *));
    eez_flow_init_object_names(object_names, sizeof(object_names) / sizeof(const char *));
    
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_affirmation();
    create_screen_awareness();
    create_screen_breathing();
    create_screen_more();
    create_screen_posture();
    create_screen_power_massage();
    create_screen_strengthen_intuition();
}
