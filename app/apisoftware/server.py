from curses import reset_prog_mode
from sanic import Sanic
from services.redis import redisInterface
from sanic.response import json as sanic_json
import json
rdb = redisInterface()
app = Sanic("minichef")

@app.get('/sensors')
def sensor(request):
    rdb.publishTask("Requests",{"task":"data"})
    resp = rdb.waitResponse()
    return sanic_json(json.loads(resp),200)

@app.get('/sensors/<sensor>')
def espesificSensor(request, sensor):
    rdb.publishTask("Requests",{"task":sensor})
    resp = rdb.waitResponse()
    return sanic_json(json.loads(resp),200)

@app.post("/config/<action>")
def configurate(request, action):
    rdb.publishTask("Requests", request.json)
    resp = rdb.waitResponse()
    return(sanic_json(json.loads(resp),200))

if '__main__' == __name__:
    app.run(host='0.0.0.0',port=9152, debug=True)
