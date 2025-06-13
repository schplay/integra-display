#include "UIElement.h"

UIElement::UIElement(int16_t x, int16_t y, int16_t w, int16_t h)
    : x(x), y(y), w(w), h(h), visible(true) {}

void UIElement::setVisible(bool v) {
    visible = v;
}

bool UIElement::isVisible() const {
    return visible;
}

bool UIElement::contains(int16_t tx, int16_t ty) const {
    return (tx >= x && tx < x + w && ty >= y && ty < y + h);
}