#include "UIManager.h"
extern float screenRotation;

UIManager::UIManager(Arduino_RGB_Display* gfx) : gfx(gfx), currentScreen(nullptr) {}

void UIManager::drawWithRotation(Arduino_Canvas* canvas, std::function<void()> drawCallback) {
    // Rotate the canvas content before drawing
    canvas->fillScreen(WHITE);  // Optionally clear the screen
    drawCallback();
    UIScreen::rotateAndBlit(canvas, gfx, screenRotation);  // Apply rotation based on global variable
}

void UIManager::begin() {
    // Initialize screen or other setup code here if needed
}

void UIManager::setScreen(UIScreen* screen) {
    currentScreen = screen;
    currentScreen->begin();  // Call begin() of the new screen
}

void UIManager::handleTouch(int x, int y) {
    if (currentScreen) {
        currentScreen->handleTouch(x, y);  // Pass touch input to current screen
    }
}

void UIManager::update() {
    if (touchController && touchController->touched()) {
        CST_TS_Point p = touchController->getPoint(0);
        touch(p.x, p.y);
    }
}

void UIManager::touch(int x, int y) {
    if (currentScreen) {
        currentScreen->handleTouch(x, y);  // Handle touch input for the current screen
    }
}

void UIManager::draw(Arduino_Canvas* canvas) {
    if (currentScreen) {
        drawWithRotation(canvas, [this, canvas] {
            // Delegate to the current screen's draw function
            currentScreen->draw(canvas);
        });
    }
}

void UIManager::setTouchController(Adafruit_CST8XX* touch) {
    touchController = touch;
    if (!touchController) {
        Serial.println("Warning: setTouchController called with nullptr");
    }
}
