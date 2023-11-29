from collections.abc import Callable, Iterable, Mapping
import socket as sck
import time
from typing import Any 
import RPi.GPIO as GPIO
from threading import Thread
from AlphaBot import AlphaBot

#Costants

PORT = 8000
HOST = '0.0.0.0'
MY_ADDRESS = (HOST, PORT) 

DR = 16
DL = 19

class Sensori(Thread):
    def __init__(self):
        Thread.__init__(self)

    def run(self):
        GPIO.setmode(GPIO.BCM)
        GPIO.setwarnings(False)
        GPIO.setup(DR,GPIO.IN,GPIO.PUD_UP)
        GPIO.setup(DL,GPIO.IN,GPIO.PUD_UP)

        try:
            while True:
                DR_status = GPIO.input(DR)
                DL_status = GPIO.input(DL)
                if((DL_status == 1) and (DR_status == 1)):
                    susina.stop()
                    susina.forward()
                    print("forward")
                elif((DL_status == 1) and (DR_status == 0)):
                    susina.stop()
                    susina.left()
                    print("left")
                elif((DL_status == 0) and (DR_status == 1)):
                    susina.stop()
                    susina.right()
                    print("right")
                '''else:
                    susina.backward()
                    time.sleep(0.2)
                    susina.left()
                    time.sleep(0.2)
                    susina.stop()
                    print("backward")
                '''
        except KeyboardInterrupt:
            GPIO.cleanup()

socket = sck.socket(sck.AF_INET, sck.SOCK_STREAM)            
socket.bind(MY_ADDRESS)
socket.listen()

print(f'Server listening on {HOST}:{PORT}...')

susina = AlphaBot()