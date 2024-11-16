import serial
import time
stm = serial.Serial(port='COM3', baudrate=115200, parity=serial.PARITY_NONE, stopbits=serial.STOPBITS_ONE, bytesize=serial.EIGHTBITS, timeout=0)

while True:
    #msg = input("mesaj gir: ")
    #if msg != "":

    if stm.in_waiting:
       stm_veri = stm.readline()
       stm_veri = stm_veri.decode('utf')
       print(stm_veri)

        #msg_with_null = msg + '\0'
        #stm.write(msg_with_null.encode("utf-8"))
        #msg = ""
        #msg_with_null = ""

        # Cevabı beklemek için biraz zaman tanı
        #time.sleep(0.1)
        
        # Gelen cevabı oku
        #response = b""
        #while True:
            #char = stm.read(1)  # 1 byte oku
            #if char == b'\0' or char == b'':
                #break
            #response += char
        
        #print("Gelen cevap:", response.decode("utf-8"))