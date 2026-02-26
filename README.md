# 🏥 Dynamic Health Surveillance System (DHSS)

![IoT](https://img.shields.io/badge/Domain-IoT-blue)
![Platform](https://img.shields.io/badge/Microcontroller-ESP8266-green)
![Cloud](https://img.shields.io/badge/Cloud-Blynk-orange)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

---

## 📌 Overview

The **Dynamic Health Surveillance System (DHSS)** is an IoT-based real-time health monitoring system designed to continuously track:

- ❤️ Heart Rate (BPM)
- 🌡 Body Temperature
- 🌡 Room Temperature
- 💧 Humidity

The system uses **ESP8266 NodeMCU** and integrates multiple sensors with the **Blynk IoT Cloud Platform** to enable remote monitoring and instant alert notifications.

This project is designed to be:

- ✅ Low-cost  
- ✅ Portable  
- ✅ Energy-efficient  
- ✅ Suitable for elderly & remote patients  

---

## 🚀 Features

- 📊 Real-time vitals monitoring
- 📟 Live display on 16x2 I2C LCD
- ☁️ Cloud monitoring via Blynk
- 🔔 Automatic alert system
- 🔴 LED visual warning
- 📶 Wi-Fi enabled communication
- 📱 Mobile app integration

---

## 🛠 Hardware Components

| Component | Purpose |
|------------|----------|
| ESP8266 NodeMCU | Microcontroller + Wi-Fi |
| Pulse Sensor | Heart Rate Monitoring |
| DHT11 | Room Temperature & Humidity |
| DS18B20 | Body Temperature |
| 16x2 I2C LCD | Real-Time Output |
| Buzzer | Audio Alert |
| LED | Visual Alert |

---

## 💻 Software Used

- Arduino IDE  
- Blynk IoT Platform  
- ESP8266WiFi Library  
- BlynkSimpleEsp8266 Library  
- DHT Library  
- DallasTemperature Library  
- LiquidCrystal_I2C Library  

---

## 🧠 System Architecture

```
Sensors → ESP8266 → LCD Display
                ↓
           Wi-Fi Module
                ↓
           Blynk Cloud
                ↓
            Mobile App
```

---

## ⚙️ Working Logic

1. Sensors collect health parameters.
2. ESP8266 processes sensor data.
3. Values displayed on LCD.
4. Data transmitted to Blynk cloud.
5. Alerts triggered if abnormal readings detected.

---

## 🔔 Alert Conditions

| Condition | Action Triggered |
|------------|------------------|
| BPM < 60 | Buzzer + LED + Blynk Notification |
| Body Temp > 35°C | Buzzer + LED + Blynk Notification |

---

## 📂 Project Structure

```
## 📂 Project Structure

```
IOT-DYNAMIC-HEALTH-SURVEILLANCE/
│
├── code/
│   ├── hardware/
│   │   ├── image.png
│   │   └── project.png
│   │
│   ├── dhss.ino
│   └── README.md
```


---

## 🧪 Testing Scenarios

✔ Normal sensor values → Data shown on LCD & Blynk  
✔ BPM < 60 → Alert triggered  
✔ Body Temp > 35°C → Alert triggered  
✔ Wi-Fi disconnected → LCD works, cloud paused  
✔ Wi-Fi reconnect → Cloud resumes updates  




## 📈 Future Improvements

- SpO2 Sensor Integration  
- ECG Module Integration  
- AI-Based Predictive Health Monitoring  
- GPS-Based Patient Tracking  
- Improved Mobile UI  

---

## 📚 References

- IEEE IoT Health Monitoring Research Papers  
- Blynk Official Documentation  
- ESP8266 Official Documentation  

---

## 👩‍💻 Authors

- G.Lavanya
- Hailey  
- Vignesh  

---

## 📜 License

This project is developed for academic and research purposes.
