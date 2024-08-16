import RPi.GPIO as GPIO
import urllib3
import time

# ThingSpeak settings'
THINGSPEAK_WRITE_API_KEY = 'EnterYourWriteKeyHere'                                                            
THINGSPEAK_CHANNEL_ID = 'EnterYourChannelIdHere'
THINGSPEAK_URL = f'https://api.thingspeak.com/update?api_key={THINGSPEAK_WRITE_API_KEY}'

def ldr():
    # Set up GPIO mode and pins
    GPIO.setmode(GPIO.BOARD)
    LED = 12
    LDR = 22
    Buzzer = 24

    GPIO.setup(LED, GPIO.OUT)
    GPIO.setup(Buzzer, GPIO.OUT)
    GPIO.setup(LDR, GPIO.IN)

    # Initialize HTTP connection
    http = urllib3.PoolManager()

    while True:
        LDRData = GPIO.input(LDR)
        LEDData = 0
        BuzzerData = 0
       
        if LDRData == 1:
            print("High: Switch on light")
            GPIO.output(LED, True)
            GPIO.output(Buzzer, True)
            LEDData = 1
            BuzzerData = 1
            print("LED ON, Buzzer sounds")
        else:
            print("Low: Don't switch on light")
            GPIO.output(LED, False)
            GPIO.output(Buzzer, False)
            LEDData = 0
            BuzzerData = 0
            print("LED OFF, Buzzer stops")
       
        # Wait before the next read
        time.sleep(0.3)  # 300 ms

        # Send data to ThingSpeak
        try:
            response = http.request(
                'POST',
                THINGSPEAK_URL,
                fields={'field1': str(LDRData), 'field2': str(LEDData), 'field3': str(BuzzerData)}
            )
            print(LDRData)
            print(LEDData)
            print(BuzzerData)
            print(response.status, response.data.decode('utf-8'))

        except Exception as e:
            print(f"Connection failed: {e}")
       
        time.sleep(1)  # Adjust sleep time as needed

if __name__ == "__main__":
    ldr()
