#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct Node{
	char info;
	Node *next;
};
Node *top=NULL;//pointer to the top of stack
int stackempty()
{
	return top==NULL;
}
void push(char x)
{
	Node* p=new Node;
	p->info=x;
	p->next=top;
	top=p;
}
char pop()
{
	Node* tmp=top;
	char x;
	x=top->info;
	top=top->next;
	delete tmp;
	return x;
}
int main()
{
	for(int i=1 ; i<7 ; i++){
		push(i);
	}
	int dem;
	printf("\n lay may phan tu: "); scanf("%d",&dem);
	while(dem!=0){
		printf("\nlay phan tu %d",pop());
		dem--;
	}
	while(!stackempty())
	{
		printf("\n %d",top->info);
		top=top->next;
	}
}
