#include "UILabel.h"
#include <Arduino_GFX_Library.h>

UILabel::UILabel(int16_t x, int16_t y, int16_t w, int16_t h, const char* t)
    : UIElement(x, y, w, h), text(t), fontName(nullptr), fontSize(1), textColor(0xFFFF), visible(true) {}

void UILabel::setFont(const char* f, uint8_t size) {
    fontName = f;
    fontSize = size;
}

void UILabel::setTextColor(uint16_t color) {
    textColor = color;
}

void UILabel::draw(Arduino_Canvas* canvas) {
    if (!visible) return;

    canvas->setTextColor(textColor);
    canvas->setTextSize(fontSize);
    canvas->setCursor(x, y + (fontSize * 8));  // Adjust as needed
    canvas->print(text);
}

void UILabel::setVisible(bool v) {
    visible = v;
}
