#ifndef BREATHINGSCREEN_H
#define BREATHINGSCREEN_H

#include "UIScreen.h"
#include "UIManager.h"
#include <vector>

class BreathingScreen : public UIScreen {
public:
    BreathingScreen(UIManager& manager) : UIScreen(manager) {}
    void begin() override;
    void draw() override;
    bool handleTouch(int16_t tx, int16_t ty) override;
    
private:
    void hideAllGroups();
    void showGroup(int groupId);

    std::vector<UIElement*> elements;
    std::vector<UIButton*> buttons;
    std::map<int, std::vector<UIElement*>> groups;
};

#endif // BREATHINGSCREEN_H
