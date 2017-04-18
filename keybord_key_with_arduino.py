'''
Created on 2011-12-02

@author: Bobby Wood
'''
from pynput.keyboard import Key, Listener
## import the serial library
import serial

ser = serial.Serial('/dev/ttyUSB0', 250000)
connected = False

while not connected:
    serin = ser.read()
    print("ready")
    connected = True
    
last_pressed=Key.backspace

def on_press(key):
    global last_pressed
    ##print('{0} pressed'.format(key))
    if key==Key.up and last_pressed!=Key.up:
        ser.write('1') 
        last_pressed=Key.up
        print(1)
    elif key==Key.down and last_pressed!=Key.down:
        ser.write('2')
        last_pressed=Key.down
        print(2)
    elif key==Key.left and last_pressed!=Key.left:
        ser.write('3')
        last_pressed=Key.left
        print(3)
    elif key==Key.right and last_pressed!=Key.right:
        ser.write('4')
        last_pressed=Key.right
        print(4)
    elif key==Key.space:
        ser.write('0')
        last_pressed=Key.space

def on_release(key):
    global last_pressed
    last_pressed=Key.backspace
    print('{0} released'.format(key))
    ser.write('0')
    if key == Key.esc: 
        # Stop listener
        ser.close()
        return False



with Listener(
        on_press=on_press,
        on_release=on_release) as listener:
    listener.join()






