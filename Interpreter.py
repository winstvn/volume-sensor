import serial
import time
import pyautogui

ArduinoSerial = serial.Serial('com3', 9600)
time.sleep(2)  # wait for 2 seconds for the communication to get established

while 1:

    incoming = str(ArduinoSerial.readline())
    #print(incoming)

    if 'Play/Pause' in incoming:
        pyautogui.typewrite(['playpause'], 0.2)
        print("Play/Pause")

    if 'Vup' in incoming:
        pyautogui.hotkey('volumeup')
        print("Vol Up")

    if 'Vdown' in incoming:
        pyautogui.hotkey('volumedown')
        print("Vol Down")

    if 'NextSong' in incoming:
        pyautogui.hotkey('nexttrack')
        print("Next Track")

    incoming = ""
