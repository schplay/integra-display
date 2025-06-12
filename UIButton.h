#ifndef UIBUTTON_H
#define UIBUTTON_H

#include <TFT_eSPI.h>
#include <functional>

class UIButton {
public:
    UIButton(int x, int y, int width, int height, const char* label, bool centerText, std::function<void()> callback);
    void draw(TFT_eSPI& tft);
    bool checkTouch(int x, int y);
    void executeCallback();

private:
    int x, y, width, height;
    const char* label;
    bool centerText;
    std::function<void()> callback;
};

#endif