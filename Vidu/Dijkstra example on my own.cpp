#include <stdio.h>
#include <conio.h>
#define MAX 10000

int matran[100][100];
int weight[100],mark[100],back[100],connect;
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
	}
}
void Dijstra (int start, int finish){
	weight[start] = 0;
	mark[start] = 1;
	int dmin = MAX;
	do{
		connect = -1;
		for(int i =1 ;i<=vertices ; i++){
			if(mark[i]==0){
				if(matran[start][i]!=0 && weight[i]>weight[start]+matran[start][i]){
					weight[i] = weight[start] + matran[start][i];
					back[i] = start;
				}
			}
			if(dmin > weight[i]){
				dmin = weight[i];
				connect = i;
			}
		}
		start = connect;
	}while(connect!=-1 &&  start!=finish);
	printf("\ndmin = %d",dmin);
}
int main(){
	printf("\nOK\n");
	for(int i=1; i<=vertices; i++){
		weight[i] = MAX;
	}
	readdata("xgraphhaveweight.txt");
	printf("\nOK");
	Dijstra(1,10);
	getch();
}
