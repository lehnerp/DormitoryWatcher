import serial
import urllib.request
import time

if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
    ser.flush()

    while True:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').rstrip()
            print(line)
            x = line.split()
            APIkey=''
            b = urllib.request.urlopen('https://api.thingspeak.com/update?api_key=' + APIkey + '&field1=' + x[4] + '&field2='+ x[1])
            time.sleep(60)
