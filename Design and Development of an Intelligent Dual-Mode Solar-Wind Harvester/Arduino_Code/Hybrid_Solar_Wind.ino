/******************************************************
 Intelligent Dual-Mode Solar-Wind Harvester
 ESP32 Main Program
******************************************************/

#include <WiFi.h>
#include <Wire.h>

#include "config.h"
#include "Sensor.h"
#include "MotorControl.h"
#include "ModeSwitch.h"

// Firebase (Next Part)
void initializeFirebase();
void uploadData();

//------------------------------------------------

unsigned long previousCloudUpdate = 0;
const long cloudInterval = 5000;

//------------------------------------------------

void setup()
{
    Serial.begin(115200);

    Serial.println();
    Serial.println("--------------------------------");
    Serial.println("Hybrid Solar-Wind Harvester");
    Serial.println("--------------------------------");

    initializeSensors();

    initializeMotors();

    initializeIndicators();

    //---------------- WiFi ----------------

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    Serial.print("Connecting to WiFi");

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("WiFi Connected");

    Serial.print("IP Address : ");
    Serial.println(WiFi.localIP());

    //---------------- Firebase ----------------

    initializeFirebase();

    Serial.println("System Ready");
}

//------------------------------------------------

void loop()
{

    //---------------- Read Sensors ----------------

    readLDR();

    readWindSensor();

    readVoltages();

    readCurrents();

    calculatePower();

    //---------------- Mode Decision ----------------

    automaticModeSwitch();

    //---------------- Display ----------------

    Serial.println();

    Serial.println("========= LIVE DATA =========");

    Serial.print("Light : ");
    Serial.println(lightIntensity);

    Serial.print("Wind Speed : ");
    Serial.print(windSpeed);
    Serial.println(" m/s");

    Serial.print("Solar Voltage : ");
    Serial.print(solarVoltage);
    Serial.println(" V");

    Serial.print("Wind Voltage : ");
    Serial.print(windVoltage);
    Serial.println(" V");

    Serial.print("Battery Voltage : ");
    Serial.print(batteryVoltage);
    Serial.println(" V");

    Serial.print("Battery Current : ");
    Serial.print(batteryCurrent);
    Serial.println(" A");

    Serial.print("Load Current : ");
    Serial.print(loadCurrent);
    Serial.println(" A");

    Serial.print("Solar Power : ");
    Serial.print(solarPower);
    Serial.println(" W");

    Serial.print("Wind Power : ");
    Serial.print(windPower);
    Serial.println(" W");

    if(currentMode == SOLAR_MODE)
        Serial.println("MODE : SOLAR");
    else
        Serial.println("MODE : WIND");

    //---------------- Cloud Upload ----------------

    if(millis() - previousCloudUpdate > cloudInterval)
    {
        previousCloudUpdate = millis();

        uploadData();
    }

    delay(100);
}