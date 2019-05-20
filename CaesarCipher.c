/**
* C Program to encrypt and descrypt messages using Caesar Cipher
* Sanjib Narzary
* CIT Kokrajhar
* san@cit.ac.in
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int chPosition(char);
char *encrypt(char*,int);
char *decrypt(char*, int);
const int ten=10;
const char alphabets[]="abcdefghijklmnopqrstuvwxyz";
const int l=26;

int main(){
	//the key is required in caesar Cipher
	//the size of key is any integer number in between 0 to 25
	int key;
	printf("Enter Key Size:\t");
	scanf("%d",&key);
	//plaintext is required to encrypt
	char msg[]="hello";
	printf("Enter Plaintext Message:\t");
	scanf("%s",msg);
	printf("Your encrypted text is:\t %s\n", encrypt(msg,key));
	//this part is in the decryption side
	//if key is already declared then fine
	//now declare the ciphertext and ask for user input
	char cipher[]="fijrgzybzdnkjrzm";
	printf("Enter Ciphertext message to Decrypt:\t");
	scanf("%s", cipher);
	printf("Your plaintext Message is:\t %s\n", decrypt(cipher,key));
}

char *encrypt(char *p,int key){
	int len=strlen(p);
	int i;
	char *ciphertext=malloc(1000);
	for(i=0;i<len;i++){
		int ptp = chPosition(p[i]);
	 	int c = (ptp+ten+key)%l;
		ciphertext[i]=alphabets[c];
	}

	return ciphertext;
}
char *decrypt(char *c, int key){
	int len=strlen(c);
	int i;
	char *plaintext=malloc(1000);
	for(i=0;i<len;i++){
		int ctp = chPosition(c[i]);
		int num = (ctp-ten-key);
		int p=(num%l+l)%l;
		//int p=(num-q*l);
		printf("%d",p);
		plaintext[i]=alphabets[p];
	}
	return plaintext;
}
int chPosition(char c){

	int i;

	for(i=0;i<l;i++){
		if(alphabets[i]==c){
			return i;
		}
	}
}
