#include "AwarenessScreen.h"
#include "assets/background.h"
// #include "assets/logo_image.h"

AwarenessScreen::AwarenessScreen() {
    // Group 0: Recording UI
    addButtonToGroup(0, UIButton(50, 50, 100, 40, "RECORD", true, [this]() {
        Serial.println("Recording started");
        setGroupVisibility(0, false); // Hide RECORD
        setGroupVisibility(1, true);  // Show timer
    }));
    addButtonToGroup(0, UIButton(50, 100, 100, 40, "SAVE", true, [this]() {
        Serial.println("Recording saved");
        setGroupVisibility(1, false); // Hide timer
        setGroupVisibility(2, true);  // Show New voice
    }));

    // Group 1: Timer UI
    addButtonToGroup(1, UIButton(50, 150, 100, 40, "00:01:85", true, []() {
        Serial.println("Timer interacted");
    }));
    setGroupVisibility(1, false); // Initially hidden

    // Group 2: New Voice UI
    addButtonToGroup(2, UIButton(50, 200, 100, 40, "New voice", true, []() {
        Serial.println("New voice selected");
    }));
    setGroupVisibility(2, false); // Initially hidden
}

void AwarenessScreen::draw(TFT_eSPI& tft) {
    tft.fillScreen(TFT_BLACK);
    // Draw background image (replaces ellipses)
    rotateAndBlit(tft, 0, 0, backgroundImageWidth, backgroundImageHeight, backgroundImage);
    // Draw logo
    // rotateAndBlit(tft, 10, 10, logoImageWidth, logoImageHeight, logoImage);
    // Draw visible groups
    for (const auto& group : groups) {
        if (!group.visible) continue;
        for (const auto& button : group.buttons) {
            button.draw(tft);
        }
    }
    // Draw non-grouped buttons (for compatibility)
    for (const auto& button : buttons) {
        button.draw(tft);
    }
}

void AwarenessScreen::update() {
    // Existing update logic
}