This Arduino sketch uses the LDR and motor libraries to set up a line follower robot.
The sketch uses the following connections:

pin    description
2      IN1 motor controller
3      IN2 motor controller
4      IN3 motor controlle
5      IN4 motor controller
9      ENA motor controller (PWM left motor)
10     ENB motor controller (PWM right motor)
12     Illumination LED on front of robot
13     Indicator LED
A0     LDR left
A1     LDR right
A5     Button to step through test modes (pullup to 5V)

When started up, the sketch starts in mode 0: all LEDS off, motor controller off.
Pressing the key steps through the following modes:

mode    description
0       default mode
1       blink indicator LED
2       test left LDR (indicator LED lights when light detected)
3       test right LDR (indicator LED lights when light detected)
4       test left motor (forward then reverse)
5       test right motor (forward then reverse)
6       test both motors (forward)
7       test both motors (reverse)
8       test both motors (forward then reverse)
9       step to default mode
