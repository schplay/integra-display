#include "UIButton.h"

void UIButton::draw(Arduino_Canvas* canvas) {
    UIElement::draw(canvas);
    canvas->setTextSize(1);
    canvas->setTextColor(0xFFFF);
    if (label && strlen(label) > 0) {
        canvas->setCursor(x + 5, y + 5);
        canvas->print(label);
    }
    if (normal && pressed && isPressed) {
        canvas->drawRGBBitmap(x, y, pressed, w, h);
    } else if (normal) {
        canvas->drawRGBBitmap(x, y, normal, w, h);
    }
}

void UIButton::release() {
    isPressed = false;
    if (onClick) {
        onClick();
    }
}