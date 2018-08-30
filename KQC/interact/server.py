from xmlrpc.server import SimpleXMLRPCServer
from multiprocessing import Process, Queue
import subprocess
import stating
import threading

currentState=stating.halt

def startClient(str):
    return "start suc :%s"%str

def execute(cmd):
	p=subprocess.Popen(cmd,shell=False,stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
	while p.poll() is None:
		line = p.stdout.readline()[0:-2]
		print(line)
		global currentState
		currentState=str(line)[1:-1].split(" ")[1]
	if p.returncode==0:
		return "exec suc"
	else:
		return "exec err"
	
def run_cmd1(cmd):
	t=threading.Thread(target=execute,args=(cmd,))
	t.start()
	return "start"
	
def getState():
	return currentState

if __name__ == '__main__':
	#p=subprocess.Popen(["python.exe","myProc.py"],shell=False,stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
	s = SimpleXMLRPCServer(('0.0.0.0', 23675))
	s.register_function(run_cmd1,"run_cmd")
	s.register_function(getState,"getState")
	s.register_function(startClient,"startClient")
	#s.register_function(runningState1,"runningState")
	s.serve_forever()
