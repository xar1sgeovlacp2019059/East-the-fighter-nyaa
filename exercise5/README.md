import numpy as np

h = np.array([[1,1,0,1,1,1,0,0,0],[1,0,1,1,0,0,1,0,0],[0,1,1,1,0,0,0,1,0],[0,0,0,0,1,0,0,0,1]])

choice=0 
for choice in range(3):      
 w=''
 if choice==0:
  f=open("received_message1.txt","r")
 elif choice==1:
  f=open("received_message2.txt","r")
 elif choice==2:
  f=open("received_message2.txt","r")
  
 received_message=f.read()
 int_list=[]
 for j in received_message:
  if j!='\n':
   int_list=int_list+[int(j)]
 for z in range(200):           # eleghos
  message=np.array(int_list[9*z:9*z+9])
  decoded = np.dot(h,message)%2#h,message
  #print(decoded)
  if np.all((decoded==0)) == False:
   print(message)
   for i in range(h.shape[1]):
    if np.array_equal(h[:,i] , decoded):
     #print('error in position: ',i)
     message[i] = (message[i] + 1)%2
     print(message)
     break
     
  for x in range(5):
   w=w+str(message[x])
    
 if choice==0:
  cl=open("decoded_message1.txt","w")
  cl.write(w)
  cl.close()
 elif choice==1:
  cl=open("decoded_message2.txt","w")
  cl.write(w)
  cl.close()
 elif choice==2:
  cl=open("decoded_message3.txt","w")
  cl.write(w)
  cl.close()    
