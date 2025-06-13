#ifndef UI_SCREEN_H
#define UI_SCREEN_H

#include <Arduino_GFX.h>
#include <vector>
#include <map>
#include "UIButton.h"
#include "UIElement.h"

class UIManager;

class UIScreen {
public:
    UIScreen(UIManager* uiManager) : uiManager(uiManager) {}
    virtual ~UIScreen() = default;

    virtual void begin() {}
    virtual void draw(Arduino_Canvas* canvas) = 0;
    virtual void update() {}
    virtual bool handleTouch(int x, int y);
    static void rotateAndBlit(Arduino_Canvas* canvas, Arduino_RGB_Display* gfx, float degrees);

    void hideAllGroups();
    void showGroup(int groupId);

protected:
    UIManager* uiManager;

    std::vector<UIElement*> elements;
    std::vector<UIButton*> buttons;
    std::map<int, std::vector<UIElement*>> groups;
};

#endif
