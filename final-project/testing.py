import serial
import time

#windows - make sure matches the com port in the Arduino IDE
ser = serial.Serial('/dev/cu.usbmodem2101', 115200, timeout=.1)
ser2 = serial.Serial('/dev/cu.usbmodem11101', 115200, timeout=.1)

#mac - - make sure matches the com port in the Arduino IDE
#ser = serial.Serial('/dev/cu.usbmodem21401', 9600, timeout=.1)
def read_uart():
    value = ser.readline().decode('utf-8').strip()
    if value == "START":
        print("Code from Arduino: " + str(value))
        ser2.write(b'S')
        read_reaction()
    else:
        read_uart()

def read_reaction():
    value2 = ser2.readline().decode('utf-8').strip()
    if value2 == "TIME":
        reaction = ser2.readline().decode('utf-8').strip()
        print("Reaction time: " + str(reaction))
        read_uart()
    else:
        read_reaction()


read_uart()