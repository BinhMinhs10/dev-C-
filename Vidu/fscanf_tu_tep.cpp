#include <stdio.h>
#include <conio.h>
int main()
{
	FILE *fp;
	int c;
	fp=fopen("C:\\Users\\ThuyLinh Computer\\Documents\\dev-C++\\da_giac.txt","rt");
	while(!feof(fp))
	   {
	     fscanf(fp,"%d",&c);
	     
	     printf("%d\n",c);
       }
    fclose(fp);
	getch();
	
}
