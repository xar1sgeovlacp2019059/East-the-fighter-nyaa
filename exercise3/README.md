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
  s=s+1

numpy_array=np.array(num_list)
error=0.01
message_array=channel.channel(numpy_array,[0,1],error)
print(message_array)
print(int(message_array[27]))
message=''
f=open("received_message1.txt","w")
for i in range(1800):
 a=int(message_array[i])
 a=str(a)
 message=message+a
f.write(message)
f.close()
#print(message)
