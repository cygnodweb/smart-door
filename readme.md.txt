# Intrusion Detection System using ESP8266

## 📌 Overview
This project implements an intrusion detection system using an **ESP8266** microcontroller. It uses an **IR sensor** and a **vibration sensor** to detect any unauthorized movement. When an intrusion is detected, it triggers a **buzzer** and sends a **Telegram alert** to a specified chat.

## 🔧 Hardware Requirements
- ESP8266 (NodeMCU)
- IR Sensor
- Vibration Sensor
- Buzzer
- WiFi Connection

## 🛠️ Circuit Connections
| Component            | ESP8266 Pin |
|---------------------|------------|
| IR Sensor          | D5 (GPIO14) |
| Vibration Sensor   | D6 (GPIO12) |
| Buzzer            | D7 (GPIO13) |

## 🚀 Installation & Setup
1. **Install ESP8266 Board Package**
   - Open **Arduino IDE**
   - Go to **File** → **Preferences**
   - Add the following URL in *Additional Board Manager URLs*:
     ```
     http://arduino.esp8266.com/stable/package_esp8266com_index.json
     ```
   - Go to **Tools** → **Board** → **Boards Manager**
   - Search for **ESP8266** and install the package

2. **Install Required Libraries**
   - Open **Arduino IDE**
   - Go to **Sketch** → **Include Library** → **Manage Libraries**
   - Search and install:
     - `ESP8266WiFi`
     - `WiFiClientSecure`

3. **Update Credentials in the Code**
   - Set your **WiFi credentials** in the code:
     ```cpp
     #define WIFI_SSID "Your_WiFi_Name"
     #define WIFI_PASS "Your_WiFi_Password"
     ```
   - Get your **Telegram Bot Token** from [BotFather](https://t.me/botfather) and set it in the code:
     ```cpp
     #define TELEGRAM_BOT_TOKEN "Your_Bot_Token"
     ```
   - Get your **Chat ID** using [IDBot](https://t.me/myidbot) and set it in the code:
     ```cpp
     #define CHAT_ID "Your_Chat_ID"
     ```

## 🔄 How It Works
1. **ESP8266 connects to WiFi** on startup.
2. It **monitors the IR sensor and vibration sensor** continuously.
3. If any movement is detected:
   - The **buzzer turns ON**.
   - A **Telegram alert is sent** to the user.
   - The buzzer remains ON for **5 seconds**, then turns OFF.
4. The system **resumes monitoring** after a short delay.

## 📝 Code Explanation
- **WiFi Connection:** Connects ESP8266 to a specified WiFi network.
- **Telegram Alerts:** Uses `WiFiClientSecure` to send messages via Telegram API.
- **Sensor Monitoring:** Reads data from IR and vibration sensors.
- **Buzzer Activation:** Turns ON buzzer when an intrusion is detected.

## 📌 Usage
- Deploy in **homes, offices, or restricted areas** for security monitoring.
- Modify the code to integrate with **other IoT devices** for smart home automation.

## 📜 License
This project is **open-source** and free to use under the **MIT License**.

## 📬 Contact
For any queries, feel free to reach out!

Happy Coding! 🚀

