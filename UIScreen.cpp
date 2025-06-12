#include "UIScreen.h"
#include <math.h>

void UIScreen::handleTouch(int x, int y) {
    for (auto& group : groups) {
        if (!group.visible) continue;
        for (auto& button : group.buttons) {
            if (button.checkTouch(x, y)) {
                button.executeCallback();
            }
        }
    }
    for (auto& button : buttons) {
        if (button.checkTouch(x, y)) {
            button.executeCallback();
        }
    }
}

void UIScreen::addButtonToGroup(int groupId, UIButton button) {
    if (groupId >= groups.size()) {
        groups.resize(groupId + 1, {std::vector<UIButton>(), true});
    }
    groups[groupId].buttons.push_back(button);
}

void UIScreen::setGroupVisibility(int groupId, bool visible) {
    if (groupId < groups.size()) {
        groups[groupId].visible = visible;
    }
}

void UIScreen::rotateAndBlit(Arduino_Canvas* canvas, Arduino_RGB_Display* gfx, float degrees) {
    // Only rotate if needed
    if (degrees == 0.0f) {
        gfx->draw16bitRGBBitmap(0, 0, (uint16_t*)canvas->getFramebuffer(), canvas->width(), canvas->height());
        return;
    }

    const int canvasW = canvas->width();
    const int canvasH = canvas->height();
    const int centerX = canvasW / 2;
    const int centerY = canvasH / 2;

    float radians = degrees * (M_PI / 180.0f);
    float cosA = cos(radians);
    float sinA = sin(radians);

    uint16_t* src = (uint16_t*)canvas->getFramebuffer();

    for (int16_t y = 0; y < canvasH; y++) {
        for (int16_t x = 0; x < canvasW; x++) {
            // Apply reverse rotation to find source pixel
            int dx = x - centerX;
            int dy = y - centerY;
            int srcX = round(cosA * dx + sinA * dy) + centerX;
            int srcY = round(-sinA * dx + cosA * dy) + centerY;

            // Only blit if the source pixel is within bounds
            if (srcX >= 0 && srcX < canvasW && srcY >= 0 && srcY < canvasH) {
                uint16_t color = src[srcY * canvasW + srcX];
                gfx->drawPixel(x, y, color);
            }
        }
    }
}
