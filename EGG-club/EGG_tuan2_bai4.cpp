#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
int random(int n)
{
	return rand()%(n+1);
}
main()
{
	char xau[100];
	int t,i;
	typedef struct point
	  {
	  	char temp[100],temp1[100];
	  }mang;
	  mang a[100];
	printf ("Add-new-words chon 1\n");
	printf("learn-words chon 2\n");
	printf("hien thi tat ca tu chon 3\n");
	printf("exit chon 4\n");
	printf("-> ki tu nhap: ");
	fflush(stdin);
	scanf("%d",&t);
	while ((t!=1)&&(t!=2)&&(t!=3)&&(t!=4))
	{
	    printf("-> ban nhap sai so\n"); 
	    printf("ki lai tu nhap: ");
	    fflush(stdin);
	    scanf("%d",&t);
	}
	if(t==1)
	{
	  FILE *fp;
	  int i;
	  fp=fopen("C:\\Users\\ThuyLinh Computer\\Documents\\dev-C++\\dictionary.txt","a");
	  if ((fp=fopen("C:\\Users\\ThuyLinh Computer\\Documents\\dev-C++\\dictionary.txt","a"))==NULL)
	  printf("khong mo duoc tep");
	    else
	  {
		printf("nhap 10 tu tieng anh\n");
		for (i=0;i<10;i++)
		{
			
			printf("%d.. ",i+1);
			{
			  printf("newwords: "); 
			  fflush(stdin);  
			  scanf("%12[^\n]",&a[i+1].temp);
			  fputs((a[i+1].temp),fp);
			  //a[i+1]=read_screen(a[i+1]); 
			  //fwrite(&a[i+1].temp,sizeof(point),1,fp);
			  //putc('\t',fp);
			}
			{
			 printf("tieng viet: ");
			 fflush(stdin);  
			 scanf("%12[^\n]",&a[i+1].temp1);
			 fputs(a[i+1].temp1,fp);
			 //fwrite(&a[i+1].temp1,sizeof(point),1,fp);
			 //putc('\n',fp); 
			}
			 
			printf("\n");
		}
	  }
	 fclose(fp);
    }
    else if(t==2)
    {
      FILE *fp;
      fp=fopen("C:\\Users\\ThuyLinh Computer\\Documents\\dev-C++\\dictionary.txt","r");
     if ((fp=fopen("C:\\Users\\ThuyLinh Computer\\Documents\\dev-C++\\dictionary.txt","r"))==NULL)
	      printf("khong mo duoc tep");
	 else
	 {
	 	int vovan,n;
	 	srand(time(NULL));
	 	int ngaunhien,an=random(9);
	 	fread(&a[an+1].temp,sizeof(40),3,fp);
	 	vovan=strlen (a[an+1].temp);
	 	printf("%d\n",vovan);
	 	//printf("nhap n: "); scanf("%d",&n);
	 	printf("english word: ");
	 	printf("%s \n",a[an+1].temp);
	 	printf("nhap tu tieng viet: ");
	 	fflush(stdin);
	 	scanf("%[^\n]",&xau);
	 	fread(&a[an].temp1,sizeof(40),3,fp);
	 	if((strcmp(xau,a[an+1].temp1))==0)
	 	{
	 		printf("ban nhap dung");
	 	}
	 	else 
	 	  printf("ban chua thuoc tu");
	 }
	  fclose(fp);
    }
    else if(t==3)
    {
    	FILE *fp;
        fp=fopen("C:\\Users\\ThuyLinh Computer\\Documents\\dev-C++\\dictionary.txt","r");
        if ((fp=fopen("C:\\Users\\ThuyLinh Computer\\Documents\\dev-C++\\dictionary.txt","r"))==NULL)
	             printf("khong mo duoc tep");
    	else
    	{
    		char ch;
	 	    while ((ch=getc(fp))!=EOF)
	 	  {
	 	     putc(ch,stdout);   
	      }
	         printf("%s",ch);
    	}
    	fclose(fp);
    } 
    else if (t==4)
      printf("an phim bat ki de thoat? ");
	getch();
}
