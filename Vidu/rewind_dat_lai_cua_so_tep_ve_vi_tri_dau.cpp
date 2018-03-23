#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
main()
{
	char str[80];
	FILE *fp;
	if((fp=fopen("TEST","w+"))==NULL)
	{
	  printf("khong the mo tep\n");
	  exit(1);
    }
    do{
    	printf("hay vao xau ki tu (enter de ket thuc):\n");
    	gets(str);
    	strcat(str,"\n");
    	fputs(str,fp);
    }while(*str!='\n');
    rewind(fp);
	while(!feof(fp)){
		fgets(str,79,fp);
		printf(str);
	}
	getch();
}
