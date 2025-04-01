# Gas-sensor : **MQ-5**, which is used to detect **Natural Gas, LPG, Coal Gas, and Methane (CH4)**.

<p align="center">
  <img src="https://github.com/user-attachments/assets/8c88f6e2-da76-450e-9b22-146384c38860" alt="Image 1" width="46%" style="margin-right: 10px;"/>
  <img src="https://github.com/user-attachments/assets/070cae4e-8c13-49db-8e65-6c502084ed14" alt="Image 2" width="46%" style="margin-right: 10px;"/>
  </br>
  <img src="https://github.com/user-attachments/assets/9978502d-1cb4-4b93-8705-b2094268ac38" alt="Image 1" width="46%" style="margin-right: 10px;"/>
  <img src="https://github.com/user-attachments/assets/7193adff-664c-4704-8f98-dc999653d9cd" alt="Image 2" width="46%" style="margin-right: 10px;"/>
</p>

---

### **🛠️ Components Required:**  
- **MQ-5 Gas Sensor**  
- **Arduino Uno** (or NANO) 
- **Jumper Wires**  
- **Power Supply (5V from Arduino)**  

---

### **🔌 Wiring Connections:**  

| **MQ-5 Sensor Pin** | **Arduino Pin** |  
|--------------------|---------------|  
| **VCC**           | **5V**         |  
| **GND**           | **GND**        |  
| **A0 (Analog Output)** | **A0**         |  
| **D0 (Digital Output, Optional)** | **D7** (if needed) |  

---

### Code -->

```cpp
int gasSensorPin = A0;  // Analog pin connected to MQ-5
int digitalPin = 7;     // Digital pin (optional)
int sensorValue;
int threshold = 400;    // Set a reasonable threshold

void setup() {
  Serial.begin(9600);
  pinMode(digitalPin, INPUT);
  
  Serial.println("MQ-5 Gas Sensor Test");
  Serial.println("Warming up... Please wait 2-3 minutes.");
  delay(3000);  // Allow sensor to stabilize (increase to 2-3 min for real use)
}

void loop() {
  sensorValue = analogRead(gasSensorPin);
  Serial.print("Gas Level (Analog): ");
  Serial.println(sensorValue);
  
  if (sensorValue > threshold) {  // Use a stable threshold
    Serial.println("🚨 Gas detected!");
  } else {
    Serial.println("✅ No gas detected.");
  }

  delay(2000);  // Increase delay for more stable readings
}
```

[<img align="right" alt="servo" width="300" src="https://github.com/user-attachments/assets/2b8eeee4-d67a-4e69-8d25-24c1e578f5e1">](https://www.linkedin.com/posts/arkadip2008_gas-detection-system-activity-7312738420567535616--Y2n)


### Output & Video

```go
✅ No gas detected.
Gas Level (Analog): 117
✅ No gas detected.
Gas Level (Analog): 247
✅ No gas detected.
Gas Level (Analog): 738
🚨 Gas detected!
Gas Level (Analog): 762
🚨 Gas detected!
Gas Level (Analog): 687
🚨 Gas detected!
Gas Level (Analog): 132
✅ No gas detected.
Gas Level (Analog): 104
✅ No gas detected.
Gas Level (Analog): 88
✅ No gas detected.
Gas Level (Analog): 57
✅ No gas detected.
Gas Level (Analog): 47
✅ No gas detected.
Gas Level (Analog): 50
✅ No gas detected.
Gas Level (Analog): 50
✅ No gas detected.
Gas Level (Analog): 569
🚨 Gas detected!
Gas Level (Analog): 142
✅ No gas detected.
Gas Level (Analog): 61
```

---

# add Display

Add a **JHD162A (16x2 LCD) with an I2C module** to display **live gas levels** from MQ-5  Gass sensor.  

---

### **🛠️ Components Required:**  
- **Arduino Uno/Nano**  
- **MQ-5 Gas Sensor**  
- **JHD162A (16x2 LCD) with I2C Module**  
- **Jumper Wires**  

---

### **🔌 Connections:**  

| **Component** | **Arduino Pin** |  
|-------------|---------------|  
| **MQ-5 VCC** | **5V** |  
| **MQ-5 GND** | **GND** |  
| **MQ-5 A0** | **A0** |  
| **I2C LCD VCC** | **5V** |  
| **I2C LCD GND** | **GND** |  
| **I2C LCD SDA** | **A4 (SDA)** |  
| **I2C LCD SCL** | **A5 (SCL)** |  

---

### **📜 Arduino Code with I2C LCD Display**  

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD setup (default I2C address 0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);  

int gasSensorPin = A0;  // MQ-5 Analog Output
int threshold = 400;    // Gas detection threshold

void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();  // Turn on LCD backlight

  Serial.println("MQ-5 Gas Sensor Test");
  lcd.setCursor(0, 0);
  lcd.print("MQ-5 Sensor Test");
  lcd.setCursor(0, 1);
  lcd.print("Warming up...");
  delay(3000);  // Warm-up time
}

void loop() {
  int sensorValue = analogRead(gasSensorPin);
  
  // Print values to Serial Monitor
  Serial.print("Gas Level: ");
  Serial.println(sensorValue);

  // Display gas level on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Gas Level: ");
  lcd.print(sensorValue);
  
  // Gas detection message
  lcd.setCursor(0, 1);
  if (sensorValue > threshold) {
    Serial.println("🚨 Gas Detected!");
    lcd.print("🚨 Gas Detected!");
  } else {
    Serial.println("✅ Safe");
    lcd.print("✅ Safe");
  }

  delay(2000);  // Delay for stability
}
```

---

### **🛠️ How It Works ?**  
- The **gas level is displayed live** on the LCD screen.  
- If gas exceeds the **threshold (400)**, it shows **"🚨 Gas Detected!"**.  
- If the environment is **safe**, it shows **"✅ Safe"**.  
- The Serial Monitor also prints the same information.  

---

### **📟 LCD Display Output:**  
#### **Normal Air (Safe Condition)**  
```
Gas Level: 180  
✅ Safe  
```
#### **When Gas is Detected (Lighter near sensor)**  
```
Gas Level: 650  
🚨 Gas Detected!  
```

---

### **🔹 Points to know:**  
- If the LCD **doesn’t display** anything, try changing `0x27` to `0x3F` in `LiquidCrystal_I2C lcd(0x27, 16, 2);`.  
- The **threshold (`400`)** can be adjusted based on your sensor's response.  
- Always give the sensor **2-3 minutes of warm-up** for accurate readings.  

---
