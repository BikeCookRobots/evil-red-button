# evil red button prop
this big red button connects to wifi and does whatever you program it to!

[video](https://www.youtube.com/watch?v=XyMc2jrceqA)

![](https://github.com/BikeCookRobots/evil-red-button/blob/master/media/stillevil-button-00001.png?raw=true)

if you want only 8 functions, then you use one of the DIP switches from the 4 switch package as a power switch .

Note, the power switch simply breaks the circuit to the battery. This means the device needs to be powered on to charge

# tools/ materials needed
3d printer
heatset insert tool
a spot of super glue or hot glue
11 M3 x 6mm heatset inserts
11 M3 x 5mm screws (countersunk flat)
3 springs of the correct length
1 tactile push button
1 four switch DIP package
1 single switch DIP package *see note in intro* 
sparkfun Qwiic Pocket
JST battery connector (possible to re-use the one on the microcontroller, but I couldnt remove mine cleanly)
LiPo battery
small piece of protoboard

# steps
1) print all the parts. the backer  may be laser cut or 3d print. I used PLA with standard settings. You might want to adjust your slicer to infill the posts with enough material. Optionally paint to correct color
2) insert all threaded inserts
3) bend legs of the tactile button flat, solder a few wires on the legs and glue to the center of the "Y" shaped piece. Take care that you are soldering the correct legs so continuity is read when pushing the button. Only two legs need be soldered.
4) remove the jst connector from the microcontroller
5) solder all components as shown in diagram
6) modify code to match your credentials (WiFi, MQTT). Optionally, modify commands to match your application.
7) load code onto board
8) configure Home Assistant (or whatever is controlling your devices) to respond to the commands from the button

![](schematic/circuit_light#gh-light-mode-only)
![](schematic/circuit_dark#gh-dark-mode-only)
