#include <conio.h>
#include <stdio.h>
int main()
{
	FILE *fp=fopen("E:\\input.txt","r");
	int n,a[100],b[100];
	if(fp==NULL){
		printf("khong mo duoc file");
	}
	else{
	    fflush(stdout);
	    fscanf(fp,"%d",&n); printf("%d\n",n);
	    fflush(stdin);
	    for(int i=0;i<n;i++)
	   {
		fscanf(fp,"%d",&a[i]);
		printf("%d",a[i]);
	   }
	   printf("\n");
	    for(int i=0;i<n;i++)
	   {
		fscanf(fp,"%d",&b[i]);
		printf("%d",b[i]);
	   }
    }
    int i,j,temp,k;
    for(i=1;i<n;i++)
    {
    	temp=a[i];
    	j=i-1;
    	while((j>=0)&&(a[j]>temp))
    	{
    		a[j+1]=a[j];
    		k=b[j+1];
    		b[j+1]=b[j];
    		b[j]=k;
    		j--;
    	}
    	a[j+1]=temp;
    }
     printf("\n");
    printf("xau sau sap xep: ");
    for(i=0;i<n;i++)
    {
    	printf("%d",b[i]);
    }
	fclose(fp);
	FILE *fpout=fopen("E:\\output.txt","w");
	for(i=0;i<n;i++)
	{
		fprintf(fpout,"%2d",a[i]);
	}
	fprintf(fpout,"\n");
	for(i=0;i<n;i++)
	{
		fprintf(fpout,"%2d",b[i]);
	}
	fclose(fpout);
	getch();
	return 0;
}
