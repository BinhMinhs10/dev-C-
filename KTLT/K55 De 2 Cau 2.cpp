#include <stdio.h>
#include <conio.h>
int main(){
	int A[]={5,7,19,1,2,6};
	for(int i=0;i<=5;i++){
		printf("%3d",A[i]);
	}
	printf("\n");
	int b, *p=A+2;
	b=*p++;
	printf("\nb=%d va *p = %d\n",b,*p);
	*p+=2*b;
	p++;
	*p+=1;
	for(int i=0;i<=5;i++){
		printf("%3d",A[i]);
	}
	return 0;
	getch();
}
