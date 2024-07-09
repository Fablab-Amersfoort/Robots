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
                     12V   GND   5V  EN  IN  IN  IN  IN  EN
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
