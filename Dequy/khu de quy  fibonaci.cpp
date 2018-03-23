#include <stdio.h>
#include <conio.h>
int Fibiter(int n)
{
	int f1,f2,f3,k;
	if(n<=1) return n;
	else
	{
		f1=0;f2=1;
		for(k=2;k<=n;k++)
		{
			f3=f2+f1;
			f1=f2;
			f2=f3;
		}
		return f3;
	}
}
int main()
{
	for(int i=0;i<9;i++)
	{
		printf("\t%d",Fibiter(i));
		
	}
	
	return 0;
}
