#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 1000
int Matrix[100][100];//ma tran de luu xem 2 dinh co lien ket voi nhau khong
int vertice,edge;
int *d = (int *) malloc(100*sizeof(int));
int *Trace = (int *) malloc(100*sizeof(int));
int start, finish;

void readFile(const char *name){
	FILE* f = fopen(name,"r");
	if(f==NULL){
		fprintf(stderr,"\nCan't open file");
	}
	else{
		int temp1, temp2, temp3;
		fscanf(f,"%d",&vertice);
		fscanf(f,"%d",&edge);
		for(int i=1;i<=vertice;i++){
		for(int j=1;j<=vertice;j++){
			if(i!=j) Matrix[i][j] = MAX;
			else{
				Matrix[i][j]=0;
			}
		}
	}
		while(!feof(f)){
			fscanf(f,"%d",&temp1);
			fscanf(f,"%d",&temp2);
			fscanf(f,"%d",&temp3);
			Matrix[temp1][temp2] = temp3;
			Matrix[temp2][temp1] = temp3;
		}
	}
	fclose(f);
}
void printMatrix(int n){
	printf("\nMatrix :\n");
	printf("     ");
	for(int i=1;i<=n;i++){
		printf(" [%d]",i);
	}
	printf("\n");
	for(int i = 1; i<= n; i++ ){
		printf(" [%d] ",i);
		for(int j=1;j<= n ; j++){
			printf(" %2d ",Matrix[i][j]);
		}
		printf("\n");
	}
}
void Init(){
	for(int i=1;i<=vertice;i++){
		d[i] = Matrix[start][i];
		Trace[i]=start;
	}
}
void Fold_Bellman(){
	bool stop;
	int countloop, u,v;
	countloop=0;
	do{
		stop=true;
		for(u=1;u<=vertice ;u++){
			for(v=1;v<=vertice;v++){
				if(d[v]>d[u]+Matrix[u][v]){
					d[v]=d[u]+Matrix[u][v];
					Trace[v]=u;
					stop = false;
				}
			}
		}
		countloop++;
	}while( stop || countloop>=(vertice-2) );
}
void printResult(){
	if(d[finish]==MAX){
		printf("\nPath from %d to %d is not found",start,finish);
		return;
	}else{
		printf("\nDistance from %d to %d is %d\n",start,finish,d[finish]);
	}
	printf("%d <- ",finish);
	do{
		finish=Trace[finish];
		printf("%d <- ",finish);
	}while(start!=finish);
}
int main(int argc,char* argv[]){
	readFile("MINPATH.txt");
	printf("\nnhap dinh bat dau va ket thuc: ");
	scanf("%d %d",&start,&finish);
	Init();
	printMatrix(vertice);
	getch();
	system("cls");
	Fold_Bellman();
	printResult();
	return 0;
}
