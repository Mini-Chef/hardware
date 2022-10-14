import json
from redis import StrictRedis
class redisInterface:
    def __init__(self):
        self._host = '0.0.0.0'
        self._port = 9152
        self._password = ''
        self._client = StrictRedis(host='127.0.0.1', port=6379, password='')
        self._subscriber = self._client.pubsub()
        self._subscriber.subscribe('Response')
    def publishTask(self, channel, payload) -> None:
        self._client.publish(channel, json.dumps(payload))
    def waitResponse(self) -> str:
        while True:
            for message in  self._subscriber.listen():
                if message['data'] != 1:
                    return json.loads(message['data'])