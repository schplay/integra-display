#ifndef PostureScreen_h
#define PostureScreen_h

#include "UIScreen.h"
#include "UILabel.h"
#include "UIButton.h"
#include "GroupID.h"
#include <vector>
#include <map>

class PostureScreen : public UIScreen {
public:
    PostureScreen(UIManager* manager);
    ~PostureScreen() override;
    void begin() override;
    void draw(Arduino_Canvas* canvas) override;
    bool handleTouch(int16_t x, int16_t y) override;
private:
    std::map<int, std::vector<UIElement*>> groups;
    int currentGroup;
    void showGroup(int groupId);
};

#endif