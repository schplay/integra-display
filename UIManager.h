#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <Arduino_GFX_Library.h>
#include "UIScreen.h"
#include <functional>

enum class ScreenID {
    Main,
    Awareness,
    Posture,
    Affirmation,
    Breathing,
    More,
    PowerMassage,
    StrengthenIntuition
};

class UIManager {
public:
    UIManager(Arduino_RGB_Display* gfx);
    ~UIManager();
    void drawWithRotation(Arduino_Canvas* canvas, std::function<void()> drawCallback);
    void setScreen(UIScreen* screen);
    void changeScreen(ScreenID id);
    Arduino_Canvas* getCanvas() const { return canvas; }
    void setCanvas(Arduino_Canvas* canvas) { this->canvas = canvas; }
    void draw(Arduino_Canvas* canvas);
    bool handleTouch(int16_t x, int16_t y);

private:
    UIScreen* currentScreen;
    Arduino_RGB_Display* gfx;
    Arduino_Canvas* canvas;
};

#endif