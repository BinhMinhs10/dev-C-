#include <stdio.h>
#include <conio.h>
main()
{
	struct point_2D
	{
		char ten_diem;
		struct
		{
			float x,y;
		}toa_do;
	}p;
	float temp_float;
	char temp_char;
	printf("\n Hay nhap thong tin ve mot diem");
	printf("\n Ten cua diem:");
	fflush(stdin);
	scanf("%c",&temp_char);
	p.ten_diem=temp_char;
	printf("\n nhap vao hoanh do cua diem:");
	scanf("%f",&temp_float);
	p.toa_do.x=temp_float;
	p.toa_do.y=3*p.toa_do.x+2;
	printf("\n %c=(%5.2f,%5.2f)",p.ten_diem,p.toa_do.x,p.toa_do.y);
	getch();
}
