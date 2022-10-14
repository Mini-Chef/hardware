import RPi.GPIO as GPIO
from time import sleep

class motorController:
  def __init__(self, motorPin=17, delay=0.05):
    self._motorPin = motorPin
    self._delay = delay
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(self._motorPin, GPIO.OUT)
    self._pwm = GPIO.PWM(self._motorPin, 50) #50 heartz
  def clearBoard(self):
      GPIO.cleanup()
      self._pwm.stop()
  def serveFood(self, serving=1):
    self._pwm.start(2.5)
    for i in range(serving):
      for dutyCycle in range(4,21): # range is 4 - 10 because to step be 0.5, the array need to divide by 2 [8, 9, 10 ... 21] => [4, 4.5, 5 ... 10]
        sleep(self._delay)
        self._pwm.ChangeDutyCycle(dutyCycle/2)
    self._pwm.stop()
  
"""
mock = motorController()
mock.serveFood(serving=2)
"""