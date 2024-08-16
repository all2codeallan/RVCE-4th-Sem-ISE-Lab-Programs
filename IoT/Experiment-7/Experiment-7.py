# Gmail login credentials to send email
username = 'FromAddress@gmail.com'   # Enter 'From' gmail address
password = 'AppPasswordGoesHere'           # Enter app password corresponding to 'From' address

# General Email Parameters
From = "FromAddress@gmail.com" # 'From' email address (Same as above given username)
To = "ToAddress@gmail.com"

# Email Parameters when sensor is Wet 
Subject_wet = "Hello"
Body_wet = "Your water sensor is wet."

# Email Parameters when sensor is Dry
Subject_dry = "Hello"
Body_dry = " Your water sensor is dry again!"

import smtplib
from email.mime.text import MIMEText
import RPi.GPIO as GPIO
import string
import time
GPIO.setwarnings(False)

# Function Definitions
#takes either "wet" or "dry" as the condition.
def email(condition):
    print("Attempting to send email")
    if condition == 'wet':
        Body = "".join((
        "From: %s" % From,
        "To: %s" % To,
        "Subject: %s" % Subject_wet,
        "",
        Body_wet,))
    if condition == 'dry':
        Body = "".join((
        "From: %s" % From,
        "To: %s" % To,
        "Subject: %s" % Subject_dry,
        "",
        Body_dry,))
    # The actual mail send
    server = smtplib.SMTP('smtp.gmail.com:587')
    server.starttls()
    print("Logging in...")

    server.login(username,password)
    print("Logged in as "+username+".")
    server.sendmail(From, [To], Body)
    server.quit()
    print("Email sent.")


#Tests whether water is present.
# returns 0 for dry
# returns 1 for wet
# tested to work on board pin 18
def RCtime (RCpin):
    reading = 0
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(RCpin, GPIO.OUT)
    GPIO.output(RCpin, GPIO.LOW)
    time.sleep(0.1)
    GPIO.setup(RCpin, GPIO.IN)
    # This takes about 1 millisecond per loop cycle
    while True:
        if (GPIO.input(RCpin) == GPIO.LOW):
            reading += 1
        if reading >= 1000:
            return 0
        if (GPIO.input(RCpin) != GPIO.LOW):
            return 1
        

# Turns on the piezo buzzer
# tested to work on board pin 11
def buzz_on(pin):
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(pin, GPIO.OUT)
    GPIO.output(pin, GPIO.HIGH)


# Turns off the piezo buzzer
# tested to work on pin 11
def buzz_off(pin):
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(pin, GPIO.OUT)
    GPIO.output(pin, GPIO.LOW)

    
# Main Loop
print('Waiting for wetness...')
while True:
    time.sleep(1)
    if RCtime(18) == 0:
        print("Sensor is wet")
    email('wet')
    while True:
        time.sleep(1)
        if RCtime(18) == 0:
            print("Sensor is still wet...")
            buzz_on(11)
            break
        if RCtime(18) == 1:
            buzz_off(11)
            print("Sensor is dry again")
            email('dry')
            print("Waiting for wetness...")
            break
