#!/usr/bin/env python3
import serial
from gpiozero import Button
import os
import random

# input pin declarations begin here
# use syntax name = Button(bcmPinNumber, bounce_time=1)
# find BCM pin numbers at https://pinout.xyz
errorPin = Button(20, bounce_time=1)

# USB declarations begin here
visorEyes = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
# visorMouth = serial.Serial('dev/ttyUSB1', 9600, timeout=1)
visorEyes.flush()
# visorMouth.flush()

# serial write functions begin here
def writeError():
    visorEyes.write(b"5") # priority 3, right beltline
#    visorMouth.write(b"5")
    print("error")
    os.system("omxplayer -o local /home/pi/flexOS/raspberry-pi/sounds/criticalwarning.wav > /dev/null")
	
writeError