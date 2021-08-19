#!/usr/bin/env python
import tkMessageBox
from Tkinter import *
import subprocess as sp


def closewindow(event=None):
    sp.Popen(['python','test.py'])
    Messagebox.destroy()


Messagebox=Tk()
Messagebox.title(" ")
w = 200 # width for the Tk root
h = 110 # height for the Tk root

# get screen width and height
ws = Messagebox.winfo_screenwidth() # width of the screen
hs = Messagebox.winfo_screenheight() # height of the screen

# calculate x and y coordinates for the Tk root window
x = (ws/2) - (w/2)
y = (hs/2) - (h/2)

# set the dimensions of the screen 
# and where it is placed

msg = '''Stored!'''

Messagebox.geometry('%dx%d+%d+%d' % (w, h, x, y))
l3=Label( Messagebox, text=msg)
l3.config(font=("Tahoma", 11, 'bold'))
b3=Button(Messagebox, text="Okay", command=closewindow)
l3.place(relx=.5, rely=.3, anchor="c")
b3.place(relx=.5, rely=.8, anchor="c")
b3.bind('<Return>', lambda _: closewindow())
b3.focus_set()



Messagebox.mainloop()
