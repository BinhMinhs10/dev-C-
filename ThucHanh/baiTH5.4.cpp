#include <stdio.h>
#include <conio.h>
#include <string.h>
int main()
{
	int n,i,j;
	char dslop[10][30];
	char *name[10];
	char *tempt;
	do{
		
		printf("\n tong so hoc sinh: ");  scanf("%d",&n);
		for(i=0;i<n;i++)
		{
		  name[i]= new char[25];
		  printf("\nnhap ten cua hoc sinh thu %d:",i);
		  fflush(stdin);
		  gets(name[i]);
	    }
		
	}while(n>10);
	
    printf("Sap xep theo thu tu tang dan : ");
    for(i = 0;i<n;i++){
     for ( int j = i+1 ; j < n ; j++)
	 if(strcmp(name[i],name[j])>0)
      {
         tempt = name[i];
         name[i] = name[j];
         name[j] = tempt;
      }
     }
     
	
       printf("Cac ten sau khi da xap xep xong: ");
       for(i=0;i<7;i++)
       printf("\n %s",name[i]); 
       getch();
	
}
