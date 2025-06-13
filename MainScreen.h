#pragma once
#include "UIScreen.h"

class MainScreen : public UIScreen {
public:
    void begin() override;
    void draw() override;
    bool handleTouch(int16_t tx, int16_t ty) override;

private:
    std::vector<UIElement*> elements;
    std::vector<UIButton*> buttons;
};
