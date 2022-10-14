#!/bin/bash
sudo apt-get update -y
sudo apt-get install git python3-pip redis -y
pip install Adafruit_Python_DHT redis sanic
echo "[Unit]
Description=Interface to hardware control
After=multi-user.target

[Service]
Type=idle
ExecStart=/usr/bin/python3 $HOME/app/hardwareController/kernel.py
Restart=always

[Install]
WantedBy=multi-user.target
" > minichef-kernel.service

echo "[Unit]
Description=Interface to hardware control
After=multi-user.target

[Service]
Type=idle
ExecStart=/usr/bin/python3 $HOME/app/controllAPI/controller.py
Restart=always

[Install]
WantedBy=multi-user.target
" > controllerApi.service

echo "[Unit]
Description=Interface to hardware control
After=multi-user.target

[Service]
Type=simple
ExecStart=/usr/bin/python3 $HOME/app/apisoftware/server.py
Restart=always

[Install]
WantedBy=multi-user.target
" > apisoftware.service



sudo mv minichef-kernel.service  /lib/systemd/system
sudo mv controllerApi.service /lib/systemd/system
sudo mv apisoftware.service  /lib/systemd/system

sudo systemctl daemon-reload

sudo systemctl enable minichef-kernel.service
sudo systemctl enable controllerApi.service
sudo systemctl enable apisoftware.service

sudo systemctl start minichef-kernel.service
sudo systemctl start controllerApi.service
sudo systemctl start apisoftware.service