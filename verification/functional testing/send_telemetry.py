# ---------------------------------------
# LibreCube LC23-01a Communication System
# Script for sending telemetry
# ---------------------------------------                                                                 
# Last update: 2014-07-10

import serial
import platform
import time

# Global configuration --------------------------------------------------------
serialPortWindows = "COM1"  # on Windows
serialPortLinux = "/dev/ttyUSB1"  # on Linux

asm = "\x1a\xcf\xfc\x1d"
message = "\n\rGreetings, Earthlings! The Alien attack has just begun!\n\r"
cadu = (asm + message)

def main(): 
    if platform.system() == 'Windows':
        ser = serial.Serial(serialPortWindows) 
    else:
        ser = serial.Serial(serialPortLinux) 
           
    while True:
        try:    
            print("Sending...")                                
            ser.write(cadu)             
            time.sleep(0.4) # wait                 
        except KeyboardInterrupt:
            break          
    ser.flush()
    ser.close()

main()
