#ifndef CONFIG_H
#define CONFIG_H

/**********************
      WiFi Settings
**********************/

#define WIFI_SSID       "YOUR_WIFI_NAME"
#define WIFI_PASSWORD   "YOUR_WIFI_PASSWORD"

/**********************
 Firebase Settings
**********************/

#define API_KEY         "YOUR_FIREBASE_API_KEY"

#define DATABASE_URL    "https://YOUR_PROJECT.firebaseio.com/"

#define USER_EMAIL      "YOUR_FIREBASE_EMAIL"

#define USER_PASSWORD   "YOUR_FIREBASE_PASSWORD"

/**********************
 Sensor Thresholds
**********************/

// LDR Threshold
#define LIGHT_THRESHOLD 500

// Wind Speed Threshold (m/s)
#define WIND_THRESHOLD 3.0

// Hysteresis
#define HYSTERESIS 50

/**********************
 Servo Angles
**********************/

#define SOLAR_MODE_ANGLE 0
#define WIND_MODE_ANGLE 90

/**********************
 ADC Reference
**********************/

#define ADC_REF 3.3
#define ADC_RESOLUTION 4095.0

/**********************
 Voltage Divider Ratios
**********************/

#define SOLAR_DIVIDER 5.0
#define WIND_DIVIDER 5.0
#define BATTERY_DIVIDER 4.0

/**********************
 Battery Limits
**********************/

#define BATTERY_FULL 14.4
#define BATTERY_LOW 11.5

#endif