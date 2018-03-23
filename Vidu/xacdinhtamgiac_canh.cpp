# include <conio.h>
# include <stdio.h>
main()
{
	float a,b,c;
	printf("nhap do dai 3 canh cua 1 tam giac a,b va c\n");
	scanf("%f\n%f\n%f",&a,&b,&c);
	if(a>(b+c)||b>(a+c)||c>(a+b))
	printf("\n khong la 3 canh tam giac");
	else
	     {printf("la 3 canh tam giac");
	     if((a*a==b*b+c*c)||(b*b==c*c+a*a)||(c*c==a*a+b*b))
	                {
	                	if ((a==b)||(b==c)||(a==c))
	                	printf("\t vuong can");
	                	else
	                	printf("\t vuong");
	                }
	     else
		            {
		            	if((a==b)||(b==c)||(a==c))
		            	{
		            		if((a==b)&&(a==c))
		            		printf("\t deu");
		            		else
		            		printf("\t can");
		            	}
		            else
					    printf("\t thuong");	
		            }           
	     }
getch();	     
}
