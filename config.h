// Design Info
String HARDWARE_VER = "0.1";
String SOFTWARE_VER = "0.1";

// UI Buttons
#define BUTTON_TASK_PRIORITY (2)  // Task Priority
#define BUTTON_UP 5
#define BUTTON_DOWN 6
// OneButton button_up = OneButton(
//   BUTTON_UP,  // Input pin for the button
//   true,        // Button is active LOW
//   false         // Enable internal pull-up resistor
// );
// OneButton button_down = OneButton(
//   BUTTON_DOWN,  // Input pin for the button
//   true,        // Button is active LOW
//   false
// );

// Enum for screen state management
// enum ScreenState { MAIN_MENU, MASSAGE_MENU, AUDIO_MENU, TENS_MENU, DISPLAY_MENU };
// ScreenState currentScreen = MAIN_MENU;

// Struct for buttons
// struct Button {
//     int x, y, width, height;
//     String label;
// };

// EEPROM
#define EEPROM_SIZE 128
#define EEPROM_HORIZONTAL 1
#define EEPROM_VOLUME 2
#define EEPROM_BRIGHTNESS 5
#define EEPROM_CONFIG 6
#define EEPROM_DISPLAYTEXT 10

// LCD
#define TFT_DE  2
#define TFT_VSYNC 42
#define TFT_HSYNC 41
#define TFT_PCLK  1
#define TFT_R1  11
#define TFT_R2  10
#define TFT_R3  9
#define TFT_R4  46
#define TFT_R5  3
#define TFT_G0  48
#define TFT_G1  47
#define TFT_G2  21
#define TFT_G3  14
#define TFT_G4  13
#define TFT_G5  12
#define TFT_B1  40
#define TFT_B2  39
#define TFT_B3  38
#define TFT_B4  0
#define TFT_B5  45

float screenRotation = 3.0f;
// uint16_t* framebuffer = (uint16_t*)ps_malloc(width * height * sizeof(uint16_t));

// I2C
#define SDA 8
#define SCL 18
#define I2C_MASTER_PORT ((i2c_port_t)0)
#define I2C_MASTER_SCL_IO (18)        /*!< GPIO number used for I2C master clock */
#define I2C_MASTER_SDA_IO (8)         /*!< GPIO number used for I2C master data  */
#define I2C_MASTER_FREQ_HZ (100000)   /*!< I2C master clock frequency */
#define I2C_MASTER_TIMEOUT_MS (1000)  /*!< I2C timeout in milliseconds */
#define I2C_MASTER_TX_BUF_DISABLE (0) /*!< I2C master doesn't need buffer */
#define I2C_MASTER_RX_BUF_DISABLE (0) /*!< I2C master doesn't need buffer */
#define I2C_TOUCH_ADDR 0x15

// Expander
#define PCA9554_ADDR (0x3F)
#define PCA9554_INPUT_PORT_REG (0x00)
#define PCA9554_OUTPUT_PORT_REG (0x01)
#define PCA9554_INVERSION_PORT_REG (0x02)
#define PCA9554_CONFIG_PORT_REG (0x03)

#define PCA_BUTTON_UP (5)
#define PCA_BUTTON_DOWN (6)

#define PCA_TFT_BACKLIGHT (4)
#define PCA_TFT_RESET 2
#define PCA_TFT_CS  1
#define PCA_TFT_SCK 0
#define PCA_TFT_MOSI  7

// UART
#define UART_NUM 2  // Using UART2

// Backlight
#define PWM_FREQ (16000)     // PWM frequency in Hz
// #define TIMER_PRESCALER 240
#define TIMER_INTERVAL_US (1000000 / PWM_FREQ)

// ETC
uint64_t lastTime = millis();
uint64_t currentTime = millis();
#define DEMO 0
#define DEBUG 1

#if DEBUG == 1
#define debug(x) Serial.print(x)
#define debugln(x) Serial.println(x)
#else
#define debug(x)
#define debugln(x)
#endif






