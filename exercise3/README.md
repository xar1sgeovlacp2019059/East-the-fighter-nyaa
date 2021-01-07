import numpy as np
import channel
fl= open('message_to_send.txt','r')
a=fl.read()
num_list=[]
s=0
for i in a:
 if i!='\n':
  i=int(i)
  num_list=num_list +[i]
  s=s+1

numpy_array=np.array(num_list)
error=0.01
message=channel.channel(numpy_array,[0,1],error)
#print(message)
print(s)
