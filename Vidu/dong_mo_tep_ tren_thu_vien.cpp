#include <stdio.h>
#include <conio.h>
main()
{
	int c;
	char t1[14],t2[14];
	FILE *f1,*f2;
	printf("\n TEN NGUON:");
	gets(t1);
	printf("\n TEN DICH");
	gets(t2);
	f1=fopen(t1,"rb");
	if(f1==NULL)
	{
		printf("\n Tep %s khong ton tai",t1);
		getch();
		//exit(1);
	}
	f2=fopen(t2,"wb");
	while((c=fgetc(f1))!=EOF)
	fputc(c,f2);
	fclose(f1);
	fclose(f2);
}
