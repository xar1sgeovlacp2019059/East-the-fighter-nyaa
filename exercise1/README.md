import numpy as np
fl= open('message.txt','r')
a=fl.read()
#a='0b'+a
v=int(a,2)
v=str(v)
num_list=[]
for i in v:
 i=int(i)
 num_list=num_list +[i]
numpy_array=np.array(num_list)
print(numpy_array)
