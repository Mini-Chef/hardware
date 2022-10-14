from redis import StrictRedis
import json
import string
import random

client = StrictRedis(host='127.0.0.1', port=6379, password='')

subscriber = client.pubsub()
subscriber.subscribe('Requests')

queue = []

def token_generator(str_size):
    allowed_chars=string.ascii_letters
    return ''.join(random.choice(allowed_chars) for x in range(str_size))

def getResponse():
    while True:
        if len(queue) > 0:
            for token in queue:
                try:
                    resp = client.get(token).decode()
                    queue.remove(token)
                    return resp
                except:
                    continue

while True:
    for message in subscriber.listen():
        if message['data'] != 1:
            msg = json.loads( message['data'] )
            msg['token'] = token_generator(16)
            queue.append(msg['token'])
            client.publish("Tasks",json.dumps(msg))
            resp = getResponse()
            client.publish("Response",json.dumps(resp))
            
            
