// Define LED pins
const int led1 = 11;
const int led2 = 12;
const int led3 = 13;
void setup() {
    // Initialize LED pins as output
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
}
void loop() {
    // Turn on LED 1 for 1 second
    digitalWrite(led1, HIGH);
    delay(1000); // 1000 milliseconds = 1 second
    digitalWrite(led1, LOW);
    // Turn on LED 2 for 2 seconds
    digitalWrite(led2, HIGH);
    delay(2000); // 2000 milliseconds = 2 seconds
    digitalWrite(led2, LOW);
    // Turn on LED 3 for 3 seconds
    digitalWrite(led3, HIGH);
    delay(3000); // 3000 milliseconds = 3 seconds
    digitalWrite(led3, LOW);
}