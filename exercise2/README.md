import numpy as np
fl= open('message.txt','r')
a=fl.read()
v=int(a,2)
v=str(v)
num_list=[]
s=0
for i in a:
 #i=int(i)
 #s=s+1
 if i!='\n':
  #s=s+1 
  i=int(i)
  num_list=num_list +[i]
numpy_array=np.array(num_list)
print(numpy_array)
g = np.array([[1,0,0,0,0,1,1,0,0],[0,1,0,0,0,1,0,1,0],[0,0,1,0,0,0,1,1,0],[0,0,0,1,0,1,1,1,0]],[0,0,0,0,1,1,0,0,1])
#print(v)
