# Drishti-Buzzer
INTRODUCTION:

A buzzer system is designed for quiz game’s having buzzer rounds. The project consists of multiple buzzer one for each player and a central computer which receives data from each of these buzzers and determines which buzzer’s button was pressed first for a particular question. The central computer displays a GUI (graphical user interface) depicting various questions like which teams turn is it to answer ,each teams score and other such information.

HARDWARE AND WORKING:

4 buzzers were made using touch pads(ne555 ic in bistable mode).The BUZZERS were connected to the central microcontroller(ATMega 128) with rainbow wires.The HC05 bluetooth module was used to transmit data from the central microcontroller to laptop.The GUI was developed using python.In ATMega 128, to be precise, 3*4+2+2=18 pins( VCC per buzzer , GND per buzzer, EXT Interrupt per buzzer, GPIO per buzzer, RXD for HC05,TXD for HC05) were used .4 PINS per buzzer’s GCB: 1 for VCC, 1 for GND, 1 for O/P feedback to MCU (EXT INTERRUPT of MCU), 1 for RESET (GPIO PIN of MCU).Whenever a TRIGGER is given (touchpad is touched), the O/P becomes one. This is send to the EXT INT of MCU.This data(which EXT INT is 1) is sent to the central computer with the use of wires then it is sent to the laptop via bluetooth.These data are saved in a document of GUI.After the completion of a question, a RESET is send to central MCU using HC05. And this data is then sent to the BUZZERS. So, the buzzer resets.
