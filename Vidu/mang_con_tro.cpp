#include <stdio.h>
#include <ctype.h>
#include <conio.h>
void tim_ng(int ma);
main()
{
	int i;
	tt: printf("\n can tim nguoi thu: ");
	    scanf("%d",&i);
	    tim_ng(i);
	    printf("\n Co tiep tuc khong? - C/K");
	    if(toupper(getch())=='C')
	    goto tt;
}
void tim_ng(int ma)
{
	static char *ds[]={"Ma sai","Pham thu Huong","Pham Thi lan","Nong Thi Thu","Nguyen tien Trong"};
	printf("\n\n Ma %d",ma);
	printf(" :%s",(ma<1||ma>10)?ds[0]:ds[ma]);
}
