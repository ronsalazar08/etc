# topFrame = Frame(root)
# topFrame.pack()
#
#
# bottomFrame = Frame(root)
# bottomFrame.pack(side=BOTTOM)
#
# button1 = Button(topFrame, text="one", bg="Blue")
#
# button2 = Button(topFrame, text="two", fg='Blue')
# button3 = Button(topFrame, text="three")
# button4 = Button(bottomFrame, text="four")
# button5 = Button(bottomFrame, text="five")
#
# button1.pack(side=LEFT)
# button2.pack(side=LEFT)
# button3.pack(side=LEFT)
# button4.pack()
# button5.pack(side=TOP)

# button class
# class App:
#     def __init__(self, root: object):
#         self.root = root
#         self.mouse_pressed = False
#         self.root.bind("<ButtonPress-1>", self.OnMouseDown)
#         self.root.bind("<ButtonRelease-3>", self.OnMouseUp)
#         self.btn = Button(root, text="SUBMIT", fg="White", bg="Blue", activebackground='Green',
#                           activeforeground='White')
#         self.btn.config(font=("Tahoma", 16, 'bold'), height=1, width=15)
#         self.btn.pack()
#
#     def do_work(self):
#         if self.mouse_pressed:
#             self.btn.bind("<Enter>", lambda event, h=self.btn: h.configure(bg="White", fg="Blue"))
#             self.btn.bind("<Leave>", lambda event, h=self.btn: h.configure(fg="White", bg="Blue"))
#
#
#         else:
#             self.btn.unbind("<Enter>")
#             self.btn.unbind("<Leave>")
#
#     def OnMouseDown(self, event):
#         self.mouse_pressed = True
#         self.do_work()
#
#     def OnMouseUp(self, event):
#         self.mouse_pressed = False
#         self.do_work()
#
#
# app = App(root)


from tkinter import *
from datetime import date
import time
import ctypes

root = Tk()
root.attributes('-fullscreen', True)
root.config(bg="White")


def close_window():
    root.destroy()


button = Button(text="X", bg="Red", fg="White", command=close_window)
button.config(font=("Tahoma", 24, 'bold'))
image = PhotoImage(file='logo.gif')
logo = Label(image=image)
logo.config(bg='White')
logo.pack(side = TOP)
button.pack(side = RIGHT)
logoLbl = Label(root, text="TORRES TECHNOLOGY CENTER CORPORATION", fg="Red", bg="White")
logoLbl.config(font=("Times New Roman", 36, 'bold'))
logoLbl.pack()

today = date.today()
day = Label(root, text=today.strftime('%B %d, %Y'), bg="White")
day.config(font=("Tahoma", 24, 'bold'))
day.pack()

clock = Label(root, bg="White", fg="Blue", bd = "5", relief="flat")
clock.config(font=("Verdana", 60, 'bold'))
clock.pack()

def tick():
    s = time.strftime('%H:%M:%S')
    if s != clock["text"]:
        clock["text"] = s
    clock.after(200, tick)


tick()

root.mainloop()
