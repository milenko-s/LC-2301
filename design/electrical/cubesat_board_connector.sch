EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:74xgxx
LIBS:ac-dc
LIBS:actel
LIBS:allegro
LIBS:Altera
LIBS:analog_devices
LIBS:battery_management
LIBS:bbd
LIBS:bosch
LIBS:brooktre
LIBS:cmos_ieee
LIBS:dc-dc
LIBS:diode
LIBS:elec-unifil
LIBS:ESD_Protection
LIBS:ftdi
LIBS:gennum
LIBS:graphic
LIBS:hc11
LIBS:ir
LIBS:Lattice
LIBS:logo
LIBS:maxim
LIBS:mechanical
LIBS:microchip_dspic33dsc
LIBS:microchip_pic10mcu
LIBS:microchip_pic12mcu
LIBS:microchip_pic16mcu
LIBS:microchip_pic18mcu
LIBS:microchip_pic32mcu
LIBS:motor_drivers
LIBS:motors
LIBS:msp430
LIBS:nordicsemi
LIBS:nxp_armmcu
LIBS:onsemi
LIBS:Oscillators
LIBS:Power_Management
LIBS:powerint
LIBS:pspice
LIBS:references
LIBS:relays
LIBS:rfcom
LIBS:sensors
LIBS:silabs
LIBS:stm8
LIBS:stm32
LIBS:supertex
LIBS:switches
LIBS:transf
LIBS:ttl_ieee
LIBS:video
LIBS:wiznet
LIBS:Worldsemi
LIBS:Xicor
LIBS:zetex
LIBS:Zilog
LIBS:as193-73
LIBS:is62wv5128bll-55tli-tr
LIBS:tps2024dr
LIBS:max893l
LIBS:ref3130
LIBS:ramp-33ln+
LIBS:sky65116
LIBS:c8051f120
LIBS:sma
LIBS:communication_system-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 7
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 5800 4300 2    60   Input ~ 0
VBAT
Text HLabel 5100 3400 0    60   Input ~ 0
+3.3V
Text HLabel 4650 3500 0    60   Input ~ 0
DGND
Text HLabel 5150 3600 0    60   Input ~ 0
AGND
Text HLabel 3100 3500 0    60   Input ~ 0
-RESET
Text HLabel 3100 4100 0    60   Input ~ 0
SDA0
Text HLabel 3100 4200 0    60   Input ~ 0
SCL0
Text HLabel 3100 4000 0    60   Input ~ 0
TX0
Text HLabel 3700 4000 2    60   Input ~ 0
RX0
$Comp
L CONN_02X26 P1b
U 1 1 58921EB4
P 3400 3350
F 0 "P1b" H 3400 4700 50  0000 C CNN
F 1 "CONN_02X26" V 3400 3350 50  0000 C CNN
F 2 "" H 3400 2650 50  0001 C CNN
F 3 "" H 3400 2650 50  0001 C CNN
	1    3400 3350
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X26 P2b
U 1 1 58921F23
P 5450 3350
F 0 "P2b" H 5450 4700 50  0000 C CNN
F 1 "CONN_02X26" V 5450 3350 50  0000 C CNN
F 2 "" H 5450 2650 50  0001 C CNN
F 3 "" H 5450 2650 50  0001 C CNN
	1    5450 3350
	1    0    0    -1  
