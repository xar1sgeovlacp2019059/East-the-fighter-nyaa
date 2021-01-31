iimport numpy as np

d=np.array([[0,0,0,0],[0,0,0,1],[0,0,1,0],[0,0,1,1],[0,1,0,0],[0,1,0,1],[0,1,1,0],[0,1,1,1],[1,0,0,0],[1,0,0,1],[1,0,1,0],[1,0,1,1],[1,1,0,0],[1,1,0,1],[1,1,1,0],[1,1,1,1]])
#d=np.array([[0,0,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]])

g=np.array([[1,0,0,0,0,1,1],[0,1,0,0,1,0,1],[0,0,1,0,1,1,0],[0,0,0,1,1,1,1]])
I1=np.array([1,0,0])
I2=np.array([0,1,0])
I3=np.array([0,0,1])
#for i in range(4):
 #print(c[i])

#h=np.random.randint(2, size=7)
h1=np.random.randint(2, size=4)
h2=np.random.randint(2, size=4)
h3=np.random.randint(2, size=4)

h1=np.insert(h1,4,I1,axis=0)
h2=np.insert(h2,4,I2,axis=0)
h3=np.insert(h3,4,I3,axis=0)
h=np.array([h1,h2,h3])
#print(h)
hgt=np.dot(h,np.transpose(g))%2
#print(hgt)
while(np.all(hgt==0)==False):
 h1=np.random.randint(2, size=4)
 h2=np.random.randint(2, size=4)
 h3=np.random.randint(2, size=4)
 h1=np.insert(h1,4,I1,axis=0)
 h2=np.insert(h2,4,I2,axis=0)
 h3=np.insert(h3,4,I3,axis=0)
 h=np.array([h1,h2,h3])
 hgt=np.dot(h,np.transpose(g))%2
#print(h)


c=np.empty([16,7], dtype=int)#check
#print(c)
for i in range(16):# check
 ci=np.dot(d[i],g)%2
 c[i]=ci
 
#print(c)
syndroms=np.array([[0,0,0],[0,0,1],[0,1,0],[0,1,1],[1,0,0],[1,0,1],[1,1,0],[1,1,1]])
parrity=np.array([0,0,0,0])

#syndrom=np.insert(syndroms[4],0,parrity,axis=0)
#print(syndrom)

#test= c[0]+syndrom
#test=np.dot(c,np.transpose(h))%2
#print(test)

complexArr=np.empty([16,7], dtype=int)#check
#print(complexArr)
for i in range(8):
 #print(syndroms[i])
 syndrom=np.insert(syndroms[i],0,parrity,axis=0)
 print(syndrom)
 for j in range(16):
  complexArr[j]=(c[j]+syndrom)%2
 print(complexArr)


