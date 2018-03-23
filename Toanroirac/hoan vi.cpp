#include <stdio.h>
#include <stdlib.h>
int n, stop=0;
int a[50];  //mang luu xau nhi phan
int day[50];
long int k;//day nhi phan
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
void Print_Sol(){
	printf("\n");
	for(int i=0;i<n ;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
int Check_Sol(){
	for(int i=0;i<n;i++){
		if(a[i]==0){
			return 1;
		}
	}
	return 0;
}
void Next_Strings(){
	for(int i = n-1 ; i>=0 ; i--){
		if(a[i] == 0){
			a[i]=1;
			for(int j = i+1; j < n ; j++){
				a[j] = 0;
			}
			break;
		}
		else
		    a[i] = 0;
	}
}
int Find(){
	for(int i=0;i<n;i++){
		if(a[i]!=day[i]) return 0;
	}
	return 1;
}
int main(){
	do{
		printf("\nnhap do dai xau nhi phan n: ");
	    scanf("%d",&n);
	}while(n>10000||n<0);
	
	printf("\nnhap day so nhi phan co do dai %d: ",n);
	scanf("%ld",&k);
	
	Stack *s = Init();
	for(int i=0;i<n;i++){
		StackPush(s,k%10);
		k = k/10;
	}
	for(int i=0;i<n;i++){
		day [i] = pop(s);
		if(day[i]!=0 && day[i]!=1){
			printf("\nnhap sai!");
			stop=1;
			break;
		}
	}
	for(int i=0;i<n;i++){
		a[i]=0;
	}
	while(!stop){
		if( Find() == 1){
			if( Check_Sol() == 1 ){
				Next_Strings();
			    Print_Sol();
			    stop = 1;
			}
			else{
				printf("\n-1");
				stop = 1;
			}
			
		}
		else if( Check_Sol() == 1 )
     		Next_Strings();	
		else 
		    stop = 1;
	}
	
}
