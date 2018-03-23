#include <stdio.h>
#include <stdlib.h>
struct StackNode{
	int sodu;
	struct StackNode *next;
};
struct Stack{
	struct StackNode* top;
};
Stack* Init(){
	Stack *s;
	s = (Stack *)malloc(sizeof(Stack));
	if(s==NULL) return 0;
	else return s;
}

int StackEmpty(Stack *s){
	if(s==NULL) return 1;
	return 0;
}
int push(Stack *s,int k){
	if(s==NULL) return 0;
	else{
		StackNode * New = (StackNode*) malloc(sizeof(StackNode));
		New->sodu=k;
		New->next=s->top;
		s->top=New;
		return 1;
	}
}
int pop(Stack* s){
	if(s==NULL ){
		printf("\nCan't pop in stack!");
		return 0;
	}
	else{
		int x;
		StackNode *temp=s->top;
		x=temp->sodu;
		s->top=temp->next;
		delete(temp);
		return x;
	} 
}
int main(){
	int n,b;
	printf("\nnhap so n = "); scanf("%d",&n);
	printf("\nnhap co so b = "); scanf("%d",&b);
	Stack *s=Init();
	int count =0;
	printf("so %d co co so %d duoc beu dien la ",n,b);
	while(n!=0){
		push(s,n%b);
		n=n/b;
		count++;
	}
	for(int i=0;i<count ;i++){
		printf("%d",pop(s));
	}
}
