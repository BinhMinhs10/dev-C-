#include <conio.h>
#include <stdio.h>
main()
{
	unsigned long a,b;
	//----------------------------nhap du lieu tu file--------------------------
	FILE *f;
	f=fopen("C:\\Users\\ThuyLinh Computer\\Documents\\dev-C++\\BAITAP.INP","w");
	if(f==NULL) perror("khong mo duoc file");
	else
	{
		do   {printf("nhap A (0<A<999999)= ");   fflush(stdin);  scanf("%u",&a); } 
		while((a>999999)||(a<0));
		fprintf(f,"%lu",a);
		do   {printf("\nnhap so B(0<B<9999999)= ");  fflush(stdin);   scanf("%u",&b);} 
		while((b>999999)||(b<0));
		fprintf(f,"\n%lu",b);
	}
	fclose(f);
	//--------------------------tinh tong---------------------------------------
	
}
