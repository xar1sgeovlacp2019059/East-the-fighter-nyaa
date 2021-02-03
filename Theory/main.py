import numpy as np
#A.M. 2019059->59mod3 +5=7 (n=7,k=4)
d=np.array([[0,0,0,0],[0,0,0,1],[0,0,1,0],[0,0,1,1],[0,1,0,0],[0,1,0,1],[0,1,1,0],[0,1,1,1],[1,0,0,0],[1,0,0,1],[1,0,1,0],[1,0,1,1],[1,1,0,0],[1,1,0,1],[1,1,1,0],[1,1,1,1]]) #data


g=np.array([[1,0,0,0,0,1,1],[0,1,0,0,1,0,1],[0,0,1,0,1,1,0],[0,0,0,1,1,1,1]])#generation matrix(k X n)=>(4 X 7)

I1=np.array([1,0,0])
I2=np.array([0,1,0])
I3=np.array([0,0,1])

#1)
h1=np.random.randint(2, size=4)# add random bits(1 or 0) 
h2=np.random.randint(2, size=4)
h3=np.random.randint(2, size=4)

h1=np.insert(h1,4,I1,axis=0)# h1<-[h1 1 0 0] (1 X 7)
h2=np.insert(h2,4,I2,axis=0)# h2<-[h2 0 1 0]
h3=np.insert(h3,4,I3,axis=0)# h3<-[h3 0 0 1]
h=np.array([h1,h2,h3]) # first try to create H(3 X 7)

hgt=np.dot(h,np.transpose(g))%2# H*(G^T)

while(np.all(hgt==0)==False):# while H*(G^T)!=0 array, repeat
 h1=np.random.randint(2, size=4)
 h2=np.random.randint(2, size=4)
 h3=np.random.randint(2, size=4)
 
 h1=np.insert(h1,4,I1,axis=0)
 h2=np.insert(h2,4,I2,axis=0)
 h3=np.insert(h3,4,I3,axis=0)
 
 h=np.array([h1,h2,h3])
 hgt=np.dot(h,np.transpose(g))%2

print('H: ')
print(h)

print('\n')

#2)
c=np.empty([16,7], dtype=int)#Create empty array for codewords 


for i in range(16):
 ci=np.dot(d[i],g)%2   #put codewords(data*g) to array 
 c[i]=ci

print('codewords \n') 
print(c)

print('\n')



#3)
syndroms=np.array([[0,0,0],[0,0,1],[0,1,0],[0,1,1],[1,0,0],[1,0,1],[1,1,0],[1,1,1]])# 2^(n-k)=2^(7-4)=2^3=8 different syndroms and complexes
parrity=np.array([0,0,0,0])# we need to turn each syndrom in array(1 X 7) 


complexArr=np.empty([16,7], dtype=int)#create empty array for complex,this will change every round

for i in range(8):
 
 syndrom=np.insert(syndroms[i],0,parrity,axis=0)#we turn each syndrom in array(1X7)
 
 for j in range(16):
  complexArr[j]=(c[j]+syndrom)%2           # complex[j]=codeword[j]+syndrom[i]
  
 print('syndrom',i+1,'=',syndroms[i],'\n')
 print('complex',i+1,': \n')
 print(complexArr)  # this array will be differnt for each i
 
 if i!=7: # Nothing special
  print('\n')
