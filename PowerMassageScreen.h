#pragma once
#include "UIScreen.h"
#include "UIButton.h"
#include "UIManager.h"

class PowerMassageScreen : public UIScreen {
public:
    PowerMassageScreen(UIManager* uiManager);
    void begin() override;
    void draw(Arduino_Canvas* canvas) override;
    void handleTouch(int x, int y) override;

private:
    UIManager* ui;
    std::vector<UIButton> buttons;
};
