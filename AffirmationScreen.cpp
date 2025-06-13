// AffirmationScreen.cpp
#include "AffirmationScreen.h"
#include "UIManager.h"
#include "UIButton.h"
#include "UILabel.h"
#include "assets/back_button.h"

// Group IDs
#define GROUP_AFFIRMATION_MAIN       0
#define GROUP_AFFIRMATION_INSTRUCTION_1 1
#define GROUP_AFFIRMATION_COMPLETE   2

void AffirmationScreen::begin() {
    elements.clear();
    buttons.clear();
    groups.clear();

    auto* back = new UIButton(20, 20, 60, 60, back_button);
    back->setCallback([this]() {
        manager.changeScreen(ScreenID::Main);
    });
    elements.push_back(back);
    buttons.push_back(back);

    // Group: AFFIRMATION_MAIN (Figma frame "Affirmation")
    auto* title = new UILabel(40, 40, 400, 40, "Affirmation");
    title->setFont("Roboto-Bold", 28);
    title->setTextColor(0xFFFF);

    auto* subtitle = new UILabel(40, 90, 400, 30, "Positive Affirmations");
    subtitle->setFont("Roboto-Regular", 22);
    subtitle->setTextColor(0xCCCC);

    groups[GROUP_AFFIRMATION_MAIN] = { title, subtitle };
    elements.push_back(title);
    elements.push_back(subtitle);

    // Group: AFFIRMATION_INSTRUCTION_1 (Figma frame "Affirmation - 1")
    auto* instr1 = new UILabel(30, 50, 420, 200,
        "I am confident and strong.\n\nI trust my decisions.");
    instr1->setFont("Roboto-Regular", 20);
    instr1->setTextColor(0xFFFF);

    groups[GROUP_AFFIRMATION_INSTRUCTION_1] = { instr1 };
    elements.push_back(instr1);

    // Group: AFFIRMATION_COMPLETE (Figma frame "Affirmation - Complete")
    auto* done = new UILabel(30, 50, 420, 200,
        "You’ve completed the Affirmation.\n\nFeel empowered.");
    done->setFont("Roboto-Regular", 20);
    done->setTextColor(0xFFFF);

    groups[GROUP_AFFIRMATION_COMPLETE] = { done };
    elements.push_back(done);

    hideAllGroups();
    showGroup(GROUP_AFFIRMATION_MAIN);
}

void AffirmationScreen::draw() {
    auto* canvas = manager.getCanvas();
    canvas->fillScreen(0x0000);
    for (auto* el : elements) el->draw(canvas);
    canvas->flush();
}

bool AffirmationScreen::handleTouch(int16_t tx, int16_t ty) {
    for (auto* btn : buttons) {
        if (btn->handleTouch(tx, ty)) return true;
    }
    return false;
}

void AffirmationScreen::hideAllGroups() {
    for (auto& [id, groupElems] : groups) {
        for (auto* el : groupElems) el->setVisible(false);
    }
}

void AffirmationScreen::showGroup(int groupId) {
    hideAllGroups();
    if (groups.count(groupId)) {
        for (auto* el : groups[groupId]) el->setVisible(true);
    }
}
