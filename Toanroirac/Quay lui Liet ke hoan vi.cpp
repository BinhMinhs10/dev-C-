#include <stdio.h>
int n,a[30];

void Print_Sol(){
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
int UCV(int j,int h){
	for(int i=1;i<h;i++){
		if(a[i]==j) return 0;
	}
	return 1;
}
void TRY(int k){
	for(int i=1;i<=n;i++){
		if(UCV(i,k)){
			a[k]=i;
			if(k==n) Print_Sol();
			else TRY(k+1);
		}
	}
}
int main(){
	printf("\nnhap n = ");
	scanf("%d",&n);
	TRY(1);
}
