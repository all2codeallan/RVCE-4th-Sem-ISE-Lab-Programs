# Experiment 6: Measuring temperature & humidity of weather using the DHT11 sensor with the Raspberry Pi.

## Setup Instructions
- Create a virtual environment and install the following libraries :\
`adafruit-circuitpython-DHT`\
`thingspeak`\
`rpi_lcd`
- If an error shows some module is missing, import that module in a similar manner.
- In your Thingspeak channel, create 2 fields and label them as per the code. (Temperature(in C) and Humidity(in %))


## Circuit Setup
- Connect DHT11 `Data/Signal` pin to Board pin 7 (BCM pin 4).
- Connect `SDA` and `SCL` pins of LCD I2C module to Board pins 3 and 5 respectively.