from xmlrpclib import ServerProxy
import time
import stating

if __name__ == '__main__':
	s = ServerProxy("http://localhost:23675")
	print s.run_cmd(["python.exe","myProc.py"])
	res= s.getState()
	while res!=stating.finish:
		print res
		time.sleep(2)
		res=s.getState()
	print "finish"
	