#include<stdio.h>
int gcd(int,int);
int main(){
	int a,b;
	printf("Enter a:\t");
	scanf("%d", &a);
	printf("Enter b:\t");
	scanf("%d", &b);
	printf("GCD(%d,%d)is\t%d\n",a,b,gcd(a,b));
	return 0;
}

int gcd(int a,int b){
	int c;
	if(b==0){
		return a;
	}
	else{
		return gcd(b,a%b);
		
	}
}
