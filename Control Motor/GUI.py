from tkinter import *
import serial
import win32api

ventana = Tk()
ventana.geometry("300x200")
ventana.title('CONTROL DE LAMPARA')
# arduino = serial.Serial('COM3', 9600)

def Horario():
    # arduino.write('a')
    win32api.MessageBox(0, 'Horario', 'title')

def AntiHorario():
    # arduino.write('b')
    win32api.MessageBox(0, 'AntiHorario', 'title')

def Parar():
    # arduino.write('c')
    win32api.MessageBox(0, 'Parar', 'title')

def Mas():
    # arduino.write('d')
    win32api.MessageBox(0, 'Mas', 'title')

def Menos():
    # arduino.write('e')
    win32api.MessageBox(0, 'Menos', 'title')

label = Label(ventana)
label.pack()

name = Label(text = 'Control de Motor').place(x=110, y=20)

Horario = Button(text='Horario', command=Horario).place(x=80, y=50)
AntiHorario = Button(text='AntiHorario', command=AntiHorario).place(x=160, y=50)
Parar = Button(text='Parar', command=Parar).place(x=120, y=90)
Mas = Button(text='Mas', command=Mas).place(x=80, y=130)
Menos = Button(text='Menos', command=Menos).place(x=160, y=130)

ventana.mainloop()
