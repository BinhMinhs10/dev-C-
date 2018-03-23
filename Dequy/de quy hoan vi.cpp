#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int n;
int a[MAX];
bool marked[MAX];
int count;
void process(){
	count++;
	printf("config %d: ",count);
	for(int i = 1; i <= n; i++) printf("%d ",a[i]);
	printf("\n");
}
void TRY(int k){// try all values for a[k] being aware of a[1...k-1]
	int v;
	for(v = 1; v <= n; v++){
		if(marked[v] == false){
			a[k] = v;
			marked[v] = true;
			if(k == n){
				process();
			}else{
				TRY(k+1);
			}
			marked[v] = false;// recover
		}		
	}		
	
}

int main(int argc, char** argv){
	printf("\n nhap n= "); scanf("%d",&n);
	for(int v = 1; v <= n; v++)  marked[v] = false;
	count = 0;
	TRY(1);
}
