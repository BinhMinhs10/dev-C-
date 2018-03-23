#include <stdio.h>
#include <conio.h>
int main(){
	int a,b,tmp,n;
	printf("\nphan tu thu may cua day Fibonaci: n= ");
	scanf("%d",&n);
	if(n==1||n==0){
		printf("F(%d)= 1",n);
		return 0;
	}
	a=1; b=1;
	for(int i=2;i<n;i++){
		tmp=a;
		a=a+b;
		b=tmp;
	}
	printf("F(%d)= %d",n,a+b);
	return 0;
}
