#!/usr/bin/python3
from redis import StrictRedis
import json
from interface.motorCotroller import motorController
from interface.sensorDHT import dhtSensor
from interface.sensorWeight import weightSensor
from time import sleep

client = StrictRedis(host='127.0.0.1', port=6379, password='')

subscriber = client.pubsub()
subscriber.subscribe('Tasks')

feeder = motorController()
dhtsensor = dhtSensor()
weightsensor = weightSensor()

def feed(weight) -> dict:
    i = 0
    while True:
        i+=1
        if weightsensor.readGetWeight() <= weight:
            print('servindo')
            feeder.serveFood(serving=2)
        print(weightsensor.readGetWeight())
        sleep(1)
    return {"porcoes":i}

def getData() -> dict:
    aux = dhtsensor.getData()
    aux['plate'] = int( weightsensor.readGetWeight() )
    return aux

def sendFeedback(token,payload):
    if type(payload) != dict:
        payload = {"data": payload}
    client.set(token, json.dumps(payload) )

taskTree = {
    "feed":feed,
    "temperature":dhtsensor.getTemperature,
    "humidity":dhtsensor.getHumidity,
    "plate":weightsensor.readGetWeight,
    "data":getData
}

try:
    while True:
        for message in subscriber.listen():
            if message['data'] != 1:
                msg = json.loads( message['data'] )
                if msg['task'] == 'feed':
                    payload = taskTree[msg['task']](215)
                    sendFeedback(msg['token'], payload)
                else:
                    payload = taskTree[msg['task']]()
                    sendFeedback(msg['token'], payload)
except Exception as e:
    print(e)
    feeder.clearBoard()

