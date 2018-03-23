#include <stdio.h>
#include <conio.h>
int array[4]={0,0,0,0},mark[4]={0,0,0,0};
	int n=3;
void permutation(int i,int n){
	if( i==n){
		printf("\n");
		for(int k=0;k<n;k++)
		{
		    printf("array[%d]= %3d  ",k,array[k]);
	    }
	    return;
	}
	for(int j=1;j<=n;j++)
	{
		if(mark[j]==0)
		{
			mark[j]=1; array[i]=j;
			permutation(i+1,3);
			mark[j]=0; array[i]=0;
		}
	}
}
main()
{
	int i;
	printf("nhap i= "); scanf("%d",&i);
	permutation(i,3);
}
