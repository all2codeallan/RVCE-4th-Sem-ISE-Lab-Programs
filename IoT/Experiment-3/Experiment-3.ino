#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    lcd.begin();
    lcd.backlight();
    // Print initial message
    lcd.setCursor(0, 0);
    lcd.print("System Monitor");
    lcd.setCursor(0, 1);
    lcd.print("Initializing...");
    delay(2000);
}

void loop() {
    // Update system stats
    float networkUtilization = getNetworkUtilization();
    float cpuLoad = getCPULoad();
    float diskSpace = getDiskSpace();
    // Display system stats on LCD
    lcd.clear(); // Clear the LCD screen
    lcd.setCursor(0, 0);
    lcd.print("Network: ");
    lcd.print(networkUtilization);
    lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print("CPU: ");
    lcd.print(cpuLoad);
    lcd.print("% Disk: ");
    lcd.print(diskSpace);
    lcd.print("GB");
    delay(5000); // Delay for 5 seconds before updating again
}

// Function to get network utilization
float getNetworkUtilization() {
// Implement your code to get network utilization
return 50.5; // Placeholder value for demonstration
}

// Function to get CPU load
float getCPULoad() {
// Implement your code to get CPU load
return 30.2; // Placeholder value for demonstration
}
// Function to get disk space
float getDiskSpace() {
// Implement your code to get disk space
return 25.7; // Placeholder value for demonstration
}