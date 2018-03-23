#include <stdio.h>
#include <conio.h>
main()
{
	FILE *fp;
	fp=fopen("xxxxxxxxx","a");
	if(fp==NULL) perror("loi khi mo tep");
	char c;
	fflush(stdin);
	scanf("%s",&c);
	fputc(c,fp);
	fclose(fp);
	
}
