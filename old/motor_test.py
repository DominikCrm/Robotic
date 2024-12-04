import RPi.GPIO as gpio
import time

gpio.setmode(gpio.BOARD)
x=0

for i in range (1000):
    gpio.setup(21,gpio.OUT)
    gpio.output(21, gpio.HIGH)
gpio.cleanup()
