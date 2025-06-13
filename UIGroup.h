#pragma once

#include <vector>
#include "UIElement.h"

class UIGroup {
public:
    UIGroup(bool visible = false);

    void add(UIElement* element);
    void setVisible(bool show);
    bool isVisible() const;

    void draw(Arduino_Canvas* canvas);
    bool handleTouch(int16_t tx, int16_t ty);

private:
    std::vector<UIElement*> elements;
    bool visible;
};
