#include <stdio.h>
int m,n,a[30];

void Print_Sol(){
	for(int i=1;i<=m;i++){
		printf("%2d",a[i]);
	}
	printf("\n");
}
void TRY(int k){
	for(int i=a[k-1]+1;i<=n-m+k;i++){
		a[k]=i;
		if(k==m) Print_Sol();
		else TRY(k+1);
	}
}
int main(){
	a[0]=0;
	printf("\ncombination\n");
	printf("\nnhap n = "); scanf("%d",&n);
	printf("\nnhap m = "); scanf("%d",&m);
	TRY(1);
}
