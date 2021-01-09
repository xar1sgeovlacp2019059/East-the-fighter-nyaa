fl= open('message.txt','r')
errors=[0,0,0]
message=fl.read()
for i in range(3):
 if i==0:
  f=open('decoded_message1.txt','r')
 if i==1:
  f=open('decoded_message2.txt','r')
 if i==2:
  f=open('decoded_message3.txt','r')
 decmessage=f.read()
 for j in range(1000):
  if message[j] != decmessage[j]:
   errors[i]=errors[i]+1
print(errors)
