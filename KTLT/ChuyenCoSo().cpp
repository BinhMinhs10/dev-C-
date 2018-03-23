#include <stdio.h>
#include <math.h>
int count = 0;
void chuyenCoSo_NonRecursion(int base,int number){
	
}
int chuyenCoSoRecursion(int base,int number){
	if(number==0 || base==10){
		return number;
	}
	int a = (number%base)*pow(10,count);
	count++;
	return a+chuyenCoSoRecursion(base,number/base);
}
int main(){
	int x,coso;
	printf("\nnhap so can chuyen: "); scanf("%d",&x);
	printf("\nnhap co so : "); scanf("%d",&coso);
	int temp = chuyenCoSoRecursion(coso,x);
	printf("\n chuyen %d sang %d la: %d",x,coso,temp);
	return 0;
}
