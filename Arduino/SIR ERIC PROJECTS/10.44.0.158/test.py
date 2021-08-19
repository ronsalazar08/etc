#!/usr/bin/env python

from Tkinter import *
import os
import time
import subprocess as sp
import signal
import serial
import tkMessageBox
from pynput.keyboard import Key, Controller
keyboard = Controller()

ser = serial.Serial('/dev/ttyUSB0',9600)

root = Tk()
root.title(" ")
#root.attributes('-fullscreen', False)
#root.geometry("500x500") #You want the size of the app to be 500x500
w = 500 # width for the Tk root
h = 400 # height for the Tk root

# get screen width and height
ws = root.winfo_screenwidth() # width of the screen
hs = root.winfo_screenheight() # height of the screen

# calculate x and y coordinates for the Tk root window
x = (ws/2) - (w/2)
y = (hs/2) - (h/2)

# set the dimensions of the screen 
# and where it is placed
#root.overrideredirect(1)
root.geometry('%dx%d+%d+%d' % (w, h, x, y))
root.resizable(0, 0) #Don't allow resizing in the x or y direction
root.config(bg="whitesmoke")

ment =StringVar()
def rst():
	#ser.close()
	#time.sleep(.5)
	#ser.open()
	ser.setDTR(False)
	time.sleep(.5)
	ser.setDTR(True)
	sp.Popen(['python','rst.py'])
	time.sleep(.3)
	root.destroy()

def openType():
    #os.system('python seria_test.py')
    ser.write('2')
    proc = sp.Popen(['python','seria_test.py'])
    global pid1
    pid1 = proc.pid
    return pid1
    
	
pid1 = openType()
def openEnroll():
	button.place_forget()
	os.kill(pid1, signal.SIGKILL)
	ser.write('1')
	lbl = Label(root, text = "Enter Trace No.", bg="White")
	lbl.config(font=("Tahoma", 15, 'bold'))
	lbl.place(relx=.5, rely=.2, anchor="c")
	txtBox = Entry(root, textvariable=ment, justify='center')
	txtBox.config(font=("Tahoma", 20, 'bold'))
	txtBox.place(relx=.5, rely=.3, anchor="c")
	txtBox.focus()
	submit= Button(text="Submit", bg="Red", fg="White", command=pasa)
	submit.config(font=("Tahoma", 15, 'bold'))
	submit.place(relx=.5, rely=.4, anchor="c")
	button1 = Button(text="Cancel", bg="Blue", fg="White", command=rst)
	button1.config(font=("Tahoma", 24, 'bold'))
	button1.place(relx=.5, rely=.9, anchor="c")
	#button.pack(side = RIGHT)
	
def pasa():
	ser.write(ment.get())
	proc1 = sp.Popen(['python','msgbox.py'])
	s = None
	while (s != "Remove finger"):
		s = str(ser.readline().decode().strip('\r\n'))
	if s == "Remove finger":
		keyboard.press(Key.space)
		keyboard.release(Key.space)
	proc2 = sp.Popen(['python','removeFbox.py'])
	s2 = None
	while (s2 != "Stored!"):
		s2 = str(ser.readline().decode().strip('\r\n'))
	if s2 == "Stored!":
		keyboard.press(Key.space)
		keyboard.release(Key.space)
		proc3 = sp.Popen(['python','stored.py'])
	time.sleep(1.5)
	root.destroy()
	'''
	time.sleep(3)
	proc = sp.Popen(['python','seria_test.py'])
	global pid1
	pid1 = proc.pid	
	'''
	
button = Button(text="Enroll", bg="Red", fg="White", command=openEnroll)
button.config(font=("Tahoma", 24, 'bold'))
button.place(relx=.5, rely=.5, anchor="c")
#button.pack(side = RIGHT)
def doSomething():
    os.kill(pid1, signal.SIGKILL)
    root.destroy()

root.protocol('WM_DELETE_WINDOW', doSomething)

root.mainloop()
