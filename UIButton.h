#ifndef UIBUTTON_H
#define UIBUTTON_H

#include "UIElement.h"
#include <functional>

class UIButton : public UIElement {
public:
    UIButton(int16_t x, int16_t y, int16_t w, int16_t h, const char* label, uint16_t* normal, uint16_t* pressed, std::function<void()> onClick)
        : UIElement(x, y, w, h), label(label), normal(normal), pressed(pressed), onClick(onClick), isPressed(false) {}
    
    void draw(Arduino_Canvas* canvas) override;
    void release();

private:
    const char* label;
    uint16_t* normal;
    uint16_t* pressed;
    std::function<void()> onClick;
    bool isPressed;
};

#endif