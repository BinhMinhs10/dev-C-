#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void sinh_matrancapn()
{
	char filename[40];
	int n;
	printf(" ten tep: "); scanf("%s",filename);
	FILE *fp;
	fp=fopen(filename,"w");
	printf("\n so luong phan tu mang: ");  scanf("%d",&n);
	fprintf(fp,"%d\n",n);
	srand(time(0));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			fprintf(fp,"\t%d",rand()%200);
		}
	   	fputs("\n",fp);
	}
	fclose(fp);
}
