#include "StrengthenIntuitionScreen.h"
#include "UIManager.h"

// Asset includes
#include <assets/background.h>
#include <assets/back_button.h>

StrengthenIntuitionScreen::StrengthenIntuitionScreen(UIManager* manager) : UIScreen(manager), currentGroup(static_cast<int>(GroupID::INTUITION_MAIN)) {}

void StrengthenIntuitionScreen::begin() {
    auto* title = new UILabel(40, 40, 400, 40, "Strengthen Intuition");
    auto* desc = new UILabel(40, 90, 600, 100, "Focus on your inner guidance.\n\n(Placeholder)");
    auto* back = new UIButton(600, 360, 48, 48, "", back_button, back_button, [this]() { manager->navigateBack(); });
    auto* next = new UIButton(40, 360, 120, 48, "NEXT", back_button, back_button, [this]() { showGroup(static_cast<int>(GroupID::INTUITION_SECOND)); });
    groups[static_cast<int>(GroupID::INTUITION_MAIN)] = std::vector<UIElement*>{title, desc, back, next};

    auto* secondTitle = new UILabel(40, 40, 400, 40, "Intuition Complete");
    auto* secondDesc = new UILabel(40, 90, 600, 100, "Well done!\n\nReturn when ready.");
    auto* secondBack = new UIButton(600, 360, 48, 48, "", back_button, back_button, [this]() { manager->navigateBack(); });
    groups[static_cast<int>(GroupID::INTUITION_SECOND)] = std::vector<UIElement*>{secondTitle, secondDesc, secondBack};
}

void StrengthenIntuitionScreen::draw(Arduino_Canvas* canvas) {
    canvas->draw16bitRGBBitmap(0, 0, const_cast<uint16_t*>(background), backgroundWidth, backgroundHeight);
    for (auto* el : groups[currentGroup]) {
        el->draw(canvas);
    }
}

bool StrengthenIntuitionScreen::handleTouch(int16_t x, int16_t y) {
    for (auto* el : groups[currentGroup]) {
        if (el->handleTouch(x, y)) {
            return true;
        }
    }
    return false;
}

void StrengthenIntuitionScreen::showGroup(int groupId) {
    currentGroup = groupId;
}

StrengthenIntuitionScreen::~StrengthenIntuitionScreen() {
    for (auto& group : groups) {
        for (auto* el : group.second) {
            delete el;
        }
    }
}