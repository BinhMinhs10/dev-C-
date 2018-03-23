#include <stdio.h>
#include <conio.h>
#include <math.h>
#define max 100
int n,c;
int xau[max];
int iterconvert(int n,int b)
{
	int count=0,a;
	int c=0;
	if(n==0) return n;
	while((n!=0))
	{
		a=n%b;
		c=c+a*(pow(10,count));
		count=count+1;
		n=n/b;
	}
	return c+1;
}
int main()
{
	do{
		printf("\n nhap do dai xau nhi phan (n<=10^4): ");
		scanf("%d",&n);
	}while((n<0)||(n>pow(10,4)));
	int count=0,temp,flag=c;
	tt:
	do{
	   	printf("\n nhap xau nhi phan do dai %d la: ",n);
        scanf("%d",&c);
        while(count==n)
        {
        	temp=flag%10;
        	if((temp!=1)&&(temp!=0))
        	{
        		printf("\nban nhap sai xau nhi phan ^_^");
        		goto tt;
        	}
        	flag=c/10;
        	count++;
        }
	}while(count!=n); 
    printf("\n xau vua nhap: %d",c);
	printf("\n so %d doi sang co so 2 la: %d",n,iterconvert(n,2));
	return 0;
}
