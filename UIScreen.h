#pragma once
#include <Arduino_GFX_Library.h>

class UIScreen {
public:
    virtual void begin() {}          // Called once on screen load
    virtual void draw(Arduino_Canvas* canvas) = 0;
    virtual void update() {}         // Optional per-frame logic
    virtual void handleTouch(int x, int y) {} // Touch input
    virtual ~UIScreen() {}
    static void rotateAndBlit(Arduino_Canvas* canvas, Arduino_RGB_Display* gfx, float degrees);
};
