#include <stdio.h>
#include <conio.h>
main()
{
	char diem;
	printf("nhap diem :");
	scanf("%c",&diem);
	switch(diem){
		case('A'):
			printf("Excellent");  break;
		case('B'):
			printf("Very good"); break;
		case('C'):
			printf("Good"); break;
		case('D'):
			printf("you passed!"); break;
		case('E'):
			printf("Better try again"); break;				
	
	default :
		printf("invalid grade"); 
	}
	getch();
}
