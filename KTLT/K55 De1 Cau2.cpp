#include <stdio.h>
int main(){
	int B[]={2,4,7,8,9,15};
	for(int i=0;i<=5;i++){
		printf("%3d",B[i]);
	}
	printf("\n");
	int c,*p=&B[1];
	*p+=1; c=*p--;
	p+=3;
	printf("%d\n",*p);
	*p+=c;
	for(int i=0;i<=5;i++){
		printf("%3d",B[i]);
	}
	return 0;
}
