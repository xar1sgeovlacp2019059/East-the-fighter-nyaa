import numpy as np

h = np.array([[1,1,0,1,1,1,0,0,0],[1,0,1,1,0,0,1,0,0],[0,1,1,1,0,0,0,1,0],[0,0,0,0,1,0,0,0,1]])

#for i in range(3):
choice=0 
w=''
if choice==0:
 f=open("received_message1.txt","r")
 #if i==1:
  #f=open("received_message2.txt","r")
 #if i==2:
  #f=open("received_message2.txt","r")
 received_message=f.read()
 int_list=[]
 for j in received_message:
  if j!='\n':
   int_list=int_list+[int(j)]
 for z in range(200):
  message=np.array(int_list[9*z:9*z+9])
  decoded = np.dot(h,message)%2#h,message
  #print(decoded)
  if np.all((decoded==0)) == False:
   error_pos=0
   for i in range(4):
    if decoded[i-1]==1:
     a=pow(2,3-i)
     error_pos=error_pos+a
   if error_pos <= 9:
   
    if(message[error_pos-1]==0):
     message[error_pos-1]=1
    else:
     message[error_pos-1]=0
     
  for x in range(9):
   w=w+str(message[x])
    
    
    
o=open("test.txt","w") 
o.write(w)
o.close()
#print(w) 
#print(error_pos)
#print(int_list)
