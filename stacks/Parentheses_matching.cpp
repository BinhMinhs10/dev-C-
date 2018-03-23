#include <stdio.h>
#include <conio.h>
char y;
char x[]={'(',')','[',']','}'};
struct Node{
	char info;
	Node *next;
};
Node* top=NULL;
int stackempty()
{
	if(top==NULL)
	    return 1;
	else
	return 0;
	
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
	char x=tmp->info;
	top=top->next;
	delete tmp;
	return x;
}
int checkmatch(char x,char y)
{
	if(x=='('&&y==')') return 1;
	if(x=='['&&y==']') return 1;
	if(x=='{'&&y=='}') return 1;
	return 0;
}
int check()
{
	for(int i=0;i<6;i++)
	{
		if(x[i]=='['||x[i]=='{'||x[i]=='(')
			push(x[i]);
		else if(x[i]==']'||x[i]=='}'||x[i]==')')
		  {
			if(stackempty())
			     return 0;
			else
			{
				y = pop();
				if(checkmatch(x[i],y)==0) 
				  return 0;   
			}
			
		  }
    }
    
	if(stackempty()) return 1;
	else return 0;
}
int main()
{
	
	if(check()==0)
	printf("\n day thoa man");
	else 
	printf("\n day khong thoa man");
}
