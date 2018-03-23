#include <stdio.h>
int n;
int a[30];// mang ghi xau nhi phan

void Print_Sol(){
	for(int i=1;i<=n;i++){
		printf("%d",a[i]);
	}
	printf("\n");
}
void TRY(int k){
	for(int i=0;i<=1;i++){
		a[k] = i;
		if(k==n) Print_Sol();
		else TRY(k+1);
	}
}
int main(){
	printf("\nnhap do dai n = "); scanf("%d",&n);
	TRY(1);
}
