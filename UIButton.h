#pragma once
#include <functional>
#include <Arduino_GFX_Library.h>

class UIButton {
public:
    UIButton(int x, int y, int w, int h, const char* label, std::function<void()> onClick);

    void draw(Arduino_Canvas* canvas);  // Method to draw the button
    bool handleTouch(int tx, int ty);     // Method to handle touch events
    const char* getLabel() const;         // Method to get the button's label
    void setColors(uint16_t bg, uint16_t border, uint16_t text) {
        bgColor = bg;
        borderColor = border;
        textColor = text;
    }

private:
    int x, y, w, h;                      // Button position and size
    const char* label;                   // Button label (text)
    std::function<void()> onClick;       // Callback when button is pressed
    uint16_t bgColor = 0xFFFF;     // Default white background
    uint16_t borderColor = 0x0000; // Default black border
    uint16_t textColor = 0x0000;   // Default black text
};
