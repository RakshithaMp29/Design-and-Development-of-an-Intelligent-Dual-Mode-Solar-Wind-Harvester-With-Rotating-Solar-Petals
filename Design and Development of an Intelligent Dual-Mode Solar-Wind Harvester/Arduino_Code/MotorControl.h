#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#include <Arduino.h>
#include <ESP32Servo.h>

// Servo GPIO Pins
#define SERVO1_PIN 26
#define SERVO2_PIN 27

// Servo Objects
extern Servo servo1;
extern Servo servo2;

// Operating Modes
enum SystemMode
{
    SOLAR_MODE,
    WIND_MODE
};

extern SystemMode currentMode;

// Function Prototypes
void initializeMotors();

void setSolarMode();

void setWindMode();

void smoothMoveServo(Servo &motor, int startAngle, int endAngle);

#endif