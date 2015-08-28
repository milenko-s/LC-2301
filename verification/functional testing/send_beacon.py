# -*- coding: utf-8 -*-
# ---------------------------------------
# LibreCube LC-2301a Communication System
# Script for sending a beacon
# ---------------------------------------                                                                 
# Last update: 2014-12-23

import serial
import platform
import time

# Global configuration --------------------------------------------------------
serialPortWindows = "COM1"  # on Windows
serialPortLinux = "/dev/ttyUSB1"  # on Linux

zero = chr(0x00)
ones = chr(0xFF)
beacon = 50 * zero + 50 * ones + 50 * zero + 50 * ones

def main(): 
    if platform.system() == 'Windows':
        ser = serial.Serial(serialPortWindows) 
    else:
        ser = serial.Serial(serialPortLinux) 
           
    while True:
        try:    
            print("Sending beacon: "+ beacon)                                
            ser.write(beacon)             
            time.sleep(2) # wait                 
        except KeyboardInterrupt:
            break          
    ser.flush()
    ser.close()

main()
