#include <stdio.h>
int main(){
	int A[]={6,13,34,19};
	int *p=A;
	printf("\n%d\n",*p);
	*p++;
	*p+=2;
	p+=2;
	//p=A+2;
	*p+=2;
	for(int i=0;i<=3;i++){
		printf("%3d",A[i]);
	}
	int x;
	scanf("%d",x);
	return 0;
}
