#include <stdio.h>
#include <stdlib.h>

int n;
int S;
int a[100];
int t;// store the sum

void process(){
	a[n] = S - t;
	//if(t == S){
	for(int i = 1;i <= n; i++) printf("%d ",a[i]);
	printf("\n");
	//}
}

void TRY(int k){// try values for a[k] being aware of a[1..k-1]
	for(int v = 1; v <= S-(t + n - k); v++){
		a[k] = v;
		t += a[k];
		
		if(k == n - 1)
			process();
		else
			TRY(k+1);
		t -= a[k];// recover
	}		
}

int main(int argc, char** argv){
	printf("nhap n= ");     scanf("%d",&n);
	printf("\nnhap S= ");   scanf("%d",&S);
	printf("\nn = %d, S = %d\n",n,S);
	t = 0;
	TRY(1);
}
