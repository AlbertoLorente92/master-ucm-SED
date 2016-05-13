import threading
import serial
import time

io1 = serial.Serial('/dev/ttyUSB0', 115200)
io2 = serial.Serial('/dev/ttyUSB1', 115200)
io1.flush()
io2.flush()
print " - Maletines detectados!"


class Transmiter(threading.Thread):
	def __init__(self, port1, port2):
		threading.Thread.__init__(self)
		self.port1 = port1
		self.port2 = port2
	
	def run(self):
		while(True):
			msg = self.port1.read()
			print bin(ord(msg))
			self.port2.write(msg)
		
	
tr1 = Transmiter(io1, io2)
tr2 = Transmiter(io2, io1)

tr1.start()
tr2.start()

while(True):
	time.sleep(100)
