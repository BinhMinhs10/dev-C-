#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	char filename[40];
	int n;
	printf(" ten tep: "); scanf("%s",filename);
	FILE *fp;
	fp=fopen(filename,"w");
	printf("\n so luong phan tu mang: ");  scanf("%d",&n);
	fprintf(fp,"%d",n);
	srand(time(0));
	for(int i=0;i<n;i++)
	{
	   fprintf(fp,"\t%d",-100+rand()%200);	
	}
	fclose(fp);
}
