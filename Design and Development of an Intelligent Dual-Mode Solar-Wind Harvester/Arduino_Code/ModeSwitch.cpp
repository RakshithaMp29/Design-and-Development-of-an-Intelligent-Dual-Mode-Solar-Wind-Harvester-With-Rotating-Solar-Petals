#include "ModeSwitch.h"
#include "Sensor.h"
#include "MotorControl.h"
#include "config.h"

// GPIO Pins
#define BUZZER_PIN 14
#define STATUS_LED 5

//------------------------------------------------

void initializeIndicators()
{
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(STATUS_LED, OUTPUT);

    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(STATUS_LED, LOW);
}

//------------------------------------------------

void buzzerBeep(int times)
{
    for(int i=0;i<times;i++)
    {
        digitalWrite(BUZZER_PIN,HIGH);
        delay(150);

        digitalWrite(BUZZER_PIN,LOW);
        delay(150);
    }
}

//------------------------------------------------

void statusLED(bool state)
{
    digitalWrite(STATUS_LED,state);
}

//------------------------------------------------

void automaticModeSwitch()
{

    //------------ SOLAR MODE ------------

    if(lightIntensity > (LIGHT_THRESHOLD + HYSTERESIS))
    {
        if(currentMode != SOLAR_MODE)
        {
            setSolarMode();

            buzzerBeep(1);

            statusLED(true);

            Serial.println("---------------------");
            Serial.println("SOLAR MODE ENABLED");
            Serial.println("---------------------");
        }
    }

    //------------ WIND MODE ------------

    else if(lightIntensity < (LIGHT_THRESHOLD - HYSTERESIS)
            && windSpeed >= WIND_THRESHOLD)
    {
        if(currentMode != WIND_MODE)
        {
            setWindMode();

            buzzerBeep(2);

            statusLED(false);

            Serial.println("---------------------");
            Serial.println("WIND MODE ENABLED");
            Serial.println("---------------------");
        }
    }

    //------------ WAIT ------------

    else
    {
        Serial.println("Waiting for Better Conditions...");
    }
}