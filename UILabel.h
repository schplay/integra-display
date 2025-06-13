#pragma once
#include "UIElement.h"
#include <Arduino_GFX_Library.h>

class UILabel : public UIElement {
public:
    UILabel(int16_t x, int16_t y, int16_t w, int16_t h, const char* text);

    void setFont(const char* fontName, uint8_t fontSize);
    void setTextColor(uint16_t color);
    void draw(Arduino_Canvas* canvas) override;
    void setVisible(bool visible) override;

private:
    const char* text;
    const char* fontName;
    uint8_t fontSize;
    uint16_t textColor;
    bool visible;
};
