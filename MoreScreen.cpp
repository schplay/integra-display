#include "MoreScreen.h"
#include "UIManager.h"
#include "UIButton.h"
#include "UILabel.h"
#include "assets/back_button.h"

#define GROUP_MORE_MAIN 0

void MoreScreen::begin() {
    elements.clear();
    buttons.clear();
    groups.clear();

    auto* back = new UIButton(20, 20, 60, 60, back_button);
    back->setCallback([this]() {
        manager.changeScreen(ScreenID::Main);
    });
    elements.push_back(back);
    buttons.push_back(back);

    // Group: MORE_MAIN (Figma frame "More")
    auto* title = new UILabel(40, 40, 400, 40, "More");
    title->setFont("Roboto-Bold", 28);
    title->setTextColor(0xFFFF);

    auto* description = new UILabel(40, 90, 400, 100,
        "Explore additional resources and exercises\nto support your journey.");
    description->setFont("Roboto-Regular", 20);
    description->setTextColor(0xCCCC);

    groups[GROUP_MORE_MAIN] = { title, description };
    elements.push_back(title);
    elements.push_back(description);

    hideAllGroups();
    showGroup(GROUP_MORE_MAIN);
}

void MoreScreen::draw() {
    auto* canvas = manager.getCanvas();
    canvas->fillScreen(0x0000);
    for (auto* el : elements) el->draw(canvas);
    canvas->flush();
}

bool MoreScreen::handleTouch(int16_t tx, int16_t ty) {
    for (auto* btn : buttons) {
        if (btn->handleTouch(tx, ty)) return true;
    }
    return false;
}

void MoreScreen::hideAllGroups() {
    for (auto& [id, groupElems] : groups) {
        for (auto* el : groupElems) el->setVisible(false);
    }
}

void MoreScreen::showGroup(int groupId) {
    hideAllGroups();
    if (groups.count(groupId)) {
        for (auto* el : groups[groupId]) el->setVisible(true);
    }
}
