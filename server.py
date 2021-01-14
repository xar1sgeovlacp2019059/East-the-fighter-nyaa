#!/usr/bin/env python3
import socket
import os
import sys
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
    
    s = socket.socket()
    s.bind((host,port))
    print("server Started")
    s.listen(1)
    while True:
        c, addr = s.accept()
        print("Connection from: " + str(addr))
        encAESkey=c.recv(1024)
        #print(encAESkey)
        privateKey=c.recv(1024)
        pikey=RSA.import_key(privateKey)
        RSAdecryptor=PKCS1_OAEP.new(pikey)
        AESkey=RSAdecryptor.decrypt(encAESkey)
       
        print("We encrypt your AESkey:",AESkey)
        c.send('We got the key. Thank you'.encode())
        
        
        iv=c.recv(16)
        print(iv)
        encmessage=c.recv(1024)
        AESdec=AES.new(AESkey,AES.MODE_CBC,iv)
        c.send('we are ready to decrypt your message'.encode())
        decmessage=AESdec.decrypt(encmessage)
        print(decmessage)
        c.send('Your message is decrypted :)'.encode())
        
        
        c.close()

if __name__ == '__main__':
    main()
