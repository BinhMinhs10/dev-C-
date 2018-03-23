#include <stdio.h>
int m,n,stop=0;
int a[30]; //mang luu cac phan tu tap con cua n do dai m

void Print_Sol(){
	for(int i=0;i<m;i++){
		printf("%2d",a[i]); 
	}
	printf("\n");
}
int Check(){
	for(int i=0;i<m;i++){
		if(a[i] != (n-m+i+1) ) return 1;
	}
	return 0;
}
void Next_Combination(){
	for(int i = m-1;i>= 0; i--){
		if(a[i]!= (n-m+i+1)){
			a[i] = a[i] + 1;
			for(int j=i+1; j<m ;j++){
				a[j]= a[j-1]+1;
			}
			break;
		}
	}
}
int main(){
	printf("\nnhap m = "); scanf("%d",&m);
	printf("\nnhap n = "); scanf("%d",&n);
	for(int i=0;i<m;i++){
		a[i]=i+1;
	}
	while(!stop){
		Print_Sol();
		if(Check() == 1){
			Next_Combination();
		}
		else 
		    stop = 1;
	}
}
