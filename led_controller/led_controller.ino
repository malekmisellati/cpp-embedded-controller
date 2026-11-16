
// ==========================================
// C++ Embedded LED Controller
// ==========================================

// LED pin assignments
const int WHITE_LED = 2;
const int YELLOW_LED = 3;
const int GREEN_LED = 4;
const int RED_LED = 5;
const int BLUE_LED = 6;

// Button pin
const int BUTTON_PIN = 7;

// LED pin array
const int ledPins[] = {
    RED_LED,
    WHITE_LED,
    GREEN_LED,
    YELLOW_LED,
    BLUE_LED
};

const int LED_COUNT = 5;

// ==========================================
// LED Controller Class
// ==========================================

class LedController {

private:

    int currentMode = 0;
    int currentStep = 0;

    bool blinkState = false;

    unsigned long previousTime = 0;

    void allOff() {

        for (int i = 0; i < LED_COUNT; i++) {
            digitalWrite(ledPins[i], LOW);
        }
    }

public:

    void begin() {

        for (int i = 0; i < LED_COUNT; i++) {
            pinMode(ledPins[i], OUTPUT);
        }

        allOff();
    }

    void setMode(int newMode, unsigned long currentTime) {

        currentMode = newMode;

        currentStep = 0;

        blinkState = false;

        previousTime = currentTime;

        allOff();
    }

    void update(unsigned long currentTime) {

        unsigned long interval;

        // Select timing based on operating mode
        if (currentMode == 0) {
            interval = 250;
        }
        else {
            interval = 500;
        }

        // Check whether enough time has passed
        if (currentTime - previousTime < interval) {
            return;
        }

        previousTime = currentTime;

        // MODE 1: LED chase
        if (currentMode == 0) {

            allOff();

            digitalWrite(ledPins[currentStep], HIGH);

            currentStep++;

            if (currentStep >= LED_COUNT) {
                currentStep = 0;
            }
        }

        // MODE 2: All LEDs blink
        else if (currentMode == 1) {

            blinkState = !blinkState;

            for (int i = 0; i < LED_COUNT; i++) {

                digitalWrite(
                    ledPins[i],
                    blinkState ? HIGH : LOW
                );
            }
        }

        // MODE 3: Alternating LEDs
        else if (currentMode == 2) {

            blinkState = !blinkState;

            for (int i = 0; i < LED_COUNT; i++) {

                if ((i % 2 == 0) == blinkState) {
                    digitalWrite(ledPins[i], HIGH);
                }
                else {
                    digitalWrite(ledPins[i], LOW);
                }
            }
        }
    }
};

// ==========================================
// Button and Controller Setup
// ==========================================

LedController controller;

int selectedMode = 0;

int lastButtonReading = HIGH;
int buttonState = HIGH;

unsigned long lastDebounceTime = 0;

const unsigned long DEBOUNCE_DELAY = 50;

// ==========================================
// Arduino Setup
// ==========================================

void setup() {

    Serial.begin(9600);

    pinMode(BUTTON_PIN, INPUT_PULLUP);

    controller.begin();

    controller.setMode(selectedMode, millis());

    Serial.println("LED Controller Started");
    Serial.println("Mode 1: LED Chase");
}

// ==========================================
// Arduino Main Loop
// ==========================================

void loop() {

    unsigned long currentTime = millis();

    // Read button
    int buttonReading = digitalRead(BUTTON_PIN);

    // Detect changes in button signal
    if (buttonReading != lastButtonReading) {

        lastDebounceTime = currentTime;
    }

    // Debounce the button
    if (currentTime - lastDebounceTime > DEBOUNCE_DELAY) {

        if (buttonReading != buttonState) {

            buttonState = buttonReading;

            // Button pressed
            if (buttonState == LOW) {

                selectedMode++;

                if (selectedMode >= 3) {
                    selectedMode = 0;
                }

                controller.setMode(selectedMode, currentTime);

                Serial.print("Operating mode: ");
                Serial.println(selectedMode + 1);
            }
        }
    }

    lastButtonReading = buttonReading;

    // Update LED controller
    controller.update(currentTime);
}
