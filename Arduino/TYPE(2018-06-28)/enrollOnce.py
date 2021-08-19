import Tkinter as tk

class MyApp: # No need to inherit 'object' in Python 3
    def __init__(self, root):
        self.root = root

    def create_button(self):
        self.test_button = tk.Button(self.root,
                text="Example",
                command=self.delete_button)
        self.test_button.place(x=75, y=100)

    def delete_button(self):
        self.test_button.place_forget()

    def run(self):
        self.create_button()
        self.root.mainloop()


if __name__=='__main__':
    root = tk.Tk()
    app = MyApp(root)
    app.run()
