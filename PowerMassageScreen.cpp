#include "PowerMassageScreen.h"
#include "UIManager.h"
#include "UIButton.h"
#include "UILabel.h"
#include "assets/back_button.h"

// Group IDs for PowerMassageScreen
#define GROUP_MASSAGE_MAIN     0
#define GROUP_MASSAGE_SOFTEN   1
#define GROUP_MASSAGE_DIRECT   2
#define GROUP_MASSAGE_DEEPEN   3
#define GROUP_MASSAGE_EXPLORE  4
#define GROUP_MASSAGE_COMPLETE 5

void PowerMassageScreen::begin() {
    elements.clear();
    buttons.clear();
    groups.clear();

    auto* back = new UIButton(20, 20, 60, 60, back_button);
    back->setCallback([this]() {
        manager.changeScreen(ScreenID::Main);
    });
    elements.push_back(back);
    buttons.push_back(back);

    // Group: MASSAGE_MAIN
    auto* title = new UILabel(40, 40, 400, 40, "Power Massage");
    title->setFont("Roboto-Bold", 28);
    title->setTextColor(0xFFFF);

    auto* desc = new UILabel(40, 100, 400, 200,
        "Begin your power massage practice."
        "\n\nFeel free to adjust position as needed."
        "\n\nPress next to continue.");
    desc->setFont("Roboto-Regular", 20);
    desc->setTextColor(0xFFFF);

    groups[GROUP_MASSAGE_MAIN] = { title, desc };
    elements.push_back(title);
    elements.push_back(desc);

    // Group: MASSAGE_SOFTEN
    auto* softenTitle = new UILabel(40, 40, 400, 40, "Soften");
    softenTitle->setFont("Roboto-Bold", 28);
    softenTitle->setTextColor(0xFFFF);

    auto* softenText = new UILabel(40, 100, 400, 200,
        "Let yourself soften around tension."
        "\n\nFeel the area without forcing change.");
    softenText->setFont("Roboto-Regular", 20);
    softenText->setTextColor(0xFFFF);

    groups[GROUP_MASSAGE_SOFTEN] = { softenTitle, softenText };
    elements.push_back(softenTitle);
    elements.push_back(softenText);

    // Group: MASSAGE_DIRECT
    auto* directTitle = new UILabel(40, 40, 400, 40, "Direct Pressure");
    directTitle->setFont("Roboto-Bold", 28);
    directTitle->setTextColor(0xFFFF);

    auto* directText = new UILabel(40, 100, 400, 200,
        "Apply firm pressure to the area."
        "\n\nBreathe slowly as you do this."
        "\n\nMaintain awareness.");
    directText->setFont("Roboto-Regular", 20);
    directText->setTextColor(0xFFFF);

    groups[GROUP_MASSAGE_DIRECT] = { directTitle, directText };
    elements.push_back(directTitle);
    elements.push_back(directText);

    // Group: MASSAGE_DEEPEN
    auto* deepenTitle = new UILabel(40, 40, 400, 40, "Deepen");
    deepenTitle->setFont("Roboto-Bold", 28);
    deepenTitle->setTextColor(0xFFFF);

    auto* deepenText = new UILabel(40, 100, 400, 200,
        "Sink deeper into the massage."
        "\n\nNotice any changes in sensation."
        "\n\nStay connected.");
    deepenText->setFont("Roboto-Regular", 20);
    deepenText->setTextColor(0xFFFF);

    groups[GROUP_MASSAGE_DEEPEN] = { deepenTitle, deepenText };
    elements.push_back(deepenTitle);
    elements.push_back(deepenText);

    // Group: MASSAGE_EXPLORE
    auto* exploreTitle = new UILabel(40, 40, 400, 40, "Explore");
    exploreTitle->setFont("Roboto-Bold", 28);
    exploreTitle->setTextColor(0xFFFF);

    auto* exploreText = new UILabel(40, 100, 400, 200,
        "Move your attention around the area."
        "\n\nWhere else do you feel connected sensations?"
        "\n\nTake your time.");
    exploreText->setFont("Roboto-Regular", 20);
    exploreText->setTextColor(0xFFFF);

    groups[GROUP_MASSAGE_EXPLORE] = { exploreTitle, exploreText };
    elements.push_back(exploreTitle);
    elements.push_back(exploreText);

    // Group: MASSAGE_COMPLETE
    auto* completeTitle = new UILabel(40, 40, 400, 40, "Complete");
    completeTitle->setFont("Roboto-Bold", 28);
    completeTitle->setTextColor(0xFFFF);

    auto* completeText = new UILabel(40, 100, 400, 200,
        "Your massage session is complete."
        "\n\nNotice how you feel now."
        "\n\nReturn when you're ready.");
    completeText->setFont("Roboto-Regular", 20);
    completeText->setTextColor(0xFFFF);

    groups[GROUP_MASSAGE_COMPLETE] = { completeTitle, completeText };
    elements.push_back(completeTitle);
    elements.push_back(completeText);

    hideAllGroups();
    showGroup(GROUP_MASSAGE_MAIN);
}

void PowerMassageScreen::draw() {
    auto* canvas = manager.getCanvas();
    canvas->fillScreen(0x0000);
    for (auto* el : elements) el->draw(canvas);
    canvas->flush();
}

bool PowerMassageScreen::handleTouch(int16_t tx, int16_t ty) {
    for (auto* btn : buttons) {
        if (btn->handleTouch(tx, ty)) return true;
    }
    return false;
}

void PowerMassageScreen::hideAllGroups() {
    for (auto& [id, groupElems] : groups) {
        for (auto* el : groupElems) el->setVisible(false);
    }
}

void PowerMassageScreen::showGroup(int groupId) {
    hideAllGroups();
    if (groups.count((GroupID)groupId)) {
        for (auto* el : groups[(GroupID)groupId]) el->setVisible(true);
    }
}
