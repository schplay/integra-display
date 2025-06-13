#include "AwarenessScreen.h"
#include "UIManager.h"
#include "UIButton.h"
#include "assets/back_button.h"

// Group IDs for AwarenessScreen
#define GROUP_AWARENESS_MAIN     0
#define GROUP_AWARENESS_BREATH   1
#define GROUP_AWARENESS_BODY     2
#define GROUP_AWARENESS_SPACE    3
#define GROUP_AWARENESS_THOUGHT  4
#define GROUP_AWARENESS_EMOTION  5
#define GROUP_AWARENESS_SOUND    6
#define GROUP_AWARENESS_VISUAL   7
#define GROUP_AWARENESS_SUMMARY  8
#define GROUP_AWARENESS_PROMPT   9
#define GROUP_AWARENESS_COMPLETE 10

void AwarenessScreen::begin() {
    elements.clear();
    buttons.clear();
    groups.clear();

    auto* back = new UIButton(20, 20, 60, 60, back_button);
    back->setCallback([this]() {
        manager.changeScreen(ScreenID::Main);
    });
    elements.push_back(back);
    buttons.push_back(back);

    // Group: AWARENESS_MAIN (Figma frame "Awareness")
    auto* title = new UILabel(40, 40, 400, 40, "Awareness");
    title->setFont("Roboto-Bold", 28);
    title->setTextColor(0xFFFF);

    auto* introText = new UILabel(40, 100, 400, 200,
        "Take a moment to settle into this experience."
        "\n\nFeel your body and notice your breath.");
    introText->setFont("Roboto-Regular", 20);
    introText->setTextColor(0xFFFF);

    groups[GROUP_AWARENESS_MAIN] = { title, introText };
    elements.push_back(title);
    elements.push_back(introText);

    // Group: AWARENESS_BREATH
    auto* breathTitle = new UILabel(40, 40, 400, 40, "Breath Awareness");
    breathTitle->setFont("Roboto-Bold", 28);
    breathTitle->setTextColor(0xFFFF);

    auto* breathText = new UILabel(40, 100, 400, 200,
        "Notice your breath without changing it."
        "\n\nWhere do you feel it most clearly?"
        "\n\nSimply observe.");
    breathText->setFont("Roboto-Regular", 20);
    breathText->setTextColor(0xFFFF);

    groups[GROUP_AWARENESS_BREATH] = { breathTitle, breathText };
    elements.push_back(breathTitle);
    elements.push_back(breathText);

    // Group: AWARENESS_BODY
    auto* bodyTitle = new UILabel(40, 40, 400, 40, "Body Awareness");
    bodyTitle->setFont("Roboto-Bold", 28);
    bodyTitle->setTextColor(0xFFFF);

    auto* bodyText = new UILabel(40, 100, 400, 200,
        "Bring attention to physical sensations in your body."
        "\n\nWhat are you feeling right now?"
        "\n\nAcknowledge without judgment.");
    bodyText->setFont("Roboto-Regular", 20);
    bodyText->setTextColor(0xFFFF);

    groups[GROUP_AWARENESS_BODY] = { bodyTitle, bodyText };
    elements.push_back(bodyTitle);
    elements.push_back(bodyText);

    // Group: AWARENESS_SPACE
    auto* spaceTitle = new UILabel(40, 40, 400, 40, "Space Awareness");
    spaceTitle->setFont("Roboto-Bold", 28);
    spaceTitle->setTextColor(0xFFFF);

    auto* spaceText = new UILabel(40, 100, 400, 200,
        "Notice the space around you."
        "\n\nHow much of it are you aware of?"
        "\n\nInclude it in your perception.");
    spaceText->setFont("Roboto-Regular", 20);
    spaceText->setTextColor(0xFFFF);

    groups[GROUP_AWARENESS_SPACE] = { spaceTitle, spaceText };
    elements.push_back(spaceTitle);
    elements.push_back(spaceText);

    // Group: AWARENESS_THOUGHT
    auto* thoughtTitle = new UILabel(40, 40, 400, 40, "Thought Awareness");
    thoughtTitle->setFont("Roboto-Bold", 28);
    thoughtTitle->setTextColor(0xFFFF);

    auto* thoughtText = new UILabel(40, 100, 400, 200,
        "Observe any thoughts that arise."
        "\n\nLet them come and go without attachment.");
    thoughtText->setFont("Roboto-Regular", 20);
    thoughtText->setTextColor(0xFFFF);

    groups[GROUP_AWARENESS_THOUGHT] = { thoughtTitle, thoughtText };
    elements.push_back(thoughtTitle);
    elements.push_back(thoughtText);

    // Group: AWARENESS_EMOTION
    auto* emotionTitle = new UILabel(40, 40, 400, 40, "Emotion Awareness");
    emotionTitle->setFont("Roboto-Bold", 28);
    emotionTitle->setTextColor(0xFFFF);

    auto* emotionText = new UILabel(40, 100, 400, 200,
        "Notice your emotional state."
        "\n\nWhere do you feel it in the body?"
        "\n\nAccept it without resistance.");
    emotionText->setFont("Roboto-Regular", 20);
    emotionText->setTextColor(0xFFFF);

    groups[GROUP_AWARENESS_EMOTION] = { emotionTitle, emotionText };
    elements.push_back(emotionTitle);
    elements.push_back(emotionText);

    // Group: AWARENESS_SOUND
    auto* soundTitle = new UILabel(40, 40, 400, 40, "Sound Awareness");
    soundTitle->setFont("Roboto-Bold", 28);
    soundTitle->setTextColor(0xFFFF);

    auto* soundText = new UILabel(40, 100, 400, 200,
        "Listen to the sounds around you."
        "\n\nDon't label them, just hear."
        "\n\nNotice silence too.");
    soundText->setFont("Roboto-Regular", 20);
    soundText->setTextColor(0xFFFF);

    groups[GROUP_AWARENESS_SOUND] = { soundTitle, soundText };
    elements.push_back(soundTitle);
    elements.push_back(soundText);

    // Group: AWARENESS_VISUAL
    auto* visualTitle = new UILabel(40, 40, 400, 40, "Visual Awareness");
    visualTitle->setFont("Roboto-Bold", 28);
    visualTitle->setTextColor(0xFFFF);

    auto* visualText = new UILabel(40, 100, 400, 200,
        "Look around slowly and take in your surroundings."
        "\n\nNotice color, light, and texture.");
    visualText->setFont("Roboto-Regular", 20);
    visualText->setTextColor(0xFFFF);

    groups[GROUP_AWARENESS_VISUAL] = { visualTitle, visualText };
    elements.push_back(visualTitle);
    elements.push_back(visualText);

    // Group: AWARENESS_SUMMARY
    auto* summaryTitle = new UILabel(40, 40, 400, 40, "Summary");
    summaryTitle->setFont("Roboto-Bold", 28);
    summaryTitle->setTextColor(0xFFFF);

    auto* summaryText = new UILabel(40, 100, 400, 200,
        "You've now explored multiple forms of awareness."
        "\n\nTake this presence into your next moments.");
    summaryText->setFont("Roboto-Regular", 20);
    summaryText->setTextColor(0xFFFF);

    groups[GROUP_AWARENESS_SUMMARY] = { summaryTitle, summaryText };
    elements.push_back(summaryTitle);
    elements.push_back(summaryText);

    // Group: AWARENESS_PROMPT
    auto* promptTitle = new UILabel(40, 40, 400, 40, "Reflection Prompt");
    promptTitle->setFont("Roboto-Bold", 28);
    promptTitle->setTextColor(0xFFFF);

    auto* promptText = new UILabel(40, 100, 400, 200,
        "What stood out most to you during this awareness exercise?\n\nTake a moment to consider.");
    promptText->setFont("Roboto-Regular", 20);
    promptText->setTextColor(0xFFFF);

    groups[GROUP_AWARENESS_PROMPT] = { promptTitle, promptText };
    elements.push_back(promptTitle);
    elements.push_back(promptText);

    // Group: AWARENESS_COMPLETE
    auto* completeTitle = new UILabel(40, 40, 400, 40, "Complete");
    completeTitle->setFont("Roboto-Bold", 28);
    completeTitle->setTextColor(0xFFFF);

    auto* completeText = new UILabel(40, 100, 400, 200,
        "Well done. Your awareness practice is complete."
        "\n\nReturn to the main menu to continue.");
    completeText->setFont("Roboto-Regular", 20);
    completeText->setTextColor(0xFFFF);

    groups[GROUP_AWARENESS_COMPLETE] = { completeTitle, completeText };
    elements.push_back(completeTitle);
    elements.push_back(completeText);

    hideAllGroups();
    showGroup(GROUP_AWARENESS_MAIN);
}

void AwarenessScreen::draw() {
    auto* canvas = manager.getCanvas();
    canvas->fillScreen(0x0000);
    for (auto* el : elements) el->draw(canvas);
    canvas->flush();
}

bool AwarenessScreen::handleTouch(int16_t tx, int16_t ty) {
    for (auto* btn : buttons) {
        if (btn->handleTouch(tx, ty)) return true;
    }
    return false;
}

void AwarenessScreen::hideAllGroups() {
    for (auto& [id, groupElems] : groups) {
        for (auto* el : groupElems) el->setVisible(false);
    }
}

void AwarenessScreen::showGroup(int groupId) {
    hideAllGroups();
    if (groups.count((GroupID)groupId)) {
        for (auto* el : groups[(GroupID)groupId]) el->setVisible(true);
    }
}
