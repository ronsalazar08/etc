#!/usr/bin/python
from Tkinter import *
from datetime import date
import time

root = Tk()
root.attributes('-fullscreen', True)
root.config(bg="White")
image = PhotoImage(file='logo.gif')
logo = Label(image=image)
logo.config(bg='White')
logo.pack()


logoLbl = Label(root, text="TORRES TECHNOLOGY CENTER CORPORATION", fg="Red", bg="White")
logoLbl.config(font=("Times New Roman", 36, 'bold'))
logoLbl.pack()

today = date.today()
day = Label(root, text= today.strftime('%B %d, %Y'), bg="White")
day.config(font=("Tahoma", 36, 'bold'))
day.pack()

clock = Label(root, bg="White", fg="Blue")
clock.config(font=("Verdana", 90, 'bold'))
clock.pack()
def tick():
    s = time.strftime('%H:%M:%S')
    if s != clock["text"]:
        clock["text"] = s
    clock.after(200, tick)
tick()



root.mainloop()
