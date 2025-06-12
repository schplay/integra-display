#include <Arduino.h>
#include <stdint.h>
#include <FS.h>
#include <FFat.h>
#include <Arduino_GFX_Library.h>
#include <Adafruit_FT6206.h>
#include <Adafruit_CST8XX.h>
// #include <OneButton.h>
#include "config.h"

#include "UIManager.h"               // For managing screens and transitions
#include "UIScreen.h"                // Base class for screens
#include "MainScreen.h"              // Main screen class
#include "AwarenessScreen.h"         // Awareness screen class
#include "PostureScreen.h"           // Posture screen class
#include "AffirmationScreen.h" // Affirmation screen class
#include "BreathingScreen.h" // Breathing techniques screen class
#include "MoreScreen.h"              // More screen class
#include "StrengthenIntuitionScreen.h" // Strengthen intuition screen class
#include "PowerMassageScreen.h"

uint16_t *colorWheel;
uint8_t brightness = 100;
hw_timer_t *pwmTimer = NULL;
volatile uint8_t dutyCycle = 128; // 50% duty cycle (0-255 scale)
volatile bool backlightState = false;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

Arduino_XCA9554SWSPI *expander;
Arduino_ESP32RGBPanel *rgbpanel;
Arduino_RGB_Display *gfx;
Arduino_Canvas *canvas = new Arduino_Canvas(480, 480, gfx); // Off-screen buffer
UIManager uiManager(gfx);

void IRAM_ATTR pwmISR() {
  static uint8_t counter = 0;
    portENTER_CRITICAL_ISR(&timerMux);
    backlightState = (counter < dutyCycle);
    counter = (counter + 1) % 255;
    portEXIT_CRITICAL_ISR(&timerMux);
}

Adafruit_CST8XX cst_ctp = Adafruit_CST8XX();
bool touchOK = false;        // we will check if the touchscreen exists
bool isFocalTouch = false;

// Placeholder functions for vibration control
void enableVibration() {
    // Serial.println("Vibration Enabled");
    Serial.println("start-massage");
}

void disableVibration() {
    // Serial.println("Vibration Disabled");
    Serial.println("stop-massage");
}

void playAudio() {
  Serial.println("start-audio");
}
void recordAudio() {
  Serial.println("record-audio");
}
void stopRecordingAudio() {
  Serial.println("stop-record-audio");
}
void startTreatment() {
  Serial.println("start-tens");
}
void stopTreatment() {
  Serial.println("stop-tens");
}
void increaseBrightness() {
  // Serial.println("brightness-up");
  if(brightness < 100) {
    brightness++;
  }
  dutyCycle = map(brightness, 0, 100, 0, 255);
  // dutyCycle = brightness * 2.55;
  Serial.println(brightness);
}
void decreaseBrightness() {
  // Serial.println("brightness-down");
  if(brightness > 10) {
    brightness--;
  }
  dutyCycle = map(brightness, 0, 100, 0, 255);
  // dutyCycle = brightness * 2.55;
  Serial.println(brightness);
}

void setup(void)
{  
  Serial.begin(115200);
  Serial.println("Starting setup");
  // Serial2.begin(115200);

  bool FSSetCorrectly = FFat.begin(true);
  debug("filesystem ready: ");
  debugln(FSSetCorrectly);
  
  expander = new Arduino_XCA9554SWSPI(PCA_TFT_RESET, PCA_TFT_CS, PCA_TFT_SCK, PCA_TFT_MOSI, &Wire, 0x20);
  debugln("expander init");
  rgbpanel = new Arduino_ESP32RGBPanel(
    TFT_DE, TFT_VSYNC, TFT_HSYNC, TFT_PCLK,
    TFT_R1, TFT_R2, TFT_R3, TFT_R4, TFT_R5,
    TFT_G0, TFT_G1, TFT_G2, TFT_G3, TFT_G4, TFT_G5,
    TFT_B1, TFT_B2, TFT_B3, TFT_B4, TFT_B5,
    1 /* hsync_polarity */, 50 /* hsync_front_porch */, 2 /* hsync_pulse_width */, 44 /* hsync_back_porch */,
    1 /* vsync_polarity */, 16 /* vsync_front_porch */, 2 /* vsync_pulse_width */, 18 /* vsync_back_porch */
//    ,1, 30000000
  );
  debugln("panel init");
  gfx = new Arduino_RGB_Display(
    480 /* width */, 480 /* height */, rgbpanel, 0 /* rotation */, true /* auto_flush */,
    expander, GFX_NOT_DEFINED /* RST */, TL021WVC02_init_operations, sizeof(TL021WVC02_init_operations));
  
#ifdef GFX_EXTRA_PRE_INIT
  GFX_EXTRA_PRE_INIT();
#endif
  debugln("gfx init");
  Wire.begin((int) SDA, (int) SCL);
  Wire.setClock(100000); // speed up I2C 
  
  debugln("wire init");
  if (!gfx->begin()) {
    Serial.println("gfx->begin() failed!");
  }

  Serial.println("Initialized!");

  gfx->fillScreen(BLACK);

  expander->pinMode(PCA_TFT_BACKLIGHT, OUTPUT);
  expander->digitalWrite(PCA_TFT_BACKLIGHT, HIGH);

  pwmTimer = timerBegin(PWM_FREQ); // Timer 0, prescaler 80 (1us per tick)
  if(pwmTimer) {
    timerAttachInterrupt(pwmTimer, &pwmISR);
    // timerWrite(pwmTimer, TIMER_INTERVAL_US);
    timerAlarm(pwmTimer, TIMER_INTERVAL_US, true, 0);
  } else {
    Serial.println("Failed to initialize timer!");
  }

  if (!cst_ctp.begin(&Wire, I2C_TOUCH_ADDR)) {
    Serial.print("No Touchscreen found at address 0x");
    Serial.println(I2C_TOUCH_ADDR, HEX);
    touchOK = false;
  } else {
    Serial.println("CST826 Touchscreen found");
    touchOK = true;
    isFocalTouch = false;
  }

  uiManager.setScreen(new MainScreen(&uiManager));
  if(touchOK) {
    uiManager.setTouchController(&cst_ctp);
  }
}

void loop()
{
  /*if (touchOK) {
    if (cst_ctp.touched()) {
      CST_TS_Point p = cst_ctp.getPoint(0);
      // Serial.printf("(%d, %d)\n", p.x, p.y);
      handleTouch(p.x, p.y);
    }
  }*/

  uiManager.update();
  uiManager.draw(canvas);

  if (Serial.available()) {
    String receivedData = Serial.readStringUntil('\n');
    // Serial.print("Received from mcu-peripherals: ");
    // Serial.println(receivedData);
  }

  expander->digitalWrite(PCA_TFT_BACKLIGHT, backlightState);
  delay(50);
  
}