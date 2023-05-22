import serial
import time
arduino = serial.Serial(port='COM3', baudrate=9600, timeout=1)

while True:
    # Taking input from user
    value =arduino.readline().decode("utf-8")
    print(value) # printing the value
    
    if value.strip() == "1":
        status = input("enter status: ")
        arduino.write(bytes(status, 'utf-8'))
        time.sleep(0.05)
    
    
        
