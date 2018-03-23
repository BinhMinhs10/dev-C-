#include <stdio.h>
#include <string.h>
struct Stack{
	char* tag;
	struct Stack *next;
};
Stack *top;
int StackIsEmpty(Stack *p){
	return p==NULL;
}
Stack* push(Stack *p,char* x){
	Stack *q = new Stack;
	strcpy(q->tag,x);
	if(p==NULL){
	 	return q;
	}
	else{
		q->next=p;
		p=q;
	}
	return p;
}
char* pop(Stack *p){
	char* x;
	if(!StackIsEmpty){
		Stack *tmp=p;
		strcpy(x,p->tag);
		return x;
		p=p->next;
		delete tmp;
	}
	return NULL;
}
void printstack(Stack *p){
	Stack *tmp=p;
	while(tmp!=NULL){
		puts(tmp->tag);
		printf("\n");
		tmp=tmp->next;
	}
}
int main(){
	top=push(top,"hello");
	top=push(top,"hell");
	top=push(top,"hel");
	top=push(top,"he");
	char* x;
	strcpy(x,pop(top));
	printstack(top);
	return 0;
}

