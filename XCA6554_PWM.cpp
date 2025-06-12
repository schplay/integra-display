#include <Arduino_GFX_Library.h>

class XCA9554_PWM : public Arduino_XCA9554SWSPI {
public:
    XCA9554_PWM(int8_t rst, int8_t cs, int8_t sck, int8_t mosi, TwoWire *wire = &Wire, uint8_t i2c_addr = XCA9554_IIC_i2c_addr) 
        : Arduino_XCA9554SWSPI(rst, cs, sck, mosi, wire, i2c_addr) {}

    void begin() {
        Arduino_XCA9554SWSPI::begin();
    }

    void analogWrite(uint8_t pin, uint8_t dutyCycle) {
        // Map duty cycle (0-255) to percentage
        int onTime = map(dutyCycle, 0, 255, 0, 100);
        int offTime = 100 - onTime;

        for (int i = 0; i < 100; i++) {
            if (i < onTime) {
                digitalWrite(pin, HIGH);
            } else {
                digitalWrite(pin, LOW);
            }
            delayMicroseconds(100);  // Adjust this for frequency control
        }
    }
};