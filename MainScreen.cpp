#include "MainScreen.h"
#include <FS.h>
#include <FFat.h>
#include "AffirmationScreen.h"
#include "AwarenessScreen.h"
#include "BreathingScreen.h"
#include "MoreScreen.h"
#include "PostureScreen.h"
#include "PowerMassageScreen.h"
#include "StrengthenIntuitionScreen.h"

// #include "assets/main_background.h"
// #include "assets/icon_awareness.h"
// #include "assets/icon_massage.h"
// #include "assets/icon_posture.h"
// #include "assets/icon_affirmation.h"
// #include "assets/icon_breathing.h"
// #include "assets/icon_more.h"
// #include "assets/icon_intuition.h"

// Constructor
MainScreen::MainScreen(UIManager* uiManager) : ui(uiManager) {}

void MainScreen::begin() {
    createButtons();
}

// Create buttons based on the positions and sizes of the icons
void MainScreen::createButtons() {
    // Awareness button
    buttons.push_back(UIButton(30, 100, 64, 64, "Awareness", []() {
      // Placeholder — actual behavior can go here or be routed through UIManager
    }));
    // Massage button
    buttons.push_back(UIButton(120, 100, 64, 64, "Massage", []() {
      // Placeholder — actual behavior can go here or be routed through UIManager
    }));
    // Posture button
    buttons.push_back(UIButton(210, 100, 64, 64, "Posture", []() {
      // Placeholder — actual behavior can go here or be routed through UIManager
    }));
    // Affirmation button
    buttons.push_back(UIButton(300, 100, 64, 64, "Affirmation", []() {
      // Placeholder — actual behavior can go here or be routed through UIManager
    }));
    // Breathing button
    buttons.push_back(UIButton(390, 100, 64, 64, "Breathing", []() {
      // Placeholder — actual behavior can go here or be routed through UIManager
    }));
    // More button
    buttons.push_back(UIButton(150, 200, 64, 64, "More", []() {
      // Placeholder — actual behavior can go here or be routed through UIManager
    }));
    // Intuition button
    buttons.push_back(UIButton(260, 200, 64, 64, "Intuition", []() {
      // Placeholder — actual behavior can go here or be routed through UIManager
    }));
}

void MainScreen::draw(Arduino_Canvas* canvas) {
    canvas->fillScreen(BLACK);

    // Draw background
    // canvas->draw16bitRGBBitmap(0, 0, main_background, 480, 480);
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

    // Draw icons (buttons)
    // canvas->drawRGBBitmap(30, 100, icon_awareness, 64, 64);
    // canvas->drawRGBBitmap(120, 100, icon_massage, 64, 64);
    // canvas->drawRGBBitmap(210, 100, icon_posture, 64, 64);
    // canvas->drawRGBBitmap(300, 100, icon_affirmation, 64, 64);
    // canvas->drawRGBBitmap(390, 100, icon_breathing, 64, 64);
    // canvas->drawRGBBitmap(150, 200, icon_more, 64, 64);
    // canvas->drawRGBBitmap(260, 200, icon_intuition, 64, 64);

    // Draw labels for buttons
    canvas->setTextColor(WHITE);
    canvas->setTextSize(1);
    canvas->setCursor(30, 170); canvas->print("Awareness");
    canvas->setCursor(120, 170); canvas->print("Massage");
    canvas->setCursor(210, 170); canvas->print("Posture");
    canvas->setCursor(300, 170); canvas->print("Affirmation");
    canvas->setCursor(390, 170); canvas->print("Breathing");
    canvas->setCursor(150, 270); canvas->print("More");
    canvas->setCursor(260, 270); canvas->print("Intuition");

    // Optionally, draw the buttons themselves to indicate press area
    // for (auto& button : buttons) {
    //     button.draw(gfx);
    // }
}

void MainScreen::handleTouch(int x, int y) {
    for (auto& button : buttons) {
        if (button.handleTouch(x, y)) {
            // Handle the button press and navigate to the appropriate screen based on button label
            if (button.getLabel() == "Awareness") {
                ui->setScreen(new AwarenessScreen(ui));  // Transition to Awareness screen
            }
            else if (button.getLabel() == "Power Massage") {
                ui->setScreen(new PowerMassageScreen(ui));  // Transition to Power Massage screen
            }
            else if (button.getLabel() == "Posture") {
                ui->setScreen(new PostureScreen(ui));  // Transition to Posture screen
            }
            else if (button.getLabel() == "Affirmation of Intention") {
                ui->setScreen(new AffirmationScreen(ui));  // Transition to Affirmation screen
            }
            else if (button.getLabel() == "Breathing Techniques") {
                ui->setScreen(new BreathingScreen(ui));  // Transition to Breathing Techniques screen
            }
            else if (button.getLabel() == "More") {
                ui->setScreen(new MoreScreen(ui));  // Transition to More screen
            }
            else if (button.getLabel() == "Strengthen Intuition") {
                ui->setScreen(new StrengthenIntuitionScreen(ui));  // Transition to Strengthen Intuition screen
            }
        }
    }
}

