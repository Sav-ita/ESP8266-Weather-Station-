# ESP8266 Weather Widget V2.0

This project creates a small desktop weather display based on the **ESP8266** and a **2.8" TFT display**.

It was born as an adaptation of the original ThingPulse project, with some hardware and mechanical simplifications.

The idea was to have a compact, attractive weather widget that would always be on the desktop, with data updated via WiFi.

---

## Functions

- Automatically updated time and date  
- Temperature, humidity, and pressure  
- Weather forecast up to 7 days  
- Wireless connection  
- Touchscreen navigation  

---

## Hardware Used

- Wemos D1 Mini Pro (ESP8266)  
- 2.8" ILI9341 TFT display with touch screen  
- Thin AWG 26 or 30 cables  
- 3D-printed case  
- USB power supply  

---

## Connections

### TFT → Wemos

| TFT  | Wemos |
|------|--------|
| VIN  | 3.3V   |
| GND  | GND    |
| CS   | D1     |
| RESET| RST    |
| DC   | D2     |
| SDI  | D7     |
| SCK  | D5     |
| LED  | D8     |
| SDO  | D6     |

### Touch

| Touch | Wemos |
|--------|--------|
| T_CLK  | D5     |
| T_CS   | D3     |
| T_DIN  | D7     |
| T_DO   | D6     |
| T_IRQ  | D4     |

---

## Arduino IDE Setup

Install ESP8266 support by adding this URL to the **Board Manager**:

<https://arduino.esp8266.com/stable/package_esp8266com_index.json>

Select the board:

**LOLIN (WEMOS) D1 R2 & mini**

### Recommended Settings

- CPU Frequency: **80 MHz**  
- Flash Size: **4MB (FS:3MB OTA:~512KB)**  

---

## Libraries

Original project repository:

<https://github.com/ThingPulse/esp8266-weather-station-color>

### Required Libraries

- Mini Grafx  
- ESP8266 WeatherStation  
- Json Streaming Parser  
- ThingPulse XPT2046 Touch  

> **Note:** If the standard **XPT2046_Touchscreen** library is installed, remove it before installing the ThingPulse library to avoid conflicts.

---

## OpenWeatherMap API

You need a free API key.

1. Register at: <https://openweathermap.org>  
2. Create an API key  
3. Insert it into the `settings.h` file along with your WiFi credentials  

---

## Upload Procedure

1. Download the repository  
2. Rename the folder to **esp8266-weather-station-color**  
3. Open `esp8266-weather-station-color.ino`  
4. Configure the `settings.h` file  
5. Upload the sketch  

On first boot, a temporary WiFi network is created for initial configuration.

---

## 3D Case

STL files available on Thingiverse:

<https://www.thingiverse.com/thing:4928974>

### Printing Tips

- Layer height: **0.2 mm**  
- Infill: **20%**  
- Material: **Standard PLA**

---

## Final Notes

The project is very stable, but requires some patience to:

- solder the wires correctly  
- perform a proper touch calibration  
- arrange the cables neatly inside the case  

Once assembled, it works flawlessly and is perfect as a compact desktop weather widget.