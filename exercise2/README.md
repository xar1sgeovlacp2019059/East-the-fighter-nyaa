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
#print(numpy_array)
g = np.array([[1,0,0,0,0,1,1,0,0],[0,1,0,0,0,1,0,1,0],[0,0,1,0,0,0,1,1,0],[0,0,0,1,0,1,1,1,0],[0,0,0,0,1,1,0,0,1]])
h = np.array([[1,1,0,1,1,1,0,0,0],[1,0,1,1,0,0,1,0,0],[0,1,1,1,0,0,0,1,0],[0,0,0,0,1,0,0,0,1]])
print(np.dot(h,np.transpose(g))%2)
#print(v)





for i in a:
 
 if i!='\n':
  team_members=team_members+[i]
  if len(team_members)< 5:
   i=int(i)
   team_members=team_members +[i]
  if len(team_members)==5:
   num_list=num_list+[team_members]
   team_members.clear()
