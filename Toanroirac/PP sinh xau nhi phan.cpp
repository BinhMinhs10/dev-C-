#include <stdio.h>
int n, stop=0;
int a[30];  //mang luu xau nhi phan

void Print_Sol(){
	for(int i=0;i<n ;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
int Check_Sol(){
	for(int i=0;i<n;i++){
		if(a[i]==0){
			return 1;
		}
	}
	return 0;
}
void Next_Strings(){
	for(int i = n-1 ; i>=0 ; i--){
		if(a[i] == 0){
			a[i]=1;
			for(int j = i+1; j < n ; j++){
				a[j] = 0;
			}
			break;
		}
		else
		    a[i] = 0;
	}
}
int main(){
	printf("\nnhap do dai xau nhi phan n: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		a[i]=0;
	}
	while(!stop){
		Print_Sol();
		if( Check_Sol() == 1 )
     		Next_Strings();
		else 
		    stop = 1;
	}
	
}
