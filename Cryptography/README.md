import random
from Cryptodome.Cipher import AES
import hashlib
import binascii
from binascii import hexlify,unhexlify
import Cryptodome.Cipher.AES
import secrets

key=secrets.token_bytes(16)
iv=secrets.token_bytes(16)
#IV=hex(bytes)
#print(iv)
cipher=AES.new(key,AES.MODE_CBC,iv)

plain="plaintext1234567"
bplain=plain.encode()
#print(bplain)
schyther=cipher.encrypt(bplain)


cither=AES.new(key,AES.MODE_CBC,iv)

a=cither.decrypt(schyther)
print(a)
