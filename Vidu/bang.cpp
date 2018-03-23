#include <stdio.h>
#include <conio.h>
 int f(signed int a,signed int b){
 	return (a*b);
 }
main(){
	int a=1,b=1,i;
	printf("    | ");
	while(a<11)
	{
		printf ("%4d",a);
		a=a+1;
	};
	printf("\n");
	for(i=0;i<50;i++)
	printf("-"); printf("\n");
	for(b=1;b<11;b++)
	{
		int a=1;
		printf(" %2d | ",b);
		for(a=1;a<11;a++){
		printf("%4d",f(a,b));}
		
		printf("\n");
	}
	getch();
	
}
