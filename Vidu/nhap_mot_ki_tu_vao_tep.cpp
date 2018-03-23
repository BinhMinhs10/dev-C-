#include <stdio.h>
#include <ctype.h>
#include <conio.h>
main()
{
	
	FILE *fptr;
	char c;
	if((fptr=fopen("D:\\minh","r+w"))==NULL)
	    printf("\a\n co loi, khong mo duoc tep de doc");
	else
	putchar(c=getc(fptr));
	while(c!='\n');
	fclose(fptr);
}
