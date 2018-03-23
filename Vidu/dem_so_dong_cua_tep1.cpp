#include <stdio.h>
#include <conio.h>
//#define EOF -1
#define EOL '\n'
main()
{
  char s[40];
  int ch,dem;
  FILE *fp;
  printf("Ten tep:");
  scanf("%s",s);
  fp=fopen(s,"r");
  if((fp=fopen(s,"r"))==NULL)
  {
  printf("khong mo duoc tep");
     
  }
  else
  {
      ch=getchar();
     while (ch!= EOF)
   {
	while (ch!=EOL)
	{
	 ch=getchar();
	  dem++;
    }
	ch=getchar();
   }
  }
  printf("so dong %d ",dem);
  getch();
  
}
