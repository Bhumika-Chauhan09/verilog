// Define the pins for the ultrasonic sensor
const int trigPin = 9;  // Trigger pin
const int echoPin = 10; // Echo pin

// Define the LED pin
const int ledPin = 13;

// Define variables for storing sensor data
long duration;
int distance;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set the trigger and echo pins as inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Send a 10us pulse to trigger the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the time it takes for the echo to return
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in centimeters
  distance = duration * 0.034 / 2;
  
  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Check if an object is detected within a certain range (e.g., 30 cm)
  if (distance < 30) {
    // Turn on the LED
    digitalWrite(ledPin, HIGH);
    Serial.println("Object Detected!");
  } else {
    // Turn off the LED
    digitalWrite(ledPin, LOW);
    Serial.println("No Object Detected");
  }
  
  // Wait for a short delay before taking the next measurement
  delay(1000);
}