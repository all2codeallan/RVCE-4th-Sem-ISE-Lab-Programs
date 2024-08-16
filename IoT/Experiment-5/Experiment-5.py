import RPi.GPIO as GPIO
import time

# Set GPIO pin numbers
pir_pin = 12  # PIR sensor output pin
led_pin = 11  # LED pin

# Setup GPIO
GPIO.setmode(GPIO.BOARD)
GPIO.setup(pir_pin, GPIO.IN)
GPIO.setup(led_pin, GPIO.OUT)

# PIR sensor pin as input
# LED pin as output
try:
    print("PIR Sensor Test (CTRL+C to exit)")
    time.sleep(2)  # Warmup time for PIR sensor
    print("Ready")
    while True:
        if GPIO.input(pir_pin):  # If motion is detected
            print("Motion Detected!")
            GPIO.output(led_pin, GPIO.HIGH)  # Turn on LED
           
        else :
           
            print("Motion not detected")
            GPIO.output(led_pin, GPIO.LOW)
        time.sleep(0.5)
except KeyboardInterrupt:
    print("\nExiting...")
finally:
    GPIO.cleanup()