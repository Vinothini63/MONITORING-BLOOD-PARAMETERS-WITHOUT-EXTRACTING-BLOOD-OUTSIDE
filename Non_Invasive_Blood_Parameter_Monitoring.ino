#include <Wire.h>
#include "MAX30105.h"
MAX30105 particleSensor;
// Define analog pin for pressure sensor
const int pressurePin = A0;
// Variables for blood pressure
float pressureValue = 0; // Raw pressure sensor value
float systolic = 0;
float diastolic = 0;
bool measuringBP = false; // Flag to track BP measurement
void setup() {
Serial.begin(9600);
while (!Serial);
// Initialize MAX30102
if (!particleSensor.begin(Wire, I2C_SPEED_STANDARD)) {
Serial.println("MAX30102 not found. Check wiring/power.");
while (1);
}
particleSensor.setup(); // Configure MAX30102 settings
Serial.println("MAX30102 initialized.");
// Initialize pressure sensor
pinMode(pressurePin, INPUT);
Serial.println("Blood pressure sensor initialized.");
}
void loop() {
// Measure SpO2 and Heart Rate
measureSpO2AndHeartRate();
// Measure Blood Pressure
measureBloodPressure();
delay(1000); // Wait for 1 second before next iteration
}// Function to measure SpO2 and heart rate
void measureSpO2AndHeartRate() {
long irValue = particleSensor.getIR();
long redValue = particleSensor.getRed();
if (irValue < 50000) {
Serial.println("No finger detected for SpO2 measurement.");
return;
}// Display raw IR and Red values
Serial.print("IR: ");
Serial.print(irValue);
Serial.print(" | Red: ");
Serial.println(redValue);
// Calculate heart rate and SpO2 using a library or algorithm (placeholder here)
float heartRate = calculateHeartRate(irValue); // Replace with actual calculation
float spO2 = calculateSpO2(irValue, redValue);
Serial.print("Heart Rate: ");
Serial.print(heartRate);
Serial.print(" bpm | SpO2: ");
Serial.print(spO2);
Serial.println(" %");
}
// Placeholder function for heart rate calculation
float calculateHeartRate(long irValue) {
// Implement heart rate calculation algorithm
return 75.0; // Placeholder value
}
// Placeholder function for SpO2 calculation
float calculateSpO2(long irValue, long redValue) {
// Implement SpO2 calculation algorithm
return 98.0; // Placeholder value
}
// Function to measure blood pressure
11
void measureBloodPressure() {
pressureValue = analogRead(pressurePin); // Read raw sensor value
// Convert raw value to pressure in mmHg (sensor-dependent calculation)
float pressure = map(pressureValue, 0, 1023, 0, 300); // Example mapping
Serial.print("Current Pressure: ");
Serial.print(pressure);
Serial.println(" mmHg");
// Implement a basic oscillometric method for blood pressure
if (measuringBP) {
// Simulate detection of systolic and diastolic pressure (use real algorithm here)
systolic = 120; // Placeholder value
diastolic = 80; // Placeholder value
Serial.print("Systolic: ");
Serial.print(systolic);
Serial.print(" mmHg | Diastolic: ");
Serial.print(diastolic);
Serial.println(" mmHg");
measuringBP = false;
} else {
Serial.println("Waiting for BP measurement start...");
measuringBP = true; // Start measuring BP in next cycle
}
}
