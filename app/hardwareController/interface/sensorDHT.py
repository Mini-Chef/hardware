import sys
import Adafruit_DHT
from time import sleep

class dhtSensor:
    def __init__(self,dataPin=25, delay=0.5, corrector=5) -> None:
        self._dataPin = dataPin
        self._delay = delay
        self._corrector = corrector
    def getTemperature(self) -> float:
        sleep(self._delay)
        _, temperature = Adafruit_DHT.read_retry(11, self._dataPin)
        return temperature-self._corrector
    def getHumidity(self) -> float:
        sleep(self._delay)
        humidity, _ = Adafruit_DHT.read_retry(11, self._dataPin)
        return humidity
    def getData(self) -> dict:
        sleep(self._delay)
        humidity, temperature = Adafruit_DHT.read_retry(11, self._dataPin)
        return {"humidity":humidity,"temperature":temperature-self._corrector}

"""
mock = dhtSensor()
print( mock.getTemperature() )
print( mock.getHumidity() )
print( mock.getData() )
"""