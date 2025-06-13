#pragma once

#include <Arduino.h>
#include <Arduino_GFX.h>
#include <functional>
#include "UIElement.h"

class UIButton : public UIElement {
public:
    UIButton(int16_t x, int16_t y, int16_t w, int16_t h,
             const uint16_t* image, const uint16_t* pressedImage = nullptr);

    void draw(Arduino_Canvas* canvas) override;
    bool handleTouch(int16_t tx, int16_t ty) override;
    void setCallback(std::function<void()> cb);

private:
    const uint16_t* image;
    const uint16_t* pressedImage;
    std::function<void()> callback;
};
