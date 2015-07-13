import RPi.io as io

#------------- PINS -------------
grid_data = 4
grid_avil = 14
grid_ack  = 15
READ  = 0
WRITE = 1

io.setmode(io.BCM)
io.setup(data_inout, io.INOUT, io.PUD_UP)
io.setup(data_ack, 	 io.INOUT, io.PUD_UP)
io.setup(data_rw, 	 io.INOUT, io.PUD_UP)
io.setup(data_avail, io.INOUT, io.PUD_UP)

#------------- GLOBALS -------------
GRID_SIZE = 30
grid = [[0 for x in range(GRID_SIZE)] for x in range(GRID_SIZE)]

#------------- CODE -------------

# Continually reads in a 1-bit status for each grid entry, 
# until the Arduino lowers grid_avail
def getGridState():
	count = 0
	io.output(data_rw, READ)
	while io.input(grid_avail) == False:
		pass
	while io.input(grid_avail) == True:
		bit = io.input(grid_data)
		grid[bitcount//GRID_SIZE][bitcount%GRID_SIZE] = bit
		bitcount += 1
		io.output(grid_ack, 1)
		delay(1)
		io.output(grid_ack, 0)
		delay(1)

def sendNextLegoPlacing():
	pass

def loop():
	pass
	
if __name__ == '__main__':
	loop()
	