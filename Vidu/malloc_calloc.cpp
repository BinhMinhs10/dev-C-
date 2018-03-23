#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
main()
{
	int *a=(int *)malloc(10*sizeof(int));
	
	double *b=(double *)calloc(10,sizeof(int));
	printf("%d",*(b+1));
}
