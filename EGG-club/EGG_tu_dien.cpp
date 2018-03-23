#include <stdio.h>
#include <conio.h>
main()
{
	int i,temp=0;
	char c,n,l;
	FILE *tumoi=fopen("dictionary.txt","wt");
	do{
		printf("add new words\n");
	
	       for(i=0;i<10;i++)
	     {
	     	 printf("word: ");
	     	 fflush(stdin);
	     	 scanf("%s",&c); 
			 fscanf(tumoi,"%s",&c); 
			 printf("nghia tieng viet:");
			 fflush(stdin);
			 scanf("%s",&n);
			 printf("\n");
	     }
	     printf("\n");
	          
	          do{
		       //printf("nhap khong dung\n");
			   printf("tiep tuc nhap 10 tu(Y/N)? ");
			   fflush(stdin);
			   scanf("%c",&l);
			   if((l=='y')||(l=='Y'))
	           temp=1;
		     } while((l!='y')&&(l!='Y')&&(l!='n')&&(l!='N'));
    }while(temp==1);
    
    fclose(tumoi);
    getch();
}
