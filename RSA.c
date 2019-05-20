#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int inverse(int,int);
int euler_function(int,int);
int rsa_encrypt(int,int);
int rsa_decrypt(int,int);
int N;
int main(){
	int p,q;
	printf("Enter P and Q\t");
	scanf("%d%d",&p,&q);
	int n = p*q;
	N=n;
	int M;
	printf("N %d", N);
	printf("Enter Message\t");
	scanf("%d",&M);
	int phi = euler_function(p,q);
	int e;
	printf("Enter public key");
	scanf("%d", &e);
	int d = inverse(e,phi);
	//convert negative number to positive number in mod 26
	d=(d%phi+phi)%phi;
	int private_key=d;
	int public_key=e;
	int plaintext = M;
	int cipher = rsa_encrypt(plaintext,public_key);
	cipher = (cipher%N+N)%N;
	int ciphertext =cipher;

	plaintext = rsa_decrypt(ciphertext,private_key);
	plaintext = (plaintext%N+N)%N;
	printf("Given-------\n");
	printf("P and Q\t%d%d\n",p,q);
	printf("public key e:\t%d\n",e);
	printf("inverse private key: \t%d",d);
	printf("Cipher is: %d",cipher);
	printf("Plaint text is %d\n", plaintext);
	return 0;
}

int rsa_decrypt(int ciphertext, int pk){
	int plaintext=pow(ciphertext,pk);
	printf("PKr %d",pk);
	plaintext=plaintext%N;
	printf("\t%d",plaintext); 
	return plaintext;
}
int rsa_encrypt(int plaintext, int pk){
	//int ciphertext=malloc(200);
	int ciphertext = pow(plaintext,pk);
	printf("%d",ciphertext);
	ciphertext %= N;
	return ciphertext;
}
int inverse(int b, int m){
	int a1=1, a2=0, a3=m, b1=0, b2=1, b3=b, t1, t2, t3;
	int q;
//	for(int i=0;i<2;i++){
	do{
		if(b2==0){
			printf("No Inverse\n");
			printf("GCD %d\n",b3);
			return -1;
		}
		if(b3==1){
			return b2;
		}
		q = floor(a3/b3);
		t1=a1-q*b1;
		t2=a2-q*b2;
		t3=a3-q*b3;
		a1=b1;
		a2=b2;
		a3=b3;
		b1=t1;
		b2=t2;
		b3=t3;
	}while(b2!=0||b3!=1);
	if(b2==0){
        	printf("No Inverse\n");
                printf("GCD %d\n",b3);
                return -1;
        }
        if(b3==1){
                return b2;
        }
	//printf("%d",q);
}
int euler_function(int p, int q){
	int phi=(p-1)*(q-1);
	return phi;
}
