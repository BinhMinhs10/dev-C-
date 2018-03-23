#include <stdio.h>
#include <conio.h>
int n,stop=0;
int a[30]; // mang de luu cac hoan vi n phan tu
int count = 0;

void Print_Sol(){
	count++;
	for(int i=1;i<=n;i++){
		printf("%2d",a[i]);
	}
	printf("\n");
}
void Swap(int *a,int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int Check(){
	for(int i=1;i<=n;i++){
		if(a[i] != n-i+1 ) return 1;
	}
	return 0;
}
void Next_Permutation(){
	int i=n-1;
    int k=n;
    while(a[i]>a[i+1]) i--;
    while(a[k]<a[i]) k--;
    Swap(&a[k],&a[i]);
    int r=n,s=i+1;
    while(r>s)
    {
        Swap(&a[r],&a[s]);
        r--;
        s++;
    }
}
int main(){
	printf("\nnhap so phan tu n = "); scanf("%d",&n);
	
	for(int i=1;i<=n;i++){
		a[i] = i;
	}
	
	while(!stop){
		Print_Sol();
		if(Check() == 1){
			Next_Permutation();
		}
		else stop = 1;
	}
	
	printf("\nso hoan vi la : %d",count);
	getch();
	return 1;
}
