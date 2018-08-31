import time
import sys
import stating

def writeState(state):
	sys.stdout.write("state "+state+"\n")
	sys.stdout.flush()
	
if __name__ == '__main__':
	writeState(stating.start)
	time.sleep(6)
	writeState(stating.indexing)
	time.sleep(6)
	writeState(stating.mapping)
	time.sleep(6)
	writeState(stating.quanting)
	time.sleep(6)
	writeState(stating.labeling)
	time.sleep(6)
	writeState(stating.finish)