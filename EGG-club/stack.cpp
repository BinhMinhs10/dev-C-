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
int main()
{
	
}
