#include <stdio.h>
#include <conio.h>
#define MAX 10000

int matran[100][100];
int vertices, edges;

void readdata(const char *name){
	FILE* f=fopen(name,"r");
	if(f==NULL){
		fprintf(stderr,"\nCan't open file");
		return;
	}
	fscanf(f,"%d",&vertices);
	fscanf(f,"%d",&edges);
	for(int i=1; i<=vertices; i++){
		for(int j=1; j<=vertices; j++){
			matran[i][j] = 0;
		}
	}
	int temp1, temp2, element;
	while(!feof(f)){
		fscanf(f,"%d",&temp1);
		fscanf(f,"%d",&temp2);
		fscanf(f,"%d",&element);
		matran[temp1][temp2] = element;
		matran[temp2][temp1] = element;
	}
}
void printPath(int s,int f,int *back){
	if(s==f){
		printf("%d->",f);
	}
	else{
		printPath(s,back[f],back);
		printf("%d->",f);
	}
}

void Dijstra (int start, int finish){
	int weight[100],mark[100],back[100];
	for(int i=1; i<=vertices; i++){
		weight[i] = MAX;
		mark[i] = 0;
		back[i] = -1;
	}
	weight[start] = 0;
	back[start] = 0;
	int connect;
	do{
		connect = -1;
		int dmin = MAX;
		for(int i =1 ;i<=vertices ; i++){
			if(mark[i]==0){
				if(matran[start][i]!=0 && weight[i]>weight[start]+matran[start][i]){
					weight[i] = weight[start] + matran[start][i];
					back[i] = start;
				}
				if(dmin>weight[i]){
					dmin = weight[i];
					connect = i;
				}
			}
		}
		start = connect;
		mark[start] = 1;
	}while(connect!=-1 &&  start!=finish);
	printf("\ntong duong di nho nhat: %d\n",weight[finish]);
	printPath(1,finish,back);
}

int main(){
	readdata("graphhaveweight.txt");
	//printf("\n%d",matran[6][5]);
	Dijstra(1,6);
	getch();
}
