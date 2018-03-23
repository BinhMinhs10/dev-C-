#include <stdio.h>
int main(){
	int flag=1;
	char xau1[100], xau2[100];
	printf("\nnhap file ket qua mong muon: "); scanf("%s",&xau1);
	printf("\nnhap file ket qua cua chuong trinh muon test: "); scanf("%s",&xau2);
	FILE *f = fopen(xau1, "r" );
	if(f == NULL){
		fprintf(stderr,"\nCan't open file");
		return 1;
	}
	FILE *p = fopen(xau2, "r");
	if(p==NULL){
		fprintf(stderr,"\nCan't open file");
		return 1;
	}
	char temp1,temp2;
	while(!feof(f)){
		fscanf(f,"%c",&temp1);
		fscanf(p,"%c",&temp2);
		if(temp1 != temp2){
			printf("\nFile ket qua sai so voi mong muon");
			flag = 0;
			break;
		}
	}
	if(flag == 1)
	printf("\nFile ket qua dat yeu cau");
	return 0;
}
