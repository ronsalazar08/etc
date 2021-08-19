#!/usr/bin/env python
import serial

from pynput.keyboard import Key, Controller
keyboard = Controller()
ser = serial.Serial('/dev/ttyUSB0',9600)
#def type():
s = None
while True: 
	s = str(ser.readline().decode().strip('\r\n'))
	keyboard.type(s)
	keyboard.press(Key.enter)
	keyboard.release(Key.enter)
