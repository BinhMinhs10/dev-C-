#include <stdio.h>
#include <conio.h>
int main()
{
	FILE *fp;
	fp=fopen("text","wt");
	fprintf(fp,"cac dong");
	for(int i=7;i<=13;i++)  fprintf(fp,"\n Dong %2d",i);
	fclose(fp);
	return 0;
}
