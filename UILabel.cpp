#include "UILabel.h"
#include <Arduino_GFX_Library.h>

UILabel::UILabel(int16_t x, int16_t y, int16_t w, int16_t h, const char* text, uint16_t color, uint8_t size)
    : UIElement(x, y, w, h), text(text), textColor(color), textSize(size) {}

void UILabel::draw(Arduino_Canvas* canvas) {
    if (!isVisible()) return;
    canvas->setTextColor(textColor);
    canvas->setTextSize(textSize);
    canvas->setCursor(x, y);
    canvas->print(text.c_str());
}

void UILabel::setText(const char* text) {
    this->text = text;
}

void UILabel::setTextColor(uint16_t color) {
    textColor = color;
}

void UILabel::setTextSize(uint8_t size) {
    textSize = size;
}

std::string UILabel::getText() const {
    return text;
}