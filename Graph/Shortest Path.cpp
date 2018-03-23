#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int Matrix[MAX][MAX];//ma tran de luu xem 2 dinh co lien ket voi nhau khong
int path[MAX],goodpath[MAX]; //trong so duong di
int edge,vertice,start,last;
int *Marked = (int *)malloc(100*sizeof(int)); //mang de danh dau dinh da duoc duyet hay chua
int begin=-1,end=-1,stop=0;
int moneny=0,min=100000;

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
void readFile(const char *name){
	FILE* f = fopen(name,"r");
	if(f==NULL){
		fprintf(stderr,"\nCan't open file");
	}
	else{
		int temp1, temp2, temp3;
		fscanf(f,"%d",&vertice);
		fscanf(f,"%d",&edge);
		for(int i = 1 ; i<=vertice ; i++ ){
			for(int j = 1 ; j<=vertice ; j++ )
				Matrix[i][j] = 0;
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
int j=1;
void findPath(int start,int last){
	path[j] = start; j++;
	for(int i = 1 ; i<=vertice ; i++){
		if(Marked[i] == 0 && Matrix[start][i] != 0){
			Marked[i] = 1;
			moneny+=Matrix[start][i];
			if(i==last){
				//printf("\n cost : %d",moneny);
				if(moneny <min){
					min = moneny;
					for(int h=1 ; h<=j ; h++){
						goodpath[h] = path[h];
					}
				}
			}
			else{
				findPath(i,last);
			}
			moneny-=Matrix[start][i];
			Marked[i]=0;
		}
	}
	j--;
}
void DFS(int start){
	Marked[start] = 1;
	printf("%d ",start);
	for(int i = 1; i<=vertice ; i++){
		if(Marked[i] == 0 && Matrix[start][i] != 0){
			DFS(i);
		}
	}
}
int main(){
	readFile("inputPath.txt");
	printMatrix(vertice);
	printf("\nDepth First Search: ");
	for(int i = 1 ; i<=vertice ; i++ ){
		Marked[i] = 0;
	}
	//DFS(1);
	
	for(int i = 1 ; i<=vertice ; i++ ){
		Marked[i] = 0;
	}
	printf("\nnhap lan luot diem bat dau va ket thuc cua duong di: ");
	scanf("%d%d",&start,&last);
	Marked[start] = 1;
	findPath(start,last);
	printf("trong so nho nhat la : %d ",min);
	/*for(int i = 1 ; i<= vertice ; i++){
		printf("->%d",goodpath[i]);
	}*/
	return 0;
}
