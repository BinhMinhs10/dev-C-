#include <stdio.h>
#include <stdlib.h>
struct StackNode{
	int value;
	StackNode *Next;
};
struct Stack{
	StackNode *top;
};
//khoi tao stack
Stack* Init(){
	Stack *s =(Stack *) malloc(sizeof(Stack));
    s->top=NULL;
    return s;
}
int StackEmpty(const Stack *s){
	if(s->top==NULL) return 1;
	return 0;
}
int StackPush(Stack *s, int item){
	{
		StackNode *New =(StackNode*) malloc(sizeof(StackNode));
		New->value=item;
		New->Next=s->top;
		s->top=New;
		return 1;
	}
}
int pop(Stack *s){
	
	if(StackEmpty(s)) return 0;
	else{
		int x;
		StackNode *temp=s->top;
	    x=(temp->value);
	    s->top=temp->Next;
	    delete temp;
	    return x;
	}
}
void readdata(char *name,Stack *s){
	FILE * f=fopen(name,"r");
	if(f==NULL) printf("can't open file!");
	else{
		int Temporary=-2;
		while(Temporary!=-1){
			fscanf(f,"%d",&Temporary);
			if(Temporary!=-1)
			StackPush(s,Temporary);
		}
	}
	fclose(f);
}
void PrintStack(Stack *s){
	StackNode *node=s->top;
	if(node==NULL) printf("\nStack Empty");
	while(node!=NULL){
		printf("%d ",node->value);
	    node=node->Next;
	}
}
int main(){
	int n;
	Stack *s = Init();
	readdata("data.txt",s);
	
	PrintStack(s);
	printf("\n muon lay may phan tu :  "); scanf("%d",&n);
	for(int i=1;i<=n;i++){
		 pop(s);
	}
	//printf("\nOK\n");
	PrintStack(s);
	
	return 0;
}
