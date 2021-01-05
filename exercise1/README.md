import numpy as np
fl= open('message.txt','r')
a=fl.read()
a='0b'+a
b=int(a,2)
print(b)
