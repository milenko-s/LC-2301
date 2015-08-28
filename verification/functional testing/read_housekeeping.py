# ------------------------------------------------------------------------------
# LibreCube LC-2301a Communication System
# Script for reading housekeeping parameter 
# ------------------------------------------------------------------------------ 
# Last update: 2014-12-23
# 
# To do:
#        - improve selection of parameters to be displayed
#        - stop script when closing the window

import serial
from collections import deque
from matplotlib import pyplot as plt
import time
import platform

# Global configuration --------------------------------------------------------
SERIAL_PORT_WINDOWS = "COM10"  # on Windows
SERIAL_PORT_LINUX = "/dev/ttyUSB1"  # on Linux
I2C_ADR = 0x13  # i2c address of device
I2C_READ = 0x01 # opcode for i2c read
X_AXIS_SIZE = 200  # length of plot
Y_AXIS_SIZE = 2500  # height of plot
PORT_TIMEOUT = 500 # timeout in 10 msec for waiting for serial port response (i.e. 2 sec)

# Parameters to be read --------------------------------------------------------
# parTitle = "Flags"  
# parLabel = ["Flags"] 
# parList = [[0x0D]]  
# parTitle = "Temperatures & RSSI"  
# parLabel = ["MCU","HPA","RSSI"]
# parList = [[0x0E,0x0F],[0x10,0x11],[0x12,0x13]]     
parTitle = "TC and TM Byte Counter"  
parLabel = ["TC Byte Counter","TM Byte Counter"] 
parList = [[0x14,0x15],[0x17,0x18]] 

# Classes ----------------------------------------------------------------------
class DataModel:

    def __init__(self, xAxisSize, dataSets):
        self.buffer = [deque([0.0] * xAxisSize) for n in range(dataSets)]
        self.xAxisSize = xAxisSize
        self.dataSets = dataSets

    def add(self, newDataSet):
        for n in range(self.dataSets):
            if len(self.buffer[n]) < self.xAxisSize:  # if data buffer is yet smaller than plot size
                self.buffer[n].append(newDataSet[n])  # then append new data from left
            else:
                self.buffer[n].pop()  # otherwise remove oldest entry (right side)
                self.buffer[n].appendleft(newDataSet[n])  # and add new data to left
  
class DataViewer:

    def __init__(self, dataModel):
        plt.ion()  # define as interactive plot; show changes
        self.yLine = [0 for n in range(dataModel.dataSets)]
        for n in range(dataModel.dataSets):
            self.yLine[n], = plt.plot([float(val) for val in dataModel.buffer[n]], label=parLabel[n])            
        plt.ylim([0, Y_AXIS_SIZE])  # y range of values
        plt.legend()
        plt.title(parTitle)

    def update(self, dataModel):
        for n in range(dataModel.dataSets):
            self.yLine[n].set_ydata([float(val) for val in dataModel.buffer[n]])
        plt.draw()
        plt.pause(0.01) # this is needed, otherwise the plot freezes

    def close(self):
        plt.close()

class DataController:

    def __init__(self):
        if platform.system() == 'Windows':
            self.ser = serial.Serial(SERIAL_PORT_WINDOWS) 
        else:
            self.ser = serial.Serial(SERIAL_PORT_LINUX)                    
        
    def update(self, parList): 
        bufferArray = [0 for n in range(len(parList))]
        for n in range(len(parList)):
            cmdString = chr((I2C_ADR << 1) + I2C_READ) + chr(parList[n][0]) # read cmd and reg to be read      
            self.ser.write(cmdString)         
            buffer = 0 # reset buffer
            timeout = PORT_TIMEOUT 
            while self.ser.inWaiting() == 0: # wait for response from serial port
                time.sleep(0.01) # small delay
                timeout = timeout - 1
                if (timeout == 0):
                    print("Error: Serial port is not responding!")
                    exit()                             
            buffer = ord(self.ser.read())               
            
            if len(parList[n]) > 1:  # if it is a 2 byte parameter  
                cmdString = chr((I2C_ADR << 1) + I2C_READ) + chr(parList[n][1]) # read cmd and reg to be read 
                self.ser.write(cmdString)
                timeout = PORT_TIMEOUT
                while self.ser.inWaiting() == 0:
                    time.sleep(0.01) # small delay
                    timeout = timeout - 1
                    if (timeout == 0):
                        print("Error: Serial port is not responding!")
                        exit() 
                buffer = buffer + 256 * ord(self.ser.read())                
            
            bufferArray[n] = buffer
            
        print(bufferArray)  # show on console    
        return bufferArray
        
    def close(self):
        self.ser.flush()
        self.ser.close()

def main():
    
    dataModel = DataModel(X_AXIS_SIZE, len(parList))
    dataViewer = DataViewer(dataModel)
    dataController = DataController()
    
    while True:                                 
        dataModel.add(dataController.update(parList))
        dataViewer.update(dataModel)                        
       
    dataController.close()
    dataViewer.close()

main()
