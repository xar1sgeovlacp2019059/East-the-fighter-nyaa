import numpy as np
fl= open('message_to_send.txt','r')
a=fl.read()
num_list=[]
for i in a:
 if i!='\n':
  i=int(i)
  num_list=num_list +[i]

numpy_array=np.array(num_list)
