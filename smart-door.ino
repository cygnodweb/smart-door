#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

// ✅ WiFi Credentials
#define WIFI_SSID "6IOT1"
#define WIFI_PASS "06DAYIOT1"

// ✅ Telegram Bot Credentials
#define TELEGRAM_BOT_TOKEN "7798876685:AAE2EeOJQJbW4TkJgOelkDgd2j2Aong3h94"
#define CHAT_ID "7235091933"

// ✅ Sensor & Buzzer Pins
#define IR_SENSOR D5
#define VIBRATION_SENSOR D6
#define BUZZER D7

WiFiClientSecure client;

// ✅ Function to Send Telegram Alert
void sendTelegramMessage(String message) {
    client.setInsecure();
    if (client.connect("api.telegram.org", 443)) {
        client.setTimeout(5000);  // Timeout set karo
        String url = "/bot" + String(TELEGRAM_BOT_TOKEN) + "/sendMessage?chat_id=" + String(CHAT_ID) + "&text=" + message;
        client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                     "Host: api.telegram.org\r\n" +
                     "Connection: close\r\n\r\n");
        delay(500);
    }
}

// ✅ Setup Function
void setup() {
    Serial.begin(115200);
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    
    Serial.print("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi!");

    pinMode(IR_SENSOR, INPUT);
    pinMode(VIBRATION_SENSOR, INPUT);
    pinMode(BUZZER, OUTPUT);
    digitalWrite(BUZZER, LOW);  // Ensure buzzer is off initially
}

// ✅ Main Loop Function
void loop() {
    int irState = digitalRead(IR_SENSOR);
    int vibrationState = digitalRead(VIBRATION_SENSOR);

    // Check if any sensor is triggered
    if (irState == LOW || vibrationState == HIGH) {
        digitalWrite(BUZZER, HIGH);

        if (irState == LOW) {
            Serial.println("🚨 IR Sensor Triggered! Sending Alert...");
            sendTelegramMessage("🚨 Alert! Motion detected by IR sensor.");
        }

        if (vibrationState == HIGH) {
            Serial.println("🚨 Vibration Sensor Triggered! Sending Alert...");
            sendTelegramMessage("🚨 Alert! Vibration detected, possible tampering.");
        }

        delay(5000); // Buzzer duration
        digitalWrite(BUZZER, LOW);
    }

    delay(1000);
}
