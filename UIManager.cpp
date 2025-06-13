#include "UIManager.h"
#include "MainScreen.h"
#include "AwarenessScreen.h"
#include "PostureScreen.h"
#include "AffirmationScreen.h"
#include "BreathingScreen.h"
#include "MoreScreen.h"
#include "PowerMassageScreen.h"
#include "StrengthenIntuitionScreen.h"

UIManager::UIManager(Arduino_RGB_Display* gfx) : currentScreen(nullptr), gfx(gfx), canvas(nullptr) {}

UIManager::~UIManager() {
    delete currentScreen;
    delete canvas;
}

void UIManager::drawWithRotation(Arduino_Canvas* canvas, std::function<void()> drawCallback) {
    drawCallback();
    UIScreen::rotateAndBlit(canvas, gfx, 0); // Adjust degrees as needed
}

void UIManager::setScreen(UIScreen* screen) {
    delete currentScreen;
    currentScreen = screen;
    if (currentScreen) currentScreen->begin();
}

void UIManager::changeScreen(ScreenID id) {
    switch (id) {
        case ScreenID::Main: setScreen(new MainScreen(this)); break;
        case ScreenID::Awareness: setScreen(new AwarenessScreen(this)); break;
        case ScreenID::Posture: setScreen(new PostureScreen(this)); break;
        case ScreenID::Affirmation: setScreen(new AffirmationScreen(this)); break;
        case ScreenID::Breathing: setScreen(new BreathingScreen(this)); break;
        case ScreenID::More: setScreen(new MoreScreen(this)); break;
        case ScreenID::PowerMassage: setScreen(new PowerMassageScreen(this)); break;
        case ScreenID::StrengthenIntuition: setScreen(new StrengthenIntuitionScreen(this)); break;
    }
}

void UIManager::draw(Arduino_Canvas* canvas) {
    if (currentScreen) currentScreen->draw(canvas);
}

bool UIManager::handleTouch(int16_t x, int16_t y) {
    return currentScreen && currentScreen->handleTouch(x, y);
}