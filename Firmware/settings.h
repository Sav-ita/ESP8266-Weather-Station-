/**
 * settings.h
 * Configuration file for the ESP8266 Weather Station.
 * 
 * Part of the ESP8266 Weather Widget V2.0 project.
 * Author: Saverio Martino
 */

#pragma once
#include <Arduino.h>

// WiFi Settings
// Set your WiFi credentials here
const char* WIFI_SSID = "YOUR_WIFI_SSID";
const char* WIFI_PASS = "YOUR_WIFI_PASSWORD";

// OpenWeatherMap Settings
// Get your API Key from https://openweathermap.org/
String OPEN_WEATHER_MAP_APP_ID = "API";
String OPEN_WEATHER_MAP_LOCATION_ID = "2525471"; // Search for your city ID on OpenWeatherMap
String DISPLAY_CITY_NAME = "Bari, IT";
String OPEN_WEATHER_MAP_LANGUAGE = "it";
boolean IS_METRIC = true;

// Time Settings
// Use https://www.travelmath.com/time-zone/ to find your UTC offset
// and daylight savings time settings.
// Italy is UTC+1 (Winter) / UTC+2 (Summer)
float UTC_OFFSET = 1;

// Update intervals
const int UPDATE_INTERVAL_SECS = 15 * 60; // Update every 15 minutes

// Pins for the ILI9341 display as defined in README.md
// TFT -> Wemos
// CS -> D1 (GPIO5)
// RESET -> RST (Internal, but DC is D2)
// DC -> D2 (GPIO4)
// SDI (MOSI) -> D7 (GPIO13)
// SCK -> D5 (GPIO14)
// LED -> D8 (GPIO15)
// SDO (MISO) -> D6 (GPIO12)

#define TFT_CS   D1
#define TFT_DC   D2
#define TFT_LED  D8

// Pins for the Touch Screen as defined in README.md
// T_CLK -> D5 (GPIO14)
// T_CS -> D3 (GPIO0)
// T_DIN -> D7 (GPIO13)
// T_DO -> D6 (GPIO12)
// T_IRQ -> D4 (GPIO2)

#define TOUCH_CS  D3
#define TOUCH_IRQ D4

// Initial calibration data. 
// You might need to recalibrate for your specific screen.
#define ADC_MIN_X 300
#define ADC_MIN_Y 350
#define ADC_MAX_X 3800
#define ADC_MAX_Y 3800
