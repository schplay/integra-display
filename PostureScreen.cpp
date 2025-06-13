#include "PostureScreen.h"
#include "UIManager.h"

// Asset includes
#include <assets/background.h>
#include <assets/back_button.h>
// #include <assets/next_button.h>

PostureScreen::PostureScreen(UIManager* manager) : UIScreen(manager), currentGroup(static_cast<int>(GroupID::POSTURE_MAIN)) {}

void PostureScreen::begin() {
    auto* title = new UILabel(40, 40, 400, 40, "Posture");
    auto* desc = new UILabel(40, 90, 600, 100, "Prepare to adjust your posture.\n\nPress start to begin.");
    auto* back = new UIButton(600, 360, 48, 48, "", back_button, back_button, [this]() { manager->navigateBack(); });
    // auto* start = new UIButton(40, 360, 120, 48, "START", next_button, next_button_h, [this]() { showGroup(static_cast<int>(GroupID::POSTURE_ADJUST)); });
    // groups[static_cast<int>(GroupID::POSTURE_MAIN)] = std::vector<UIElement*>{title, desc, back, start};
    groups[static_cast<int>(GroupID::POSTURE_MAIN)] = std::vector<UIElement*>{title, desc, back};

    auto* adjustTitle = new UILabel(40, 40, 400, 40, "Adjust Posture");
    auto* adjustText = new UILabel(40, 90, 600, 100, "Sit or stand straight.\n\nAlign your spine comfortably.");
    // auto* adjustNext = new UIButton(40, 360, 120, 48, "NEXT", next_button, next_button_h, [this]() { showGroup(static_cast<int>(GroupID::POSTURE_HOLD)); });
    // groups[static_cast<int>(GroupID::POSTURE_ADJUST)] = std::vector<UIElement*>{adjustTitle, adjustText, adjustNext};
    groups[static_cast<int>(GroupID::POSTURE_ADJUST)] = std::vector<UIElement*>{adjustTitle, adjustText};

    auto* holdTitle = new UILabel(40, 40, 400, 40, "Hold Posture");
    auto* holdText = new UILabel(40, 90, 600, 100, "Maintain your posture.\n\nBreathe deeply for 30 seconds.");
    // auto* holdNext = new UIButton(40, 360, 120, 48, "NEXT", next_button, next_button_h, [this]() { showGroup(static_cast<int>(GroupID::POSTURE_COMPLETE)); });
    // groups[static_cast<int>(GroupID::POSTURE_HOLD)] = std::vector<UIElement*>{holdTitle, holdText, holdNext};
    groups[static_cast<int>(GroupID::POSTURE_HOLD)] = std::vector<UIElement*>{holdTitle, holdText};

    auto* completeTitle = new UILabel(40, 40, 400, 40, "Complete");
    auto* completeText = new UILabel(40, 90, 600, 100, "Great job!\n\nReturn when ready.");
    // auto* finish = new UIButton(40, 360, 120, 48, "FINISH", next_button, next_button_h, [this]() { manager->navigateBack(); });
    groups[static_cast<int>(GroupID::POSTURE_COMPLETE)] = std::vector<UIElement*>{completeTitle, completeText, finish};
}

void PostureScreen::draw(Arduino_Canvas* canvas) {
    canvas->draw16bitRGBBitmap(0, 0, const_cast<uint16_t*>(background), backgroundWidth, backgroundHeight);
    for (auto* el : groups[currentGroup]) {
        el->draw(canvas);
    }
}

bool PostureScreen::handleTouch(int16_t x, int16_t y) {
    for (auto* el : groups[currentGroup]) {
        if (el->handleTouch(x, y)) {
            return true;
        }
    }
    return false;
}

void PostureScreen::showGroup(int groupId) {
    currentGroup = groupId;
}

PostureScreen::~PostureScreen() {
    for (auto& group : groups) {
        for (auto* el : group.second) {
            delete el;
        }
    }
}