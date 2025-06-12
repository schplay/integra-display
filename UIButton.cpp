#include "UIButton.h"

UIButton::UIButton(int x, int y, int w, int h, const char* label, std::function<void()> onClick)
    : x(x), y(y), w(w), h(h), label(label), onClick(onClick) {}

void UIButton::draw(Arduino_Canvas* canvas) {
    // Draw button background
    canvas->fillRoundRect(x, y, w, h, 8, bgColor);

    // Draw button border
    canvas->drawRoundRect(x, y, w, h, 8, borderColor);

    // Set text properties
    canvas->setTextColor(textColor);
    canvas->setTextSize(1);  // You can scale this up if needed

    // Center the label
    int16_t x1, y1;
    uint16_t centerW, centerH;
    canvas->getTextBounds(label, 0, 0, &x1, &y1, &centerW, &centerH);

    int16_t textX = x + (w - centerW) / 2;
    int16_t textY = y + (h - centerH) / 2;

    canvas->setCursor(textX, textY);
    canvas->print(label);
}

bool UIButton::handleTouch(int tx, int ty) {
    if (tx >= x && tx <= x + w && ty >= y && ty <= y + h) {
        if (onClick) onClick();  // Trigger the onClick callback when the button is pressed
        return true;
    }
    return false;
}

const char* UIButton::getLabel() const {
    return label;
}
