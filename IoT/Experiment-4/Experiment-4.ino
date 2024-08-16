// Define pin numbers
const int gasPin = A0;
const int ledPin = 8;
void setup() {
    Serial.begin(9600); // Initialize serial communication
    pinMode(ledPin, OUTPUT); // Set LED pin as output
}
void loop() {
    // Read gas sensor value
    int gasValue = analogRead(gasPin);
    // Map gas sensor value to LED brightness
    int brightness = map(gasValue, 0, 1023, 0, 255);
    // Display gas sensor value on serial monitor
    Serial.print("Gas Level: ");
    Serial.println(gasValue);
    // Turn on LED based on gas sensor value
    analogWrite(ledPin, brightness);
    delay(1000); // Delay for 1 second
}