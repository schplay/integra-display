#pragma once
#include "UIScreen.h"
#include <Adafruit_CST8XX.h>

class UIManager {
public:
    UIManager(Arduino_RGB_Display* gfx);
    void drawWithRotation(Arduino_Canvas* canvas, std::function<void()> drawCallback);
    void begin();
    void setScreen(UIScreen* screen);
    void handleTouch(int x, int y);
    void update();
    void touch(int x, int y);
    void draw(Arduino_Canvas* canvas);
    void setTouchController(Adafruit_CST8XX* touch);

private:
    Arduino_RGB_Display* gfx;
    UIScreen* currentScreen = nullptr;
    Adafruit_CST8XX* touchController = nullptr;
};
