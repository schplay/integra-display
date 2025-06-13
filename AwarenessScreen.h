#pragma once
#include "UIScreen.h"
#include <map>

class AwarenessScreen : public UIScreen {
public:
    void begin() override;
    void draw() override;
    bool handleTouch(int16_t tx, int16_t ty) override;

private:
    std::vector<UIElement*> elements;
    std::vector<UIButton*> buttons;

    void showGroup(int groupId);
    void hideAllGroups();


    std::map<GroupID, std::vector<UIElement*>> groups;
};
