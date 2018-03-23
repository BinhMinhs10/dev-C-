#include <stdio.h>
struct PS{
	int TuSo,MauSo;
};
int UCLN(int a,int b){
	return b ? UCLN(b,a%b) : a;
}
int UCLN1(int x,int y){
	if(x==y)
		return x;
	else if(x>y)
		return UCLN(x-y,y);
	else 
		return UCLN(x,y-x);
}
PS operator ~ (PS &a){
	a.TuSo/=UCLN1(a.TuSo,a.MauSo);
	a.MauSo/=UCLN1(a.TuSo,a.MauSo);
	return a;
}
int main(){
	PS a;
	a.TuSo = 10;
	a.MauSo = 6;
	printf("%d/%d",a.TuSo,a.MauSo);
	~(a);
	printf("\n%d/%d",a.TuSo,a.MauSo);
	return 0;
}
