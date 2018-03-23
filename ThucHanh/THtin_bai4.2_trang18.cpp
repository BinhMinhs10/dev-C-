# include <conio.h>
# include <stdio.h>
main()
{
	float a;
	printf("nhap so nguyen:");
	scanf("%f",&a);
	if((a<0)||(a>9))
	 printf("SO KHONG HOP LE");
	else
	 {
	 	if(a==0) printf("KHONG");
	 	if(a==2)
	 	printf("HAI");
	 	if(a==3)
	 	printf("BA");
	 	if(a==1)
	 	printf("MOT");
	 	
	 } 
}
