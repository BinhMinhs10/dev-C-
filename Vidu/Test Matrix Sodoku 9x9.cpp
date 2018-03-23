#include <stdio.h>
int Board[10][10];
void readdata(const char *name){
	FILE* f=fopen(name,"r");
	if(f==NULL){
		fprintf(stderr,"\nCan't open file");
		return;
	} 
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			fscanf(f,"%d",&Board[i][j]);
		}
	}
}
bool checkValid(int Board[9][9]){
	
}
void print(){
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			printf("%d",Board[i][j]);
		}
		printf("\n");
	}
}

int main(){
	readdata("9x9.txt");
	print();
	return 0;
}
