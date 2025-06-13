#include "PostureScreen.h"
#include "UIManager.h"
#include "UIButton.h"
#include "UILabel.h"
#include "assets/back_button.h"

// Group IDs
#define GROUP_POSTURE_MAIN       0
#define GROUP_POSTURE_PREP       1
#define GROUP_POSTURE_ALIGN      2
#define GROUP_POSTURE_HOLD       3
#define GROUP_POSTURE_COMPLETE   4

void PostureScreen::begin() {
    elements.clear();
    buttons.clear();
    groups.clear();

    auto* back = new UIButton(20, 20, 60, 60, back_button);
    back->setCallback([this]() {
        manager.changeScreen(ScreenID::Main);
    });
    elements.push_back(back);
    buttons.push_back(back);

    // Group: POSTURE_MAIN
    auto* title = new UILabel(40, 40, 400, 40, "Posture");
    title->setFont("Roboto-Bold", 28);
    title->setTextColor(0xFFFF);

    auto* intro = new UILabel(40, 100, 400, 200,
        "This activity helps correct your sitting posture.\n\nPress next to begin.");
    intro->setFont("Roboto-Regular", 20);
    intro->setTextColor(0xFFFF);

    groups[GROUP_POSTURE_MAIN] = { title, intro };
    elements.push_back(title);
    elements.push_back(intro);

    // Group: POSTURE_PREP
    auto* prepTitle = new UILabel(40, 40, 400, 40, "Get Ready");
    prepTitle->setFont("Roboto-Bold", 28);
    prepTitle->setTextColor(0xFFFF);

    auto* prepText = new UILabel(40, 100, 400, 200,
        "Sit in a comfortable position.\n\nTake a deep breath.");
    prepText->setFont("Roboto-Regular", 20);
    prepText->setTextColor(0xFFFF);

    groups[GROUP_POSTURE_PREP] = { prepTitle, prepText };
    elements.push_back(prepTitle);
    elements.push_back(prepText);

    // Group: POSTURE_ALIGN
    auto* alignTitle = new UILabel(40, 40, 400, 40, "Align");
    alignTitle->setFont("Roboto-Bold", 28);
    alignTitle->setTextColor(0xFFFF);

    auto* alignText = new UILabel(40, 100, 400, 200,
        "Straighten your spine.\nAlign your shoulders above your hips.");
    alignText->setFont("Roboto-Regular", 20);
    alignText->setTextColor(0xFFFF);

    groups[GROUP_POSTURE_ALIGN] = { alignTitle, alignText };
    elements.push_back(alignTitle);
    elements.push_back(alignText);

    // Group: POSTURE_HOLD
    auto* holdTitle = new UILabel(40, 40, 400, 40, "Hold");
    holdTitle->setFont("Roboto-Bold", 28);
    holdTitle->setTextColor(0xFFFF);

    auto* holdText = new UILabel(40, 100, 400, 200,
        "Hold this position.\nBreathe slowly and evenly.");
    holdText->setFont("Roboto-Regular", 20);
    holdText->setTextColor(0xFFFF);

    groups[GROUP_POSTURE_HOLD] = { holdTitle, holdText };
    elements.push_back(holdTitle);
    elements.push_back(holdText);

    // Group: POSTURE_COMPLETE
    auto* doneTitle = new UILabel(40, 40, 400, 40, "Complete");
    doneTitle->setFont("Roboto-Bold", 28);
    doneTitle->setTextColor(0xFFFF);

    auto* doneText = new UILabel(40, 100, 400, 200,
        "Well done.\nRemember this posture throughout your day.");
    doneText->setFont("Roboto-Regular", 20);
    doneText->setTextColor(0xFFFF);

    groups[GROUP_POSTURE_COMPLETE] = { doneTitle, doneText };
    elements.push_back(doneTitle);
    elements.push_back(doneText);

    hideAllGroups();
    showGroup(GROUP_POSTURE_MAIN);
}

void PostureScreen::draw() {
    auto* canvas = manager.getCanvas();
    canvas->fillScreen(0x0000);
    for (auto* el : elements) el->draw(canvas);
    canvas->flush();
}

bool PostureScreen::handleTouch(int16_t tx, int16_t ty) {
    for (auto* btn : buttons) {
        if (btn->handleTouch(tx, ty)) return true;
    }
    return false;
}

void PostureScreen::hideAllGroups() {
    for (auto& [id, groupElems] : groups) {
        for (auto* el : groupElems) el->setVisible(false);
    }
}

void PostureScreen::showGroup(int groupId) {
    hideAllGroups();
    if (groups.count(groupId)) {
        for (auto* el : groups[groupId]) el->setVisible(true);
    }
}
