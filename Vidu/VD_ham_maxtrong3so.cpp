#include <stdio.h>
#include <conio.h>
int max(int x,int y,int z)
{
	int max;
	max=(x>y)?x:y;
	max=max>z?max:z;
	return max;
}

int main()
{
	int a,b,c;
	fflush(stdin);
	printf("\n nhap gia tri 3 so nguyen a,b,c;");
	scanf("%d %d %d",&a,&b,&c);
	printf("\ngia tri cac so vua nhap: ");
	printf("a=%-5d b=%-5d c=%-5d",a,b,c);
	printf("\ngia tri lon nhat trong 3 so la: %d",max(a,b,c));
	getch();
	return 1;
	
	
}

