#pragma once

#include <Arduino.h>
#include <Arduino_GFX.h>

class UIElement {
public:
    UIElement(int16_t x, int16_t y, int16_t w, int16_t h);
    virtual ~UIElement() = default;

    virtual void draw(Arduino_Canvas* canvas) = 0;
    virtual void setVisible(bool v);
    virtual bool isVisible() const;
    virtual bool contains(int16_t tx, int16_t ty) const;

protected:
    int16_t x, y, width, height;
    bool visible;
};
