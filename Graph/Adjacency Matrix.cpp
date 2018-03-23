#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int Matrix[MAX][MAX];//ma tran de luu xem 2 dinh co lien ket voi nhau khong
int edge,vertice,start;
int *Marked = (int *)malloc(100*sizeof(int)); //mang de danh dau dinh da duoc duyet hay chua
int begin=-1,end=-1,stop=0;
int* queue=(int*)malloc(100*sizeof(int));
int isEmpty()
{
	if(begin==end)
	return 1;
	return 0;
}
void pushQueue(int x)
{
	queue[end]=x;
	end++;
}
int popQueue()
{
	if(isEmpty() == 1){
		return -1;
	}else{
		int temp = queue[begin];
		free( queue + begin );
		begin++;
		return temp;
	}
}
int del,insert,degree,tmp[30];

void readFile(const char *name){
	FILE* f = fopen(name,"r");
	if(f == NULL){
		fprintf(stderr,"\nCan't open file");
	}
	else{
		int temp1, temp2;
		fscanf(f,"%d",&vertice);
		fscanf(f,"%d",&edge);
		for(int i = 1 ; i<=vertice ; i++ ){
			for(int j = 1 ; j<=vertice ; j++ )
				Matrix[i][j] = 0;
		}
		while(!feof(f)){
			fscanf(f,"%d",&temp1);
			fscanf(f,"%d",&temp2);
			Matrix[temp1][temp2] = 1;
			Matrix[temp2][temp1] = 1;
		}
	}
	fclose(f);
}
void printMatrix(int n){
	printf("\nMatrix :\n");
	for(int i = 1; i<= n; i++ ){
		for(int j=1;j<= n ; j++){
			printf("%d ",Matrix[i][j]);
		}
		printf("\n");
	}
}
void DFS(int start){
	Marked[start] = 1;
	printf("%d ",start);
	for(int i = 1; i<=vertice ; i++){
		if(Marked[i] == 0 && Matrix[start][i] == 1){
			DFS(i);
		}
	}
}
void BFS(int start){
	Marked[start] = 1;
	printf("%d ",start);
	for(int i=1 ; i<=vertice ; i++ ){
		if(Matrix[start][i] == 1 && Marked[i] == 0){
			Marked[i] = 1;
			pushQueue(i);
		}
	}
	int temp = popQueue();
	if(temp == -1) return;
	BFS(temp);
}
void initMarked(){
	for(int i = 1 ; i<=vertice ; i++ ){
		Marked[i] = 0;
	}
}
void deleteVertice(int x){
	for(int i=1 ; i<=vertice ; i++){
		Matrix[i][x] = 0;
		Matrix[x][i] = 0;
	}
	if(x == vertice){
		vertice--;
	}
}
void insertVertice(){
	printf("\ninsert vertice : "); scanf("%d",&insert);
	printf("\ndegree of vertice %d : ",insert);
	if(insert <= vertice){
		fprintf(stderr,"\nVertice has been");
		return;
	}
	scanf("%d",&degree);
	printf("\nlan luot cac edge is: ");
	for(int i = 0;i<degree ;i++){
		scanf("%d",&tmp[i]);
	}
	for(int j=0; j<degree ; j++){
		Matrix[insert][tmp[j]] = 1;
		Matrix[tmp[j]][insert] = 1;	
	}
	vertice = insert;
}
int main(){
	readFile("inputGraph.txt");//
	printMatrix(vertice);
	
	//Duyet Graph
	printf("\nnhap dinh bat dau duyet graph: "); scanf("%d",&start);
	printf("\nduyet theo Depth First Search: ");
	initMarked();
	DFS(start);
	printf("\nduyet theo Breadth First Search: "); 
	initMarked();
	BFS(start);
	
	//Thao tac tren Graph
	printf("\ndelete vertice : "); scanf("%d",&del);
	deleteVertice(del);
	printMatrix(vertice);
	
	insertVertice();
	printMatrix(vertice);
	return 0;
}
