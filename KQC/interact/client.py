import xmlrpc.client
import time
import stating
import os

if __name__ == '__main__':
		s = xmlrpc.client.ServerProxy("http://localhost:23675")
		print(s.startClient("client zzl"))
		cmd=input()
		while cmd:
			cmdList=cmd.split(' ')
			retRes=None
			if len(cmdList[1:])==0:
				retRes=eval(cmdList[0])()
			else:
				retRes=eval(cmdList[0])(tuple(cmdList[1:]))
			print(retRes)
			cmd=input()
		'''print(s.run_cmd(["python.exe","myProc.py"]))
		res= s.getState()
		while res!=stating.finish:
			print(res)
			time.sleep(2)
			res=s.getState()'''
		print("finish")
	
