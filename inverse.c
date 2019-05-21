#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int inverse(int,int);

int main(){
	int b,m;
	printf("Enter a number b:\t");
	scanf("%d", &b);
	printf("Enter modulo m:\t");
	scanf("%d",&m);
	int c= inverse(b,m);
	c=(c%m+m)%m;
	printf("Inverse of %d mod (%d) is \t%d\n",b,m,c);
	return 0;
}

int inverse(int b,int m){
	int a1=0,a2=0,a3=0,q=0,b1=0,b2=0,b3=0,t1=0,t2=0,t3=0;
	a1=1;
	a2=0;
	a3=m;
	b1=0;
	b2=1;
	b3=b;
	int cont=0;
	do{
		if(b3==0){
			cont=1;
			printf("No inverse exists\n");
			exit(1);
			//return -1;
		}
		if(b3==1){
			cont=1;
			return b2;
		}
		q=0;
		q=floor(a3/b3);

		t1=a1 - (q*b1);
		t2=a2 - (q*b2);
		t3=a3 - (q*b3);
		a1=b1;
		a2=b2;
		a3=b3;
		b1=t1;
		b2=t2;
		b3=t3;
	}while(cont==0);
}
