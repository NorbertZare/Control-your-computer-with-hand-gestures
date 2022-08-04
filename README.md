# Control-your-computer-with-hand-gestures
Control your computer with hand gestures

Since the 1970s personal computers have mouse and keyboards.
I think soon the mouse and keyboards will be replaced with gesture control technology.
I built a device to control a computer with hand gestures, this device does not replace the mouse and keyboards but it makes using the computer more fun and you can customize it based on your needs.

In this project I used a PAJ7620U2 Gesture Sensor.
PAJ7620U2 Gesture Sensor, gesture recognition function with general I2C interface into a single chip. It can recognize 9 gestures including move up, move down, move left, move right, etc. with a simple swipe of your hand.
(this sensor works with 3.3V)

for this project you need use HID (Human Interface Device) supporting Arduino. I used Digispark board.

Proper performance of this project depends on the timing.
For example, if you move your hand towards the sensor, it will read as forward and send a zoom in command. While executing this command, you must quickly move your hand away from the sensor, otherwise it will read as a backward and sends the zoom out command.

you can customize this times with delays and GES_REACTION_TIME , GES_QUIT_TIME in the code.

YouTube Video: https://youtu.be/BoA5tAtZOtc
