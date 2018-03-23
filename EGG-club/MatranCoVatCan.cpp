#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int column, row;
int Matran[100][100];
void readdata(const char *name){
	FILE* f=fopen(name,"r");
	if(f==NULL){
		fprintf(stderr,"\nCan't open file");
		return;
	}
	fscanf(f,"%d",&row);
	fscanf(f,"%d",&column);
	for(int i=1;i<=row;i++){
		for(int j=1;j<=column;j++){
			fscanf(f,"%d",&Matran[i][j]);
		}
	}
}
void print(){
	printf("\n%d %d\n",row,column);
	for(int i=1;i<=row;i++){
		for(int j=1;j<=column;j++){
			printf("%d ",Matran[i][j]);
		}
		printf("\n");
	}
}
int main(){
	readdata("MatranCoVatCan.txt");
	print();
	getch();
	return 0;
}
