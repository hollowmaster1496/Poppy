# Poppy

Arduino (clone) circuit to count number of popped kernels in a microwave oven.
Uses a potentiometer, sound sensor, LCD display, and an Elegoo Uno R3.

![Top View](./images/top-view.JPG?raw=true "Top View")

### Motivation 

You have an amazing movie recorded on DVR and there's nothing you need more for movie night than a bag of microwave popcorn. So you get out your box of popcorn bags 
and find there's one left. You pop it into the microwave with the default "Popcorn" setting. A few minutes later, you smell something burning. You dash over to the kitchen and sure enough, its your popcorn. NOOOOOOOOO! MOVIE NIGHT IS RUINED!

Little did you know, that the microwave oven you used is way more powerful than the one at your old man's place. This is an all too common problem. This project aims to prevent popcorn from burning by turning the microwave off immediately when a certain number of pops has been reached or when the frequency of pops has decreased substantially.

### Functionality 

Here's how I intend for it to work. An arduino tracks the number of popped kernels using a sound sensor which registers large popping sounds. The count is displayed on an LCD. Once the number of pops reaches say 100, turn the microwave oven off.

![Animation](./images/Poppy.gif?raw=true "Poppy")

### Current Issues 

A major problems appears to be the transducer's high sensitivity to air. Any air currents in the room can toggle the digital output of the sound sensor and these can even over-power loud sounds near the microphone. An appropriate potentiometer setting must be used to limit the sensitivity of the transducer.

Random toggling issue is also causing issues measuring the frequency of pops. I'll need a sound sensor with analogue output (or at least more that 1 bit of info).