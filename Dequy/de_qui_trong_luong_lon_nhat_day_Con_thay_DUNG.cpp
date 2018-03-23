#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 100;
int n;
int a[100];
int maxLeft(int* a, int l, int r){
	int max = -9999999;
	int s = 0;
	for(int i = r; i >= l; i--){
		s += a[i];
		if(s > max) max = s;
	}
	return max;
}

int maxRight(int* a, int l, int r){
	int max = -99999999;
	int s = 0;
	for(int i = l; i <= r; i++){
		s += a[i];
		if(s > max) max = s;
	}
	return max;
}

int maxSeq(int* a, int l, int r){
	if(l == r) return a[l];
	
	int max;
	int mid = (l+r)/2;
	int mL = maxSeq(a,l,mid);
	int mR = maxSeq(a,mid+1,r);
	int mLR = maxLeft(a,l,mid) + maxRight(a,mid+1,r);
	
	max = mL;
	if(max < mR) max = mR;
	if(max < mLR) max = mLR;
	return max;
}

void algo3(){
	int *a;
	int max = maxSeq(a,0,n-1);
	printf("algo3, result = %d\n",max);
}
int main()
{
	printf("\n nhap so phan tu cua day: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
			printf("\na[%d]= ",i+1);
			scanf("%d",&a[i]);
	}
	algo3();
	

	return 0;
}
