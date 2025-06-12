#include "UIButton.h"

UIButton::UIButton(int x, int y, int width, int height, const char* label, bool centerText, std::function<void()> callback)
    : x(x), y(y), width(width), height(height), label(label), centerText(centerText), callback(callback) {}

void UIButton::draw(TFT_eSPI& tft) {
    tft.fillRect(x, y, width, height, TFT_BLUE);
    tft.setTextColor(TFT_WHITE);
    if (centerText) {
        tft.setTextDatum(MC_DATUM); // Middle center datum
        tft.drawString(label, x + width / 2, y + height / 2);
    } else {
        tft.setTextDatum(TL_DATUM); // Top left datum
        tft.drawString(label, x + 10, y + 10);
    }
}

bool UIButton::checkTouch(int xTouch, int yTouch) {
    return xTouch >= x && xTouch <= x + width && yTouch >= y && yTouch <= y + height;
}

void UIButton::executeCallback() {
    if (callback) {
        callback();
    }
}