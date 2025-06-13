#ifndef UI_LABEL_H
#define UI_LABEL_H

#include "UIElement.h"
#include <string>

class UILabel : public UIElement {
public:
    UILabel(int16_t x, int16_t y, int16_t w, int16_t h, const char* text, uint16_t color = 0xFFFF, uint8_t size = 1);
    void draw(Arduino_Canvas* canvas) override;
    void setText(const char* text);
    void setTextColor(uint16_t color);
    void setTextSize(uint8_t size);
    std::string getText() const;

private:
    std::string text;
    uint16_t textColor;
    uint8_t textSize;
};

#endif