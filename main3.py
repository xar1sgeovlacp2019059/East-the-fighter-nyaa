import numpy as np
import channel
fl= open('message_to_send.txt','r')
mes_2send=fl.read()
num_list=[]
s=0
for i in mes_2send:
 if i!='\n':
  i=int(i)
  num_list=num_list +[i]
  

numpy_array=np.array(num_list)
for i in range(1,4):
 error=0.01*i
 message_array=channel.channel(numpy_array,[0,1],error)

 message=''
 if i==1:
  f=open("received_message1.txt","w")
 elif i==2:
  f=open("received_message2.txt","w")
 elif i==3:
  f=open("received_message3.txt","w")
 for i in range(1800):
  a=int(message_array[i])
  a=str(a)
  message=message+a
 f.write(message)
 f.close()

