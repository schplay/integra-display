#ifndef AwarenessScreen_h
#define AwarenessScreen_h

#include "UIScreen.h"
#include "UILabel.h"
#include "UIButton.h"
#include "GroupID.h"
#include <vector>
#include <map>

class AwarenessScreen : public UIScreen {
public:
    AwarenessScreen(UIManager* manager);
    ~AwarenessScreen() override;
    void begin() override;
    void draw(Arduino_Canvas* canvas) override;
    bool handleTouch(int16_t x, int16_t y) override;
private:
    std::map<int, std::vector<UIElement*>> groups;
    int currentGroup;
    bool isRecording;
    unsigned long recordingStartTime;
    unsigned long recordingDuration;
    float recordingProgress;
    void startRecording();
    void stopRecording();
    void updateTimer();
};

#endif