$EndComp
NoConn ~ 3650 4600
NoConn ~ 3650 4500
NoConn ~ 3650 4400
NoConn ~ 3650 4300
NoConn ~ 3650 4200
NoConn ~ 3650 4100
NoConn ~ 3150 4600
NoConn ~ 3150 4500
NoConn ~ 3150 4400
NoConn ~ 3150 4300
NoConn ~ 3150 3900
NoConn ~ 3150 3800
NoConn ~ 3150 3700
NoConn ~ 3150 3600
NoConn ~ 3650 3900
NoConn ~ 3650 3800
NoConn ~ 3650 3700
NoConn ~ 3650 3600
NoConn ~ 3650 3500
NoConn ~ 3650 3400
NoConn ~ 3650 3300
NoConn ~ 3650 3200
NoConn ~ 3150 3400
NoConn ~ 3150 3300
NoConn ~ 3150 3200
NoConn ~ 3150 3100
NoConn ~ 3150 3000
NoConn ~ 3150 2900
NoConn ~ 3150 2600
NoConn ~ 3150 2700
NoConn ~ 3150 2800
NoConn ~ 3650 3100
NoConn ~ 3650 3000
NoConn ~ 3650 2900
NoConn ~ 3650 2800
NoConn ~ 3650 2700
NoConn ~ 3650 2600
NoConn ~ 3150 2500
NoConn ~ 3150 2400
NoConn ~ 3150 2300
NoConn ~ 3150 2200
NoConn ~ 3150 2100
NoConn ~ 3650 2100
NoConn ~ 3650 2200
NoConn ~ 3650 2300
NoConn ~ 3650 2400
NoConn ~ 3650 2500
Wire Wire Line
	3100 3500 3150 3500
Wire Wire Line
	3100 4000 3150 4000
Wire Wire Line
	3100 4100 3150 4100
Wire Wire Line
	3100 4200 3150 4200
Wire Wire Line
	3650 4000 3700 4000
Wire Wire Line
	5700 4300 5800 4300
Wire Wire Line
	5750 4300 5750 4700
Wire Wire Line
	5750 4700 5150 4700
Wire Wire Line
	5150 4700 5150 4300
Wire Wire Line
	5150 4300 5200 4300
Connection ~ 5750 4300
Wire Wire Line
	5200 3400 5100 3400
Wire Wire Line
	5150 3400 5150 1950
Wire Wire Line
	5150 1950 5750 1950
Wire Wire Line
	5750 1950 5750 3400
Wire Wire Line
	5750 3400 5700 3400
Connection ~ 5150 3400
Wire Wire Line
	5700 3600 5750 3600
Wire Wire Line
	5750 3600 5750 3500
Wire Wire Line
	5700 3500 5800 3500
Wire Wire Line
	5800 3500 5800 1900
Wire Wire Line
	5800 1900 4700 1900
Wire Wire Line
	4700 1900 4700 3500
Wire Wire Line
	4650 3500 5200 3500
Connection ~ 5750 3500
Connection ~ 4700 3500
NoConn ~ 5200 4400
NoConn ~ 5200 4500
NoConn ~ 5200 4600
NoConn ~ 5700 4600
NoConn ~ 5700 4500
NoConn ~ 5700 4400
NoConn ~ 5200 3700
NoConn ~ 5200 3800
NoConn ~ 5200 3900
NoConn ~ 5200 4000
NoConn ~ 5200 4100
NoConn ~ 5200 4200
NoConn ~ 5700 4200
NoConn ~ 5700 4100
NoConn ~ 5700 4000
NoConn ~ 5700 3900
NoConn ~ 5700 3800
NoConn ~ 5700 3700
NoConn ~ 5200 3300
NoConn ~ 5200 3200
NoConn ~ 5200 3100
NoConn ~ 5200 3000
NoConn ~ 5200 2900
NoConn ~ 5200 2800
NoConn ~ 5200 2700
NoConn ~ 5200 2600
NoConn ~ 5200 2400
NoConn ~ 5200 2500
NoConn ~ 5700 2400
NoConn ~ 5700 2500
NoConn ~ 5700 2600
NoConn ~ 5700 2700
NoConn ~ 5700 2800
NoConn ~ 5700 2900
NoConn ~ 5700 3000
NoConn ~ 5700 3100
NoConn ~ 5700 3200
NoConn ~ 5700 3300
NoConn ~ 5200 2100
NoConn ~ 5200 2200
NoConn ~ 5200 2300
NoConn ~ 5700 2300
NoConn ~ 5700 2200
NoConn ~ 5700 2100
$EndSCHEMATC
