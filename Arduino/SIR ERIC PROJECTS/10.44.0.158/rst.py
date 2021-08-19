#!/usr/bin/env python

from Tkinter import *
import subprocess as sp
import time
root=Tk()
root.title(" ")
w = 200 # width for the Tk root
h = 110 # height for the Tk root

# get screen width and height
ws = root.winfo_screenwidth() # width of the screen
hs = root.winfo_screenheight() # height of the screen

# calculate x and y coordinates for the Tk root window
x = (ws/2) - (w/2)
y = (hs/2) - (h/2)

# set the dimensions of the screen 
# and where it is placed

root.geometry('%dx%d+%d+%d' % (w, h, x, y))
time.sleep(1)
sp.Popen(['python','test.py'])
root.destroy()
root.mainloop()
