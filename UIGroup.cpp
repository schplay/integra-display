#include "UIGroup.h"

UIGroup::UIGroup(bool visible) : visible(visible) {}

void UIGroup::add(UIElement* element) {
    elements.push_back(element);
}

void UIGroup::setVisible(bool show) {
    visible = show;
}

bool UIGroup::isVisible() const {
    return visible;
}

void UIGroup::draw(Arduino_Canvas* canvas) {
    if (!visible) return;
    for (auto* e : elements) e->draw(canvas);
}

bool UIGroup::handleTouch(int16_t tx, int16_t ty) {
    if (!visible) return false;
    for (auto* e : elements) {
        if (e->handleTouch(tx, ty)) return true;
    }
    return false;
}
