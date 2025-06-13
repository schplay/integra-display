#ifndef AFFIRMATIONSCREEN_H
#define AFFIRMATIONSCREEN_H

#include "UIScreen.h"
#include "UIManager.h"
#include <vector>

class AffirmationScreen : public UIScreen {
public:
    AffirmationScreen(UIManager& manager) : UIScreen(manager) {}
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

#endif // AFFIRMATIONSCREEN_H
