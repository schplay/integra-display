#include "AffirmationScreen.h"
#include "UIManager.h"

// Restore exact asset includes
#include <assets/background.h>
#include <assets/back_button.h>
#include <assets/affirmation_logo.h>

AffirmationScreen::AffirmationScreen(UIManager* manager) : UIScreen(manager), currentGroup(static_cast<int>(GroupID::AFFIRMATION_MAIN)) {}

void AffirmationScreen::begin() {
    // Restore main group
    auto* title = new UILabel(40, 200, 400, 40, "Affirmation");
    auto* desc = new UILabel(40, 250, 600, 100, "Reflect on your affirmation.\n\n\n(Placeholder)");
    auto* back = new UIButton(600, 360, 48, 48, "", back_button, back_button, [this]() { manager->navigateBack(); });
    auto* next = new UIButton(40, 360, 120, 48, "NEXT", back_button, back_button, [this]() { showGroup(static_cast<int>(GroupID::AFFIRMATION_SECOND)); });
    groups[static_cast<int>(GroupID::AFFIRMATION_MAIN)] = std::vector<UIElement*>{title, desc, back, next};

    // Restore second group (inferred from pattern)
    auto* secondTitle = new UILabel(40, 200, 400, 40, "Affirmation Complete");
    auto* secondDesc = new UILabel(40, 250, 600, 100, "Great job reflecting!\n\nReturn when ready.");
    auto* secondBack = new UIButton(600, 360, 48, 48, "", back_button, back_button, [this]() { manager->navigateBack(); });
    groups[static_cast<int>(GroupID::AFFIRMATION_SECOND)] = std::vector<UIElement*>{secondTitle, secondDesc, secondBack};
}

void AffirmationScreen::draw(Arduino_Canvas* canvas) {
    canvas->draw16bitRGBBitmap(0, 0, const_cast<uint16_t*>(background), backgroundWidth, backgroundHeight);
    canvas->draw16bitRGBBitmap(20, 20, const_cast<uint16_t*>(affirmation_logo), affirmation_logoWidth, affirmation_logoHeight);
    for (auto* el : groups[currentGroup]) {
        el->draw(canvas);
    }
}

bool AffirmationScreen::handleTouch(int16_t x, int16_t y) {
    for (auto* el : groups[currentGroup]) {
        if (el->handleTouch(x, y)) {
            return true;
        }
    }
    return false;
}

void AffirmationScreen::showGroup(int groupId) {
    currentGroup = groupId;
}

AffirmationScreen::~AffirmationScreen() {
    for (auto& group : groups) {
        for (auto* el : group.second) {
            delete el;
        }
    }
}