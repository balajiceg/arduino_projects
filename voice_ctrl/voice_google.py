'''
Created on 2011-12-02

@author: Bobby Wood
'''

#!/usr/bin/env python3

# NOTE: this example requires PyAudio because it uses the Microphone class

import speech_recognition as sr
import serial

ser = serial.Serial("COM3", 250000)
connected = False

while not connected:
    serin = ser.read()
    print("ready")
    connected = True
while True:
    # obtain audio from the microphone
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Say something!")
        audio = r.listen(source)

    # recognize speech using Sphinx
    try:
        s=r.recognize_google(audio)
        print("Google thinks you said " + s)
        if "go" in s:
            ser.write("1")
        elif "stop" in s:
            ser.write("0");
    except sr.UnknownValueError:
        print("Google could not understand audio")
    except sr.RequestError as e:
        print("Google error; {0}".format(e))
