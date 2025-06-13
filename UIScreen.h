#ifndef UI_SCREEN_H
#define UI_SCREEN_H

#include <Arduino_GFX_Library.h>
#include "UIElement.h"
#include <vector>
#include <map>

class UIManager;

class UIScreen {
public:
    UIScreen(UIManager* uiManager);
    virtual ~UIScreen();
    virtual void begin() {}
    virtual void draw(Arduino_Canvas* canvas) = 0;
    virtual bool handleTouch(int16_t tx, int16_t ty);
    static void rotateAndBlit(Arduino_Canvas* canvas, Arduino_RGB_Display* gfx, float degrees);

protected:
    UIManager* uiManager;
    std::map<int, std::vector<UIElement*>> groups;
};

#endif