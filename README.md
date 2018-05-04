# Poppy

Arduino circuit to count number of popped kernels in a microwave oven.
Uses a potentiometer, sound sensor, LCD display, and an Arduino Uno R3.

![Top View](./images/top-view.JPG?raw=true "Top View")


Here's how I intend for it to work.

![Animation](./images/Poppy.gif?raw=true "Poppy")

A major problems appears to be the transducer's high sensitivity to air. Any air currents in the room can toggle the digital output of the sound sensor and these can even over-power loud sounds near the microphone. An appropriate potentiometer setting must be used to limit the sensitivity of the transducer.
