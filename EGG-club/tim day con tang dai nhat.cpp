#include <stdio.h>
#include <conio.h>
#define max 100
static int n;
int a[max];
int dem=0, i=0;
void readfile(char *fn)
{
	FILE *f;
	if((f=fopen(fn,"r"))==NULL)
	{
		printf("\nkhong mo duoc file");
	}
	else
	{
		fscanf(f,"%d",&n);
		for(int i=0;i<n;i++)
		{
			fscanf(f,"%d",&a[i]);
		}
	}
	fclose(f);
}
void process()
{
	while(i<n)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]<a[j])
			{
				dem++;
				i=j;
				break;
			}
		}
	}
	printf("\nday con co do dai dai nhat la: %d",dem);
}
int main()
{
	char filename[40];
	printf("\n nhap ten file: "); scanf("%s",&filename);
	readfile(filename);
	printf("%d",n);
	process();
	return 0;
}
