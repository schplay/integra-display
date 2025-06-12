#pragma once
#include "UIScreen.h"
#include "UIButton.h"
#include "UIManager.h"

class StrengthenIntuitionScreen : public UIScreen {
public:
    StrengthenIntuitionScreen(UIManager* uiManager);
    void begin() override;
    void draw(Arduino_Canvas* canvas) override;
    void handleTouch(int x, int y) override;

private:
    UIManager* ui;
    std::vector<UIButton> buttons;
};
