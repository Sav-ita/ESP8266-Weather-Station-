/**
 * WeatherStation.ino
 * Main sketch for the ESP8266 Weather Station.
 * 
 * Required Libraries:
 * - Mini Grafx (by Daniel Eichhorn)
 * - ESP8266 WeatherStation (by Daniel Eichhorn)
 * - Json Streaming Parser (by Daniel Eichhorn)
 * - ThingPulse XPT2046 Touch (by ThingPulse)
 * 
 * Author: Saverio Martino
 */

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <TimeLib.h>
#include <OpenWeatherMapCurrent.h>
#include <OpenWeatherMapForecast.h>
#include <OpenWeatherMapOneCall.h>
#include <MiniGrafx.h>
#include <ILI9341_SPI.h>
#include <XPT2046_Touchscreen.h>
#include "settings.h"

// Define the colors used in the UI
#define MINI_BLACK 0
#define MINI_WHITE 1
#define MINI_YELLOW 2
#define MINI_BLUE 3

uint16_t palette[] = {ILI9341_BLACK, ILI9341_WHITE, ILI9341_YELLOW, ILI9341_BLUE};
int BITS_PER_PIXEL = 2; // 2^2 = 4 colors

ILI9341_SPI tft = ILI9341_SPI(TFT_CS, TFT_DC);
MiniGrafx gfx = MiniGrafx(&tft, BITS_PER_PIXEL, palette);
XPT2046_Touchscreen touch(TOUCH_CS, TOUCH_IRQ);

OpenWeatherMapCurrentData currentData;
OpenWeatherMapForecastData forecasts[7];

unsigned long lastUpdate = 0;

void setup() {
  Serial.begin(115200);
  
  // Power up the display LED
  pinMode(TFT_LED, OUTPUT);
  digitalWrite(TFT_LED, HIGH);

  // Initialize display
  gfx.init();
  gfx.fillBuffer(MINI_BLACK);
  gfx.commit();

  // Initialize Touch
  touch.begin();

  // Connect to WiFi
  connectWiFi();

  // Initial data fetch
  updateData();
}

void loop() {
  if (millis() - lastUpdate > UPDATE_INTERVAL_SECS * 1000) {
    updateData();
  }

  // Handle touch events
  if (touch.touched()) {
    TS_Point p = touch.getPoint();
    Serial.printf("Touch at X: %d, Y: %d\n", p.x, p.y);
    // Add logic here to switch screens or activate functions
  }

  drawUI();
  delay(100);
}

void connectWiFi() {
  gfx.setTextAlignment(TEXT_ALIGN_CENTER);
  gfx.setColor(MINI_WHITE);
  gfx.drawString(120, 160, "Connessione WiFi...");
  gfx.commit();

  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connesso");
  gfx.fillBuffer(MINI_BLACK);
  gfx.drawString(120, 160, "Connesso!");
  gfx.commit();
}

void updateData() {
  Serial.println("Aggiornamento dati meteo...");
  
  OpenWeatherMapCurrent *currentClient = new OpenWeatherMapCurrent();
  currentClient->updateCurrentById(&currentData, OPEN_WEATHER_MAP_APP_ID, OPEN_WEATHER_MAP_LOCATION_ID);
  delete currentClient;

  // You can also add forecast updates here
  
  lastUpdate = millis();
}

void drawUI() {
  gfx.fillBuffer(MINI_BLACK);
  
  gfx.setColor(MINI_WHITE);
  gfx.setTextAlignment(TEXT_ALIGN_CENTER);
  gfx.drawString(120, 20, DISPLAY_CITY_NAME);
  
  gfx.setColor(MINI_YELLOW);
  String temp = String(currentData.temp, 1) + (IS_METRIC ? "°C" : "°F");
  gfx.drawString(120, 80, temp);
  
  gfx.setColor(MINI_WHITE);
  gfx.drawString(120, 140, currentData.description);
  
  gfx.commit();
}
