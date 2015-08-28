# LibreCube LC-2301 Communication System

## About

Half-duplex communication system for UHF band operation with radio output power of up to 31 dBm (>1 W). The output power, as well as the frequency and frequency separation are user-programmable, allowing large flexibility in operation. The device includes a beacon function that sends out a user-defined message in Morse code at adjustable keying speed, useful for satellite tracking and identification. The heart of the device is the establishment of a space link via ECSS/CCSDS compliant telecommand and telemetry frames (more correctly, CLTUs and CADUs, respectively). Beacon and telemetry frames are created and transmitted whenever such data is written to the device from an external device. Incoming telecommand frames are buffered in the device's memory, for successive read out from an external device. The physical layer of the space link uses FSK modulation at a data rate of 1200 bps (user-programmable). Further, a mechanism to support antenna deployment is included.

## Authors

- Artur Scholz [artur.scholz@librecube.net]
- Jesus Sanchez []

## Acknowledgements

- Development supported from National Cheng Kung University (www.ncku.edu.tw) under supervision of Prof. Jiun-Jih Miau and Prof. Jyh-Ching Juang and with the help from students of PACELAB and MECLAB.
