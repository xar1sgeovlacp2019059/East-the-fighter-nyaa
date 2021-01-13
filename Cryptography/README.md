import random
from Cryptodome.Cipher import AES
import Cryptodome.Cipher.AES
from Cryptodome.Cipher import PKCS1_OAEP
from Cryptodome.PublicKey import RSA
import secrets
import binascii

key=secrets.token_bytes(16)
iv=secrets.token_bytes(16)

cipher=AES.new(key,AES.MODE_CBC,iv)

plain="plaintext1234567"
bplain=plain.encode()
#print(bplain)
schyther=cipher.encrypt(bplain)#encryption AES

print(key)
#cither=AES.new(key,AES.MODE_CBC,iv)#Decryption AES

#a=cither.decrypt(schyther)

#print(a)
keypair=RSA.generate(1024)#Generate keys
pubkey=keypair.publickey()
#print(keypair)
pubikey=pubkey.exportKey()
#print(pubikey.decode('ascii'))
RSAenc=PKCS1_OAEP.new(pubkey)
encryptedkey=RSAenc.encrypt(key)
#print(encryptedkey)

decryptor=PKCS1_OAEP.new(keypair)
b=decryptor.decrypt(encryptedkey)
print(b)
