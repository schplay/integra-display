#pragma once

#include "UIScreen.h"
#include <vector>
#include <map>

class PostureScreen : public UIScreen {
public:
    void begin() override;
    void draw() override;
    bool handleTouch(int16_t tx, int16_t ty) override;

    void hideAllGroups();
    void showGroup(int groupId);

private:
    std::vector<UIElement*> elements;
    std::vector<UIButton*> buttons;
    std::map<int, std::vector<UIElement*>> groups;
};
