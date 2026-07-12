#include "Sensor.h"
#include "config.h"

// INA219 Objects
Adafruit_INA219 batteryINA(0x40);
Adafruit_INA219 loadINA(0x41);

// Sensor Variables
float solarVoltage = 0;
float windVoltage = 0;
float batteryVoltage = 0;

float batteryCurrent = 0;
float loadCurrent = 0;

float solarPower = 0;
float windPower = 0;

float windSpeed = 0;

int lightIntensity = 0;

// Pulse counter for anemometer
volatile unsigned long pulseCount = 0;

unsigned long previousMillis = 0;

// Interrupt Function
void IRAM_ATTR countPulse()
{
    pulseCount++;
}

// Initialize Sensors
void initializeSensors()
{
    pinMode(LDR_PIN, INPUT);

    pinMode(SOLAR_VOLT_PIN, INPUT);
    pinMode(WIND_VOLT_PIN, INPUT);
    pinMode(BATTERY_VOLT_PIN, INPUT);

    pinMode(ANEMOMETER_PIN, INPUT_PULLUP);

    attachInterrupt(
        digitalPinToInterrupt(ANEMOMETER_PIN),
        countPulse,
        RISING
    );

    Wire.begin();

    batteryINA.begin();
    loadINA.begin();

    Serial.println("Sensors Initialized");
}

// Read LDR
void readLDR()
{
    lightIntensity = analogRead(LDR_PIN);
}

// Read Wind Sensor
void readWindSensor()
{
    unsigned long currentMillis = millis();

    if(currentMillis - previousMillis >= 1000)
    {
        detachInterrupt(digitalPinToInterrupt(ANEMOMETER_PIN));

        float frequency = pulseCount;

        // Wind Speed Formula
        windSpeed = frequency * 0.4938;

        pulseCount = 0;

        previousMillis = currentMillis;

        attachInterrupt(
            digitalPinToInterrupt(ANEMOMETER_PIN),
            countPulse,
            RISING
        );
    }
}

// Read Voltages
void readVoltages()
{
    int solarADC = analogRead(SOLAR_VOLT_PIN);
    int windADC = analogRead(WIND_VOLT_PIN);
    int batteryADC = analogRead(BATTERY_VOLT_PIN);

    solarVoltage =
        ((solarADC * ADC_REF) / ADC_RESOLUTION) * SOLAR_DIVIDER;

    windVoltage =
        ((windADC * ADC_REF) / ADC_RESOLUTION) * WIND_DIVIDER;

    batteryVoltage =
        ((batteryADC * ADC_REF) / ADC_RESOLUTION) * BATTERY_DIVIDER;
}

// Read Currents
void readCurrents()
{
    batteryCurrent =
        batteryINA.getCurrent_mA() / 1000.0;

    loadCurrent =
        loadINA.getCurrent_mA() / 1000.0;
}

// Calculate Power
void calculatePower()
{
    solarPower =
        solarVoltage * batteryCurrent;

    windPower =
        windVoltage * batteryCurrent;
}