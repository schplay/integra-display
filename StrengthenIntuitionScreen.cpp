#include "StrengthenIntuitionScreen.h"
#include "UIManager.h"
#include "UIButton.h"
#include "UILabel.h"
#include "assets/back_button.h"

#define GROUP_INTUITION_MAIN 0

void StrengthenIntuitionScreen::begin() {
    elements.clear();
    buttons.clear();
    groups.clear();

    auto* back = new UIButton(20, 20, 60, 60, back_button);
    back->setCallback([this]() {
        manager.changeScreen(ScreenID::Main);
    });
    elements.push_back(back);
    buttons.push_back(back);

    // Group: INTUITION_MAIN (Figma frame "Strengthen Intuition")
    auto* title = new UILabel(40, 40, 400, 40, "Strengthen Intuition");
    title->setFont("Roboto-Bold", 28);
    title->setTextColor(0xFFFF);

    auto* description = new UILabel(40, 90, 400, 100,
        "Practice listening inward and\nbuilding trust in your inner voice.");
    description->setFont("Roboto-Regular", 20);
    description->setTextColor(0xCCCC);

    groups[GROUP_INTUITION_MAIN] = { title, description };
    elements.push_back(title);
    elements.push_back(description);

    hideAllGroups();
    showGroup(GROUP_INTUITION_MAIN);
}

void StrengthenIntuitionScreen::draw() {
    auto* canvas = manager.getCanvas();
    canvas->fillScreen(0x0000);
    for (auto* el : elements) el->draw(canvas);
    canvas->flush();
}

bool StrengthenIntuitionScreen::handleTouch(int16_t tx, int16_t ty) {
    for (auto* btn : buttons) {
        if (btn->handleTouch(tx, ty)) return true;
    }
    return false;
}

void StrengthenIntuitionScreen::hideAllGroups() {
    for (auto& [id, groupElems] : groups) {
        for (auto* el : groupElems) el->setVisible(false);
    }
}

void StrengthenIntuitionScreen::showGroup(int groupId) {
    hideAllGroups();
    if (groups.count(groupId)) {
        for (auto* el : groups[groupId]) el->setVisible(true);
    }
}
