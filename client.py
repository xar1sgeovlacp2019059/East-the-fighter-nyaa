#!/usr/bin/env python3 
import socket, os.path, datetime, sys
import random
from Cryptodome.Cipher import AES
import Cryptodome.Cipher.AES
from Cryptodome.Cipher import PKCS1_OAEP
from Cryptodome.PublicKey import RSA
import secrets
import binascii
def main():
    host = '127.0.0.1'
    port = 50001

    s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    s.connect((host, port))
    AESkey=secrets.token_bytes(16)
    print(AESkey)
    iv=secrets.token_bytes(16)
    cipher=AES.new(AESkey,AES.MODE_CBC,iv)
    message="dame dane dameyo"
    bmessage=message.encode()
    C=cipher.encrypt(bmessage)#encryption AES
    
    keypair= RSA.generate(1024) #Generate RSAkeys
    #print(keypair)
    pubkey=keypair.publickey()
    pubkeyPEM=pubkey.exportKey()#Public key
    
    prikeyPEM=keypair.exportKey()#Private key
    
    RSAenc=PKCS1_OAEP.new(pubkey)
    encryptedkey=RSAenc.encrypt(AESkey)
    #print(encryptedkey)
    s.send(encryptedkey)
    s.send(prikeyPEM)
    ack = s.recv(1024).decode()
    print(ack)
    
    
    s.send(iv)
    print(iv)
    s.send(C)
    
    ack = s.recv(1024).decode()
    print(ack)
    ack = s.recv(1024).decode()
    print(ack)
    
    s.close()

if __name__ == '__main__':
    main()
