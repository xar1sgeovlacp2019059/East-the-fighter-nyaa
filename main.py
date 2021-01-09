import numpy as np
fl= open('message.txt','r')
a=fl.read()
v=int(a,2)
v=str(v)
num_list=[]
s=0
for i in a:
 
 if i!='\n':
  
  i=int(i)
  num_list=num_list +[i]
numpy_array=np.array(num_list)
print(numpy_array)
#print(v)

