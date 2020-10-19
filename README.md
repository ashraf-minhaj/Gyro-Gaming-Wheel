# Gyro-Gaming-Wheel
We all love playing games. To control games we need controllers, usually that is our keyboard + mouse combination or for some games on phone it's gyroscope. I saw some people make gaming steering wheel but one main problem is those are attached to something, which means they are not portable.
My idea was to design a single controller for racing games that will give the steering wheel vibe and will also come with all the buttons I need. But it has to be movable, so that I can take it anywhere and play on the go. 

#### Principle- How will it Work?
The controller will will work like our pc's keyboard and mouse, pressing forward, left right etc. I used Arduino pro micro for that. To get the steer wheel vibe without connecting to any potentiometer I used IMU6050 (Inertia Measurement Unit) to measure Y axis data, that will point out the tilting. And some buttons for pedal, brake, nitro etc.
I targetted Beach Buggy game's pc's version, it's light weight and runs on simple pc's too. To customize the controller with the game what is does is - 
•	Auto accelerator is on,
•	For left right tilt presses - left_arrow, right_arrow
•	For power/boost presses - 'z'
•	For Character Power presses - 'A'
The whole system is going to be powered from a USB cable that plugs into arduino and goes to all other components. This makes the design more reliable and super cool.

#### Video Demo:
https://youtu.be/NzfHxzomoY0

#### Written Tutorial:
tinyurl.com/y32l5okt
