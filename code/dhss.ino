#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// WiFi Credentials
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "tech";
char pass[] = "12345678";

// LCD Configuration (SDA = D1, SCL = D2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// DHT11 Configuration
#define DHTPIN D5
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// DS18B20 Temperature Sensor Configuration
#define ONE_WIRE_BUS D6
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// Pulse Sensor Configuration
#define PULSE_SENSOR_PIN A0

// Buzzer and LED Configuration
#define BUZZER_PIN D7
#define RED_LED_PIN D8

// Reporting Time
#define REPORTING_PERIOD_MS 1000
uint32_t tsLastReport = 0;

// Variables
int BPM, humidity;
float roomTemp, bodyTemp;

void setup() {
  Serial.begin(115200);

  // Initialize I2C
  Wire.begin(D1, D2);
  Serial.println("I2C Initialized");

  // Initialize LCD
  lcd.init();
  lcd.backlight();
  Serial.println("LCD Initialized");

  // Startup Message
  lcd.setCursor(2, 0);
  lcd.print("Health System");
  lcd.setCursor(3, 1);
  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();
  Serial.println("Startup Message Displayed");

  // Initialize Blynk
  Blynk.begin(auth, ssid, pass);
  Serial.println("Blynk Initialized");

  // Initialize Sensors
  dht.begin();
  sensors.begin();
  pinMode(PULSE_SENSOR_PIN, INPUT);
  Serial.println("Sensors Initialized");

  // Initialize Buzzer and LED
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(RED_LED_PIN, LOW);
  Serial.println("Buzzer and LED Initialized");
}

void loop() {
  Blynk.run();

  // Send data to Blynk
  Blynk.virtualWrite(V1, BPM);
  Blynk.virtualWrite(V2, roomTemp);
  Blynk.virtualWrite(V3, humidity);
  Blynk.virtualWrite(V4, bodyTemp);

  // Alert System
  if (BPM < 60) {
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(RED_LED_PIN, HIGH);
    Blynk.logEvent("health_alert", "Low Heart Rate Detected!");
  }
  else if (bodyTemp > 35.0) {
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(RED_LED_PIN, HIGH);
    Serial.println("ALERT: High Body Temperature!");
    Blynk.logEvent("health_alert", "High Body Temp Detected!");
  }
  else {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);
  }

  delay(100);
}
