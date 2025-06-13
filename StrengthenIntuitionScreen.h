#ifndef StrengthenIntuitionScreen_h
#define StrengthenIntuitionScreen_h

#include "UIScreen.h"
#include "UILabel.h"
#include "UIButton.h"
#include "GroupID.h"
#include <vector>
#include <map>

class StrengthenIntuitionScreen : public UIScreen {
public:
    StrengthenIntuitionScreen(UIManager* manager);
    ~StrengthenIntuitionScreen() override;
    void begin() override;
    void draw(Arduino_Canvas* canvas) override;
    bool handleTouch(int16_t x, int16_t y) override;
private:
    std::map<int, std::vector<UIElement*>> groups;
    int currentGroup;
};

#endif