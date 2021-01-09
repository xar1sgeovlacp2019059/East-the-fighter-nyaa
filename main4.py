import numpy as np
import channel
fl= open('message_to_send.txt','r')
errors=[0,0,0]
mes_2send=fl.read()
for i in range(3):
 if i==0:
  f=open('received_message1.txt','r')
 if i==1:
  f=open('received_message2.txt','r')
 if i==2:
  f=open('received_message3.txt','r')
 mes_2rec=f.read()
 for j in range(1800):
  if mes_2send[j]!=mes_2rec[j]:
   errors[i]=errors[i]+1

for i in range(3):
 print("errors",errors[i],"with error possibility=",0.01*(i+1))
