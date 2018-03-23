#include <stdio.h>
#include <stdlib.h>
main(int argc,char *argv[])
{
	int ch;
	char filename[40];
	FILE *fp;
	long count=0; 
	printf("ten tep: ");
	scanf("%s",filename);
	fp=fopen(filename,"r");
	if((fp=fopen(filename,"r"))==NULL)
	  printf("loi khong mo duoc tep");
	else{
	
	  while ((ch=getc(fp))!= EOF)
	 {
		putc(ch,stdout);
		count++;
		
	 }
	 fclose(fp);
	 printf("\n tep %s co %ld ki tu \n",filename,count);
	 return 0;
    }
}
