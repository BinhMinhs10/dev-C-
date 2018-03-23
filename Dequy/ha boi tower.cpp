#include <stdio.h>
#include <stdlib.h>
int count;
void move(int n,char a,char b,char c)
{
	if(n==1)
	{
		count++;
		printf("step %d move %c->%c",count ,a,b);
	}
	else{
		move(n-1,a,c,b);
		move(1,a,b,c);
		move(n-1,b,c,a);
	}
}
int main(int argc,char** argv)
{
	int n;
	n=atoi(argv[1]);
	move(n,'A','B','C');
}
