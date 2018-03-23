#include <stdio.h>
#include <conio.h>
char doc(int x)
{
	switch (x)
	{
		case 0: printf("khong"); break;
		case 1: printf("mot"); break;
		case 2: printf("hai"); break;
		case 3: printf("ba"); break;
		case 4: printf("bon"); break;
		case 5: printf("nam"); break;
		case 6: printf("sau"); break;
		case 7: printf("bay"); break;
		case 8: printf("tam"); break;
		case 9: printf("chin"); break;
	}
}
main()
{
	
	signed int x;
	 do{
		printf("nhap so cua ban(1<x<1000): ");
		scanf("%d",&x);
	}while((x>1000)||(x<1));

	printf("\nso %d doc la: ",x);
	{
	 //doc(x/1000); printf(" nghin ");
	 doc(x/100); printf(" tram ");
	 doc((x-(x/100)*100)/10); printf(" muoi ");
	 doc((x-(x/10)*10)); 
    }
	getch();
}
