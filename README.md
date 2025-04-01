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


### Output:

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
