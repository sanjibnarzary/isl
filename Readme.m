#Readme

##How to Use this Manual

** RSA **
This is a basic RSA implementation. To compile it `cc RSA.c -lm -o rsa.o` it will generate `rsa.o` object file and now you can execute it by typing `./rsa`

**CaesarCipher**

CaesarCipher implementation in C. However there is a little modification in basic algorithm. 
`C = (p+10+k) mod 26` 
where 10 is a constant
