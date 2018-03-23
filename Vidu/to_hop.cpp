#include<stdio.h>
int *A, n = 10, x = 1;

void Display(int x){
	while (x > 0)
		{
			printf("%d ",A[x]);
			x = x - 1;
		}
	printf("\n");
}

void Analysis(){
	int i = A[x-1];
	i = i + 1;
	while (i <= (n-1)/2)
		{
			A[x] = i;
			n = n - i;
			++x;
			Analysis();
			--x;
			n = n + i;
			i++;
		}
	A[x] = n;
	Display(x);
}

int main(){
	A = new int[(n>>1+2)];
	A[0] = 0;
	Analysis();
	return 0;
}

