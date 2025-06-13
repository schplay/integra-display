#include "AwarenessScreen.h"
#include "UIManager.h"

// Asset includes
#include <assets/background.h>
#include <assets/back_button.h>
// #include <assets/record_button.h>

AwarenessScreen::AwarenessScreen(UIManager* manager)
    : UIScreen(manager), currentGroup(static_cast<int>(GroupID::AWARENESS_RECORD)),
      isRecording(false), recordingStartTime(0), recordingDuration(0), recordingProgress(0.0f) {}

void AwarenessScreen::begin() {
    auto* recordTitle = new UILabel(40, 40, 400, 40, "Record");
    auto* recordText = new UILabel(40, 90, 600, 100, "Record your thoughts.\n\nPress record to begin.");
    auto* recordBack = new UIButton(600, 360, 48, 48, "", back_button, back_button, [this]() {
        manager->navigateBack();
    });
    // auto* recordButton = new UIButton(40, 360, 120, 48, isRecording ? "STOP" : "RECORD", record_button, record_button_h, [this]() {
    //     if (!isRecording) {
    //         startRecording();
    //     } else {
    //         stopRecording();
    //     }
    // });
    // groups[static_cast<int>(GroupID::AWARENESS_RECORD)] = std::vector<UIElement*>{recordTitle, recordText, recordBack, recordButton};
    groups[static_cast<int>(GroupID::AWARENESS_RECORD)] = std::vector<UIElement*>{recordTitle, recordText, recordBack};
}

void AwarenessScreen::startRecording() {
    isRecording = true;
    recordingStartTime = millis();
    recordingDuration = 0;
    recordingProgress = 0.0f;
}

void AwarenessScreen::stopRecording() {
    isRecording = false;
    recordingDuration = (millis() - recordingStartTime) / 1000; // Convert to seconds
    recordingProgress = 0.0f;
}

void AwarenessScreen::updateTimer() {
    if (isRecording) {
        recordingDuration = (millis() - recordingStartTime) / 1000; // Convert to seconds
        recordingProgress = min(recordingDuration / 60.0f, 1.0f); // 60 seconds max
    }
}

void AwarenessScreen::draw(Arduino_Canvas* canvas) {
    updateTimer();
    canvas->draw16bitRGBBitmap(0, 0, const_cast<uint16_t*>(background), backgroundWidth, backgroundHeight);
    if (currentGroup == static_cast<int>(GroupID::AWARENESS_RECORD) && isRecording) {
        int barX = 40, barY = 320, barWidth = 600, barHeight = 8;
        canvas->drawRect(barX - 2, barY - 2, barWidth + 4, barHeight + 4, 0xFFFF); // White border
        canvas->fillRect(barX, barY, static_cast<int>(barWidth * recordingProgress), barHeight, 0x07E0); // Green progress
        char durationStr[10];
        snprintf(durationStr, sizeof(durationStr), "%02ld:%02ld", recordingDuration / 60, recordingDuration % 60);
        canvas->setTextColor(0xFFFF);
        canvas->setCursor(barX + barWidth + 10, barY - 2);
        canvas->print(durationStr);
    }
    for (auto* el : groups[currentGroup]) {
        el->draw(canvas);
    }
}

bool AwarenessScreen::handleTouch(int16_t x, int16_t y) {
    for (auto* el : groups[currentGroup]) {
        if (el->handleTouch(x, y)) {
            return true;
        }
    }
    return false;
}

AwarenessScreen::~AwarenessScreen() {
    for (auto& group : groups) {
        for (auto* el : group.second) {
            delete el;
        }
    }
}