#include "MoreScreen.h"
#include "MainScreen.h"
#include <FS.h>
#include <FFat.h>

// #include "assets/more_background.h"

MoreScreen::MoreScreen(UIManager* uiManager) : ui(uiManager) {}

void MoreScreen::begin() {
    // Initialize buttons or other UI elements for this screen
    
}

void MoreScreen::draw(Arduino_Canvas* canvas) {
    canvas->fillScreen(BLACK);

    // Draw the background for the More screen
    // canvas->draw16bitRGBBitmap(0, 0, more_background, 480, 480);
    File file = FFat.open("/assets/background.rgb565", "r");
    if (!file) {
        Serial.println("Failed to open background.rgb565");
        return;
    }

    const int width = 480;
    const int height = 480;
    uint8_t buffer[480 * 2]; // 480 pixels * 2 bytes (1 row)

    for (int y = 0; y < height; y++) {
        file.read(buffer, sizeof(buffer));
        canvas->draw16bitRGBBitmap(0, y, (uint16_t*)buffer, width, 1);
    }

    file.close();

    // Draw any additional UI elements like buttons, text, etc.
    for (auto& button : buttons) {
        button.draw(canvas);
    }
}

void MoreScreen::handleTouch(int x, int y) {
    for (auto& button : buttons) {
        if (button.handleTouch(x, y)) {
            // Handle the button press and navigate back to the Main screen
            if (button.getLabel() == "Back") {
                ui->setScreen(new MainScreen(ui));  // Transition back to Main screen
            }
        }
    }
}

