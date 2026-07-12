#include "MotorControl.h"
#include "config.h"

Servo servo1;
Servo servo2;

SystemMode currentMode = SOLAR_MODE;

// ---------------- Initialize ----------------

void initializeMotors()
{
    servo1.attach(SERVO1_PIN);
    servo2.attach(SERVO2_PIN);

    servo1.write(SOLAR_MODE_ANGLE);
    servo2.write(SOLAR_MODE_ANGLE);

    currentMode = SOLAR_MODE;

    Serial.println("Servo Motors Initialized");
}

// ---------------- Smooth Movement ----------------

void smoothMoveServo(Servo &motor, int startAngle, int endAngle)
{
    if(startAngle < endAngle)
    {
        for(int i = startAngle; i <= endAngle; i++)
        {
            motor.write(i);
            delay(20);
        }
    }
    else
    {
        for(int i = startAngle; i >= endAngle; i--)
        {
            motor.write(i);
            delay(20);
        }
    }
}

// ---------------- Solar Mode ----------------

void setSolarMode()
{
    if(currentMode == SOLAR_MODE)
        return;

    Serial.println("Switching to Solar Mode");

    smoothMoveServo(servo1, WIND_MODE_ANGLE, SOLAR_MODE_ANGLE);
    smoothMoveServo(servo2, WIND_MODE_ANGLE, SOLAR_MODE_ANGLE);

    currentMode = SOLAR_MODE;
}

// ---------------- Wind Mode ----------------

void setWindMode()
{
    if(currentMode == WIND_MODE)
        return;

    Serial.println("Switching to Wind Mode");

    smoothMoveServo(servo1, SOLAR_MODE_ANGLE, WIND_MODE_ANGLE);
    smoothMoveServo(servo2, SOLAR_MODE_ANGLE, WIND_MODE_ANGLE);

    currentMode = WIND_MODE;
}