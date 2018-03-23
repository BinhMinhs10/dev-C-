#include <stdio.h>
#include <conio.h>
main()
{
	int i=0;
	char d[256];
	FILE *f;
	f=fopen("dong_vd","w");
	//clrscr();
	fflush(stdin);
	while(1){
	
	printf("\n Dong %d (bam emter ket thuc): ",i);
	gets(d);
	if(d[0]=='\0')
	break;
	if(i>1)
	fputc(10,f);
	fputs(d,f);
    }
    fclose(f);
}

