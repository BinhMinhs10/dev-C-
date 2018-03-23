#include <stdio.h>
#include <conio.h>
#include <math.h>
int MAXSIZE=50;
int top=-1;
int stack[50];

int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}


int pop() {
   int data;
	
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   }else {
      printf("Khong the thu thap du lieu, ngan xep (Stack) la trong.\n");
   }
}

int push(int data) {

   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
   }else {
      printf("Khong the chen du lieu, ngan xep (Stack) da day.\n");
   }
}
int stackconvert(int n,int b)
{
	int c=0,a;
	while(n!=0)
	{
		push(n%b);
		n=n/b;
	}
	while(!isempty()) {
	   a=10*c;
      int data = pop();
      c=data+a;
   }
   return c;
}
int convert(int n,int b)
{
	if((n==0)||(b==10)) return n;
	int a;
	a=n%b;
	return a+10*convert(n/b,b);
	
}
int iterconvert(int n,int b)
{
	int count=0,a;
	int c=0;
	if((n==0)||(b==10)) return n;
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
	int n,b;
	printf("nhap so n va co so b lan luot: "); scanf("%d%d",&n,&b);
	printf("\n so %d  doi sang so so dung de quy %d la: %d",n,b,convert(n,b));
	printf("\n so %d  doi sang so so dung vong lap %d la: %d",n,b,iterconvert(n,b));
	printf("\n so %d doi sang co so %d la: %d ",n,b,stackconvert(n,b));
	
	getch();
}
