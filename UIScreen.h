#ifndef UISCREEN_H
#define UISCREEN_H

#include <TFT_eSPI.h>
#include <vector>
#include "UIButton.h"

struct ElementGroup {
    std::vector<UIButton> buttons;
    bool visible;
    // Add other elements (e.g., text, images) as needed
};

class UIScreen {
public:
    virtual void draw(TFT_eSPI& tft) = 0;
    virtual void handleTouch(int x, int y);
    virtual void update();
    void addButtonToGroup(int groupId, UIButton button);
    void setGroupVisibility(int groupId, bool visible);
    void rotateAndBlit(TFT_eSPI& tft, int x, int y, int width, int height, uint16_t* buffer);

protected:
    std::vector<UIButton> buttons;
    std::vector<ElementGroup> groups;
};

#endif