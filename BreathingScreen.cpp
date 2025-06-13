// BreathingScreen.cpp
#include "BreathingScreen.h"
#include "UIManager.h"
#include "UIButton.h"
#include "UILabel.h"
#include "assets/back_button.h"

// Group IDs
#define GROUP_BREATHING_MAIN       0
#define GROUP_BREATHING_INSTRUCTION_1 1
#define GROUP_BREATHING_INSTRUCTION_2 2
#define GROUP_BREATHING_COMPLETE   3

void BreathingScreen::begin() {
    elements.clear();
    buttons.clear();
    groups.clear();

    auto* back = new UIButton(20, 20, 60, 60, back_button);
    back->setCallback([this]() {
        manager.changeScreen(ScreenID::Main);
    });
    elements.push_back(back);
    buttons.push_back(back);

    // Group: BREATHING_MAIN (Figma frame "Breathing Techniques")
    auto* title = new UILabel(40, 40, 400, 40, "Breathing Techniques");
    title->setFont("Roboto-Bold", 28);
    title->setTextColor(0xFFFF);

    auto* subtitle = new UILabel(40, 90, 400, 30, "Focus on your breath");
    subtitle->setFont("Roboto-Regular", 22);
    subtitle->setTextColor(0xCCCC);

    groups[GROUP_BREATHING_MAIN] = { title, subtitle };
    elements.push_back(title);
    elements.push_back(subtitle);

    // Group: BREATHING_INSTRUCTION_1 (Figma frame "Breathing Techniques - 1")
    auto* instr1 = new UILabel(30, 50, 420, 200,
        "Inhale deeply through your nose.\n\nHold for a few seconds.");
    instr1->setFont("Roboto-Regular", 20);
    instr1->setTextColor(0xFFFF);

    groups[GROUP_BREATHING_INSTRUCTION_1] = { instr1 };
    elements.push_back(instr1);

    // Group: BREATHING_INSTRUCTION_2 (Figma frame "Breathing Techniques - 2")
    auto* instr2 = new UILabel(30, 50, 420, 200,
        "Exhale slowly through your mouth.\n\nRepeat for 5 minutes.");
    instr2->setFont("Roboto-Regular", 20);
    instr2->setTextColor(0xFFFF);

    groups[GROUP_BREATHING_INSTRUCTION_2] = { instr2 };
    elements.push_back(instr2);

    // Group: BREATHING_COMPLETE (Figma frame "Breathing Techniques - Complete")
    auto* done = new UILabel(30, 50, 420, 200,
        "You’ve completed the Breathing Techniques.\n\nFeel more centered.");
    done->setFont("Roboto-Regular", 20);
    done->setTextColor(0xFFFF);

    groups[GROUP_BREATHING_COMPLETE] = { done };
    elements.push_back(done);

    hideAllGroups();
    showGroup(GROUP_BREATHING_MAIN);
}

void BreathingScreen::draw() {
    auto* canvas = manager.getCanvas();
    canvas->fillScreen(0x0000);
    for (auto* el : elements) el->draw(canvas);
    canvas->flush();
}

bool BreathingScreen::handleTouch(int16_t tx, int16_t ty) {
    for (auto* btn : buttons) {
        if (btn->handleTouch(tx, ty)) return true;
    }
    return false;
}

void BreathingScreen::hideAllGroups() {
    for (auto& [id, groupElems] : groups) {
        for (auto* el : groupElems) el->setVisible(false);
    }
}

void BreathingScreen::showGroup(int groupId) {
    hideAllGroups();
    if (groups.count(groupId)) {
        for (auto* el : groups[groupId]) el->setVisible(true);
    }
}
