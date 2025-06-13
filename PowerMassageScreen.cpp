#include "PowerMassageScreen.h"
#include "UIManager.h"

// Asset includes
#include <assets/background.h>
#include <assets/back_button.h>
// #include <assets/play_button.h>
// #include <assets/pause_button.h>
// #include <assets/stop_button.h>

PowerMassageScreen::PowerMassageScreen(UIManager* manager) : UIScreen(manager), currentGroup(static_cast<int>(GroupID::POWER_MASSAGE_MAIN)), currentState(STOPPED) {}

void PowerMassageScreen::begin() {
    auto* title = new UILabel(40, 40, 400, 40, "Power Massage");
    auto* desc = new UILabel(40, 90, 600, 100, "Select massage intensity and press play.\n\n(Placeholder)");
    // auto* back = new UIButton(600, 360, 48, 48, "", back_button, back_button, [this]() { manager->navigateBack(); });
    // auto* play = new UIButton(40, 360, 48, 48, "", play_button, play_button_h, [this]() { startMassage(); });
    // auto* pause = new UIButton(100, 360, 48, 48, "", pause_button, pause_button_h, [this]() { pauseMassage(); });
    // auto* stop = new UIButton(160, 360, 48, 48, "", stop_button, stop_button_h, [this]() { stopMassage(); });
    auto* intensity = new UIButton(220, 360, 120, 40, "Low", nullptr, nullptr, [this]() { setIntensity(1); });
    auto* intensity2 = new UIButton(340, 360, 120, 40, "Medium", nullptr, nullptr, [this]() { setIntensity(2); });
    auto* intensity3 = new UIButton(460, 360, 120, 40, "High", nullptr, nullptr, [this]() { setIntensity(3); });
    // groups[static_cast<int>(GroupID::POWER_MASSAGE_MAIN)] = std::vector<UIElement*>{title, desc, back, play, pause, stop, intensity, intensity2, intensity3};
    groups[static_cast<int>(GroupID::POWER_MASSAGE_MAIN)] = std::vector<UIElement*>{title, desc, back, intensity, intensity2, intensity3};
}

void PowerMassageScreen::startMassage() {
    if (currentState == STOPPED || currentState == PAUSED) {
        currentState = PLAYING;
    }
}

void PowerMassageScreen::pauseMassage() {
    if (currentState == PLAYING) {
        currentState = PAUSED;
    }
}

void PowerMassageScreen::stopMassage() {
    currentState = STOPPED;
}

void PowerMassageScreen::setIntensity(int32_t level) {
    currentLevel = level;
}

void PowerMassageScreen::draw(Arduino_Canvas* canvas) {
    canvas->draw16bitRGBBitmap(0, 0, const_cast<uint16_t*>(background), backgroundWidth, backgroundHeight);
    for (auto* el : groups[currentGroup]) {
        el->draw(canvas);
    }
}

bool PowerMassageScreen::handleTouch(int16_t x, int16_t y) {
    for (auto* el : groups[currentGroup]) {
        if (el->handleTouch(x, y)) {
            return true;
        }
    }
    return false;
}

PowerMassageScreen::~PowerMassageScreen() {
    for (auto& group : groups) {
        for (auto* el : group.second) {
            delete el;
        }
    }
}