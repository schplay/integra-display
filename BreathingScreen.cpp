#include "BreathingScreen.h"
#include "UIManager.h"

// Restore exact asset includes
#include <assets/background.h>
#include <assets/back_button.h>
// #include <assets/start_button.h>

BreathingScreen::BreathingScreen(UIManager* manager) : UIScreen(manager), currentGroup(static_cast<int>(GroupID::BREATHING_MAIN)) {}

void BreathingScreen::begin() {
    auto* title = new UILabel(40, 40, 400, 40, "Breathing");
    auto* desc = new UILabel(40, 90, 600, 100, "Prepare for a breathing exercise.\n\nPress start to begin.");
    auto* back = new UIButton(600, 360, 48, 48, "", back_button, back_button, [this]() { manager->navigateBack(); });
    // auto* start = new UIButton(40, 360, 120, 48, "START", start_button, start_button_h, [this]() { showGroup(static_cast<int>(GroupID::BREATHING_EXERCISE)); });
    // groups[static_cast<int>(GroupID::BREATHING_MAIN)] = std::vector<UIElement*>{title, desc, back, start};
    groups[static_cast<int>(GroupID::BREATHING_MAIN)] = std::vector<UIElement*>{title, desc, back};

    auto* exerciseTitle = new UILabel(40, 40, 400, 40, "Breathing Exercise");
    auto* exerciseText = new UILabel(40, 90, 600, 100, "Inhale for 4 seconds, hold for 4, exhale for 4.\n\nRepeat for 1 minute.");
    // auto* exerciseNext = new UIButton(40, 360, 120, 48, "NEXT", start_button, start_button_h, [this]() { showGroup(static_cast<int>(GroupID::BREATHING_COMPLETE)); });
    groups[static_cast<int>(GroupID::BREATHING_EXERCISE)] = std::vector<UIElement*>{exerciseTitle, exerciseText, exerciseNext};

    auto* completeTitle = new UILabel(40, 40, 400, 40, "Complete");
    auto* completeText = new UILabel(40, 90, 600, 100, "Well done!\n\nReturn when ready.");
    // auto* finish = new UIButton(40, 360, 120, 48, "FINISH", start_button, start_button_h, [this]() { manager->navigateBack(); });
    groups[static_cast<int>(GroupID::BREATHING_COMPLETE)] = std::vector<UIElement*>{completeTitle, completeText, finish};
}

void BreathingScreen::draw(Arduino_Canvas* canvas) {
    canvas->draw16bitRGBBitmap(0, 0, const_cast<uint16_t*>(background), backgroundWidth, backgroundHeight);
    for (auto* el : groups[currentGroup]) {
        el->draw(canvas);
    }
}

bool BreathingScreen::handleTouch(int16_t x, int16_t y) {
    for (auto* el : groups[currentGroup]) {
        if (el->handleTouch(x, y)) {
            return true;
        }
    }
    return false;
}

void BreathingScreen::showGroup(int groupId) {
    currentGroup = groupId;
}

BreathingScreen::~BreathingScreen() {
    for (auto& group : groups) {
        for (auto* el : group.second) {
            delete el;
        }
    }
}