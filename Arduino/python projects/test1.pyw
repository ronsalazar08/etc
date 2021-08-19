from tkinter import *

root = Tk()

lbl_1 = Label(root, text="Username:")
lbl_2 = Label(root, text="Password:")
entry_1 = Entry(root)
entry_2 = Entry(root)


lbl_1.grid(row=0, sticky=E)
lbl_2.grid(row=1, sticky=E)

entry_1.grid(row=0, column=1)
entry_2.grid(row=1, column=1)

root.mainloop()