#include "FirebaseManager.h"

#include <WiFi.h>

#include <Firebase_ESP_Client.h>

#include "config.h"
#include "Sensor.h"
#include "MotorControl.h"

// Firebase Helper Libraries
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig firebaseConfig;

bool signupOK = false;

//------------------------------------------------

void initializeFirebase()
{

    firebaseConfig.api_key = API_KEY;

    firebaseConfig.database_url = DATABASE_URL;

    auth.user.email = USER_EMAIL;
    auth.user.password = USER_PASSWORD;

    Firebase.begin(&firebaseConfig, &auth);

    Firebase.reconnectWiFi(true);

    Serial.println("Firebase Connected");

}

//------------------------------------------------

void uploadData()
{

    if(WiFi.status() != WL_CONNECTED)
    {
        Serial.println("WiFi Disconnected");
        return;
    }

    // Solar

    Firebase.RTDB.setFloat(&fbdo,
    "/Solar/Voltage",
    solarVoltage);

    Firebase.RTDB.setFloat(&fbdo,
    "/Solar/Power",
    solarPower);

    // Wind

    Firebase.RTDB.setFloat(&fbdo,
    "/Wind/Voltage",
    windVoltage);

    Firebase.RTDB.setFloat(&fbdo,
    "/Wind/Power",
    windPower);

    Firebase.RTDB.setFloat(&fbdo,
    "/Wind/Speed",
    windSpeed);

    // Battery

    Firebase.RTDB.setFloat(&fbdo,
    "/Battery/Voltage",
    batteryVoltage);

    Firebase.RTDB.setFloat(&fbdo,
    "/Battery/Current",
    batteryCurrent);

    Firebase.RTDB.setFloat(&fbdo,
    "/Load/Current",
    loadCurrent);

    // Environment

    Firebase.RTDB.setInt(&fbdo,
    "/Environment/Light",
    lightIntensity);

    // Mode

    if(currentMode == SOLAR_MODE)
    {
        Firebase.RTDB.setString(&fbdo,
        "/System/Mode",
        "Solar");
    }
    else
    {
        Firebase.RTDB.setString(&fbdo,
        "/System/Mode",
        "Wind");
    }

    // Timestamp

    Firebase.RTDB.setInt(&fbdo,
    "/System/Time",
    millis()/1000);

    Serial.println("Firebase Updated");
}