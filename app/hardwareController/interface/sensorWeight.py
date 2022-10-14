import json
import subprocess

class weightSensor:
    def __init__(self) -> None:
        self._read = 0
    def readWeight(self) -> None:
        rawData = subprocess.check_output(["head -1 /dev/ttyUSB0"], shell=True).decode()
        data = rawData.replace("'",'"')
        self._read = json.loads(data)['data']
        del rawData, data
    def _convertToG(self) -> float:
        return 0.4096*self._read

    def getRead(self) -> float:
        return self._convertToG()

    def readGetWeight(self) -> float:
        self.readWeight()
        return self.getRead()
"""
mock = sensorWeight()
print(mock.readGetWeight())
"""