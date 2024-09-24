# FABLAB Motor Module
## for use in Arduino sketches

### HARDWARE

This module uses a L298N H-bridge module to connect up to two motors:

Module layout:

---
```
                 ##############COOLING FAN #################
                 ##############COOLING FAN #################
                 ##############COOLING FAN #################
                 ##############L298N module#################
 Output A - 1    #-----------------------------------------# Output B - 1
 Output A - 2    #-----------------------------------------# Output B - 1
                 #-----Jumper 1----------------------------#
                 #-----------------------------------------#
                 #-------------------GND-----------------GND
                    5-35V  GND   5V  EN  IN  IN  IN  IN  EN
                     in          in  A   1   2   3   4   B
```
---
### Connections:
The standard connections to arduino as used in the examples are as follows:
* ENA -> Arduino digital pin 9
* IN1 -> Arduino digital pin 2
* IN2 -> Arduino digital pin 3
* IN3 -> Arduino digital pin 4
* IN4 -> Arduino digital pin 5
* ENB -> Arduino digital pin 10

The motor controller can be used with a DC voltage between 5 and 35 volts, which is fed to the motor.

When the jumper is installed, it enables the 5V regulator, which can be used to power both the arduino as the motor controller.
In this case power from the arduino is proviced by connecting the GND and 5V to the Arduino.

When the jumper is NOT installed, the motor controller must be provided with both power for the motor and a separate 5V for the controller.