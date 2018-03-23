#include <conio.h>
#include <stdio.h>
float f(float x); // khai bao nguyen ham mau
int main(){
	float x;
	printf("Nhap vao gia tri doi so x:");
	scanf("%f",&x);
	printf("ket qua goi ham la:%6.2f",f(x));
	getch();
	return 1;
	
}
float f(float x){
	if(x>=0)return (3*x*x-2*x+5);
	else return ((2*x*x+1)/x);
}
