#include <stdio.h>
#include <math.h>
//ham de quy chuyen sang co so base
void chuyenCoSo(int base, int number){
	char digits[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	if(number <= 0){
		return ;
	}
	chuyenCoSo(base,number/base);
	printf("%c",digits[number%base]);
}
void chuyenCoSo_nonRec(int base, int number){
	char digits[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	char output[100];
	int i=0;
	while(number>0){
		output[i++]=digits[number%base];
		number = number/base;
	}
	i--;
	for(;i>=0;i--){
		printf("%c",output[i]);
	}
}
int main(int argc, char *argv[]){
	int number,base;
	printf("\nchuyen so: "); scanf("%d",&number);
	printf("\nsang co so: "); scanf("%d",&base);
	printf("\n%d sang co so %d la : ",number,base);
	chuyenCoSo_nonRec(base, number);
	printf("\n%d sang co so %d la : ",number,base);
	chuyenCoSo(base, number);
	return 0;
}
