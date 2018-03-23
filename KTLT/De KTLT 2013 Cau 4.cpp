#include<stdio.h>
void vidu(int &x,int *y,int &z){
	x*=2;
	printf("%d : %d",y,*y);
	y+=2;
	printf("\n%d : %d",y,*y);
	z<<=2;
}
int main(){
	int x=1,y=2,z=3;
	vidu(z,&x,y);
	printf("\nx= %d, y=%d, z=%d",x,y,z);
}
