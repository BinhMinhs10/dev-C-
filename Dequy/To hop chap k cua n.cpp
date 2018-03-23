#include <stdio.h>
#define MAXN 40
int M[MAXN][MAXN];//de quy dung mang 2 chieu de luu
int n,k;
int x[MAXN],Mark[]={};
void printSol(){
	for(int i=1 ; i<=k ; i++){
		printf("%d ",x[i]);
	}
	printf("\n");
}
void TRY(int h){
	//xay dung xong x1, x2, ..x(k-1)
	for(int i=x[h-1]+1; i<=n-k+h ;i++){
		if(Mark[i]==0){
			Mark[i] = 1;
			x[h] = i;
			if(h==k){
				printSol();
			}
			else{
				TRY(h+1);
			}
			Mark[i] = 0;
		}
	}
}
int main(){
	printf("\nLiet ke To hop voi n,k Lan luot la: ");
	scanf("%d",&n); scanf("%d",&k);
	TRY(1);
}
