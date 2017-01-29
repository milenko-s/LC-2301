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
Sheet 3 7
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 2950 3400 0    60   Input ~ 0
RFOUT
Text HLabel 5450 3550 0    60   Input ~ 0
-LNA_ON
Text HLabel 3750 4250 3    60   Input ~ 0
RFIN
$Comp
L RAMP-33LN+ U2f
U 1 1 5891C406
P 3850 3550
F 0 "U2f" H 3450 4050 60  0000 C CNN
F 1 "RAMP-33LN+" H 4300 3200 60  0000 C CNN
F 2 "" H 3850 3550 60  0001 C CNN
F 3 "" H 3850 3550 60  0001 C CNN
	1    3850 3550
	1    0    0    -1  
$EndComp
$Comp
L TPS2024DR U1f
U 1 1 5891C507
P 6300 3350
F 0 "U1f" H 6300 3700 60  0000 C CNN
F 1 "TPS2024DR" H 6300 3100 60  0000 C CNN
F 2 "" H 6300 3350 60  0001 C CNN
F 3 "" H 6300 3350 60  0001 C CNN
	1    6300 3350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5891C5A0
P 3650 2900
F 0 "#PWR?" H 3650 2650 50  0001 C CNN
F 1 "GND" H 3650 2750 50  0000 C CNN
F 2 "" H 3650 2900 50  0001 C CNN
F 3 "" H 3650 2900 50  0001 C CNN
	1    3650 2900
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR?
U 1 1 5891C5D0
P 3950 2900
F 0 "#PWR?" H 3950 2650 50  0001 C CNN
F 1 "GND" H 3950 2750 50  0000 C CNN
F 2 "" H 3950 2900 50  0001 C CNN
F 3 "" H 3950 2900 50  0001 C CNN
	1    3950 2900
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR?
U 1 1 5891C66E
P 4450 3600
F 0 "#PWR?" H 4450 3350 50  0001 C CNN
F 1 "GND" H 4450 3450 50  0000 C CNN
F 2 "" H 4450 3600 50  0001 C CNN
F 3 "" H 4450 3600 50  0001 C CNN
	1    4450 3600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5891C73D
P 3850 4050
F 0 "#PWR?" H 3850 3800 50  0001 C CNN
F 1 "GND" H 3850 3900 50  0000 C CNN
F 2 "" H 3850 4050 50  0001 C CNN
F 3 "" H 3850 4050 50  0001 C CNN
	1    3850 4050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5891C755
P 3650 4050
F 0 "#PWR?" H 3650 3800 50  0001 C CNN
F 1 "GND" H 3650 3900 50  0000 C CNN
F 2 "" H 3650 4050 50  0001 C CNN
F 3 "" H 3650 4050 50  0001 C CNN
	1    3650 4050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5891C76D
P 3150 3600
F 0 "#PWR?" H 3150 3350 50  0001 C CNN
F 1 "GND" H 3150 3450 50  0000 C CNN
F 2 "" H 3150 3600 50  0001 C CNN
F 3 "" H 3150 3600 50  0001 C CNN
	1    3150 3600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5891C785
P 3150 3300
F 0 "#PWR?" H 3150 3050 50  0001 C CNN
F 1 "GND" H 3150 3150 50  0000 C CNN
F 2 "" H 3150 3300 50  0001 C CNN
F 3 "" H 3150 3300 50  0001 C CNN
	1    3150 3300
	0    1    1    0   
$EndComp
Text GLabel 3850 2700 1    60   Input ~ 0
LNA
Text GLabel 6750 3150 2    60   Input ~ 0
LNA
Text GLabel 5450 3250 0    60   Input ~ 0
VCC_RF
$Comp
L GND #PWR?
U 1 1 5891CB9B
P 5850 3150
F 0 "#PWR?" H 5850 2900 50  0001 C CNN
F 1 "GND" H 5850 3000 50  0000 C CNN
F 2 "" H 5850 3150 50  0001 C CNN
F 3 "" H 5850 3150 50  0001 C CNN
	1    5850 3150
	0    1    1    0   
$EndComp
NoConn ~ 6700 3450
$Comp
L R R1f
U 1 1 5891CD2B
P 5550 3400
F 0 "R1f" V 5630 3400 50  0000 C CNN
F 1 "10k" V 5550 3400 50  0000 C CNN
F 2 "" V 5480 3400 50  0001 C CNN
F 3 "" H 5550 3400 50  0001 C CNN
	1    5550 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 2950 3650 2950
Wire Wire Line
	3650 2950 3650 2900
Wire Wire Line
	3950 2950 3950 2900
Wire Wire Line
	4400 3300 4400 3600
Connection ~ 4400 3500
Connection ~ 4400 3400
Wire Wire Line
	4400 3600 4450 3600
Connection ~ 4400 3600
Wire Wire Line
	3650 4000 3650 4050
Wire Wire Line
	3950 4000 3850 4000
Wire Wire Line
	3850 4000 3850 4050
Connection ~ 3850 4000
Wire Wire Line
	3200 3600 3150 3600
Wire Wire Line
	3200 3300 3150 3300
Wire Wire Line
	3750 4250 3750 4000
Wire Wire Line
	3200 3400 2950 3400
Wire Wire Line
	3200 3500 3200 3600
Connection ~ 3200 3600
Connection ~ 3650 2950
Wire Wire Line
	3850 2950 3850 2700
Wire Wire Line
	5900 3150 5850 3150
Wire Wire Line
	6700 3150 6750 3150
Wire Wire Line
	6700 3150 6700 3350
Connection ~ 6700 3250
Wire Wire Line
	5900 3250 5900 3350
Wire Wire Line
	5900 3550 5900 3450
Wire Wire Line
	5450 3550 5900 3550
Connection ~ 5550 3550
Wire Wire Line
	5450 3250 5900 3250
Connection ~ 5550 3250
Connection ~ 5900 3250
Connection ~ 6700 3150
$EndSCHEMATC
