#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_INA219.h>

// ---------------- GPIO Pins ----------------

// Analog Inputs
#define LDR_PIN             36
#define SOLAR_VOLT_PIN      34
#define WIND_VOLT_PIN       35
#define BATTERY_VOLT_PIN    32

// Digital Input
#define ANEMOMETER_PIN      39

// ---------------- INA219 ----------------

extern Adafruit_INA219 batteryINA;
extern Adafruit_INA219 loadINA;

// ---------------- Variables ----------------

extern float solarVoltage;
extern float windVoltage;
extern float batteryVoltage;

extern float batteryCurrent;
extern float loadCurrent;

extern float solarPower;
extern float windPower;

extern float windSpeed;

extern int lightIntensity;

// ---------------- Functions ----------------

void initializeSensors();

void readLDR();

void readWindSensor();

void readVoltages();

void readCurrents();

void calculatePower();

#endif