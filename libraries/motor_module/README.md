FABLAB Motor Module
for use in Arduino sketches

HARDWARE

This module uses a L298N H-bridge module to connect up to two motors:

Module layout:

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
