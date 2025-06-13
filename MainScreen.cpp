#include "MainScreen.h"
#include "UIManager.h"

#include "assets/awareness_button.h"
#include "assets/awareness_button_highlight.h"
#include "assets/posture_button.h"
#include "assets/posture_button_highlight.h"
#include "assets/power_massage_button.h"
#include "assets/power_massage_button_highlight.h"
#include "assets/affirmation_button.h"
#include "assets/affirmation_button_highlight.h"
#include "assets/breathing_techniques_button.h"
#include "assets/breathing_techniques_button_highlight.h"
#include "assets/more_button.h"
#include "assets/more_button_highlight.h"


void MainScreen::begin() {
    elements.clear();
    buttons.clear();

    auto* btn_Awareness = new UIButton(20, 220, 80, 80,
        awareness_button, awareness_button_highlight);
    btn_Awareness->setCallback([this]() {
        manager.changeScreen(ScreenID::Awareness);
    });
    elements.push_back(btn_Awareness);
    buttons.push_back(btn_Awareness);

    auto* btn_Posture = new UIButton(120, 220, 80, 80,
        posture_button, posture_button_highlight);
    btn_Posture->setCallback([this]() {
        manager.changeScreen(ScreenID::Posture);
    });
    elements.push_back(btn_Posture);
    buttons.push_back(btn_Posture);

    auto* btn_Affirmation = new UIButton(220, 220, 80, 80,
        affirmation_button, affirmation_button_highlight);
    btn_Affirmation->setCallback([this]() {
        manager.changeScreen(ScreenID::Affirmation);
    });
    elements.push_back(btn_Affirmation);
    buttons.push_back(btn_Affirmation);

    auto* btn_Breathing = new UIButton(320, 220, 80, 80,
        breathing_button, breathing_button_highlight);
    btn_Breathing->setCallback([this]() {
        manager.changeScreen(ScreenID::Breathing);
    });
    elements.push_back(btn_Breathing);
    buttons.push_back(btn_Breathing);

    auto* btn_More = new UIButton(420, 220, 80, 80,
        more_button, more_button_highlight);
    btn_More->setCallback([this]() {
        manager.changeScreen(ScreenID::More);
    });
    elements.push_back(btn_More);
    buttons.push_back(btn_More);

    auto* btn_Massage = new UIButton(520, 220, 80, 80,
        power_massage_button, power_massage_button_highlight);
    btn_Massage->setCallback([this]() {
        manager.changeScreen(ScreenID::PowerMassage);
    });
    elements.push_back(btn_Massage);
    buttons.push_back(btn_Massage);
}

void MainScreen::draw() {
    auto* canvas = manager.getCanvas();
    canvas->fillScreen(0x0000); // Black background or your custom bg color
    for (auto* el : elements) el->draw(canvas);
    canvas->flush();
}

bool MainScreen::handleTouch(int16_t tx, int16_t ty) {
    for (auto* btn : buttons) {
        if (btn->handleTouch(tx, ty)) return true;
    }
    return false;
}
