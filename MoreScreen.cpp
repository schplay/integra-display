#include "MoreScreen.h"
#include "UILabel.h"
#include "UIButton.h"

MoreScreen::MoreScreen(UIManager* manager) : UIScreen(manager) {}

void MoreScreen::begin() {
    auto* title = new UILabel(40, 40, "More");
    auto* desc = new UILabel(40, 80, "Additional settings and information.");
    auto* back = new UIButton(600, 360, 48, 48, "", back_button, back_button, [this]() { uiManager->navigateBack(); });
    auto* info = new UILabel(40, 120, "App Version: 1.0.0");
    groups[static_cast<int>(GroupID::MORE_MAIN)] = std::vector<UIElement*>{title, desc, back, info};
}