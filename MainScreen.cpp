#include "MainScreen.h"
#include "UIManager.h"
#include <assets/background.h>
#include <assets/absolute_freedom.h>
#include <assets/battery.h>
#include <assets/logo.h>
#include <assets/awareness_button.h>
#include <assets/awareness_button_highlight.h>
#include <assets/posture_button.h>
#include <assets/posture_button_highlight.h>
#include <assets/affirmation_button.h>
#include <assets/affirmation_button_highlight.h>
#include <assets/more_button.h>
#include <assets/more_button_highlight.h>
#include <assets/power_massage_button.h>
#include <assets/power_massage_button_highlight.h>
#include <assets/breathing_techniques_button.h>
#include <assets/breathing_techniques_button_highlight.h>

MainScreen::MainScreen(UIManager* manager) : UIScreen(manager) {}

void MainScreen::begin() {
    auto* awareness = new UIButton(40, 120, 200, 40, "Awareness", nullptr, nullptr, [this]() { manager->changeScreen(ScreenID::Awareness); });
    auto* posture = new UIButton(40, 170, 200, 40, "Posture", nullptr, nullptr, [this]() { manager->changeScreen(ScreenID::Posture); });
    auto* affirmation = new UIButton(40, 220, 200, 40, "Affirmation", nullptr, nullptr, [this]() { manager->changeScreen(ScreenID::Affirmation); });
    auto* breathing = new UIButton(40, 270, 200, 40, "Breathing", nullptr, nullptr, [this]() { manager->changeScreen(ScreenID::Breathing); });
    auto* more = new UIButton(40, 320, 200, 40, "More", nullptr, nullptr, [this]() { manager->changeScreen(ScreenID::More); });
    auto* powerMassage = new UIButton(280, 120, 200, 40, "Power Massage", nullptr, nullptr, [this]() { manager->changeScreen(ScreenID::PowerMassage); });
    auto* intuition = new UIButton(280, 170, 200, 40, "Strengthen Intuition", nullptr, nullptr, [this]() { manager->changeScreen(ScreenID::StrengthenIntuition); });
    elements = {awareness, posture, affirmation, breathing, more, powerMassage, intuition};
}

void MainScreen::draw(Arduino_Canvas* canvas) {
    canvas->draw16bitRGBBitmap(0, 0, const_cast<uint16_t*>(background), backgroundWidth, backgroundHeight);
    canvas->draw16bitRGBBitmap(0, 0, const_cast<uint16_t*>(absolute_freedom), absolute_freedomWidth, absolute_freedomHeight);
    canvas->draw16bitRGBBitmap(400, 10, const_cast<uint16_t*>(battery), batteryWidth, batteryHeight);
    canvas->draw16bitRGBBitmap(20, 20, const_cast<uint16_t*>(logo), logoWidth, logoHeight);
    for (auto* el : elements) {
        el->draw(canvas);
    }
}

bool MainScreen::handleTouch(int16_t x, int16_t y) {
    for (auto* el : elements) {
        if (el->handleTouch(x, y)) {
            return true;
        }
    }
    return false;
}

MainScreen::~MainScreen() {
    for (auto* el : elements) {
        delete el;
    }
}