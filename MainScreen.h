#ifndef MAIN_SCREEN_H
#define MAIN_SCREEN_H

#include "UIScreen.h"
#include "UIButton.h"

class MainScreen : public UIScreen {
public:
    MainScreen(UIManager* manager);
    void begin() override;
    void draw(Arduino_Canvas* canvas) override;
    bool handleTouch(int16_t tx, int16_t ty) override;

private:
    std::vector<UIElement*> elements;
};

#endif