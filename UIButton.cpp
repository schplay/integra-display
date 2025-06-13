#include "UIButton.h"

UIButton::UIButton(int16_t x, int16_t y, int16_t w, int16_t h,
                   const uint16_t* image, const uint16_t* pressedImage)
    : UIElement(x, y, w, h), image(image), pressedImage(pressedImage) {}

void UIButton::draw(Arduino_Canvas* canvas) {
    if (image) {
        canvas->draw16bitRGBBitmap(x, y, image, w, h);
    }
}

bool UIButton::handleTouch(int16_t tx, int16_t ty) {
    if (contains(tx, ty)) {
        if (pressedImage) {
            canvas->draw16bitRGBBitmap(x, y, pressedImage, w, h);
            canvas->flush();
            delay(100);  // brief press feedback
        }
        if (callback) callback();
        return true;
    }
    return false;
}

void UIButton::setCallback(std::function<void()> cb) {
    callback = std::move(cb);
}
