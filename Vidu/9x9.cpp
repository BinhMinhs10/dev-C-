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
bool checkValid(int Board[][10]){
	int flag[10];
	for(int i=1;i<=9;i++){
		for(int k=1;k<=9;k++){
			flag[k]=0;
		}
		for(int j=1;j<=9;j++){
			if(flag[Board[i][j]]==0){
				flag[Board[i][j]]=1;
			}
			else{
				return false;
			}
		}
	}
	
	return true;
}
void print(){
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			printf("%2d",Board[i][j]);
		}
		printf("\n");
	}
}

int main(){
	readdata("9x9.txt");
	print();
	if(checkValid(Board) == true){
		printf("\nHop le");
	}
	else{
		printf("\nKhong hop le");
	}
	return 0;
}
