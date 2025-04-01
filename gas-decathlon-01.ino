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
