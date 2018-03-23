#include <stdio.h>
#include <stdlib.h>
struct Stack{
	int value;
	struct Stack *next;
};
Stack *top = NULL;
int isStackEmpty(Stack* t){
	return t == NULL;
}
void pushStack(int x){
	Stack *temp = new Stack;
	temp->value = x;
	temp->next = NULL;
	if(isStackEmpty(top)){
		top = temp;
	}
	else{
		temp->next = top;
	    top = temp;
	}
	
}
int popStack(){
	Stack *temp = top;
	int x = temp->value;
	top = temp->next;
	delete temp;
	return x;
}

int main(){
	int i;
	for(i=0 ; i<7 ; i++){
		pushStack(i);
	}
	Stack* t = top;
	while(!isStackEmpty(t))
	{
		printf(" %2d",t->value);
		t = t->next;
	}
	int dem,x;
	
	do{
		printf("\nlay may phan tu: "); 
		scanf("%d",&dem);
	}while(dem>i);
	
	while(dem!=0){
		x = popStack();
		if(x==-1) break;
		dem--;
	}
	t = top;
	while(!isStackEmpty(t))
	{
		
		printf(" %2d",t->value);
		t = t->next;
	}
}
