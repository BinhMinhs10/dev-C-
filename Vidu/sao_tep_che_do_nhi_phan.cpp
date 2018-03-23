#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
main()
{
	FILE *f1,*f2;
	char s;
	int c;
	char s1[14],s2[14];
	fflush(stdin);
	printf("\n TEP NGUON: "); gets(s1);
	printf("\n TEP DICH: "); gets(s2);
	f1=fopen(s1,"rb");
	if(f1==NULL)
	{
		printf("TEP %s khong ton tai",s1);
		getch();
		exit (1);
	}
	f2=fopen(s2,"wb");
	while((c=fgetc(f1))!=EOF)
	fputc(c,f2);
	fclose(f1);
	fclose(f2);
	
}

