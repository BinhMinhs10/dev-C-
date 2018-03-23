#include <stdio.h>
#include <stdlib.h>
struct Stack{
	char item;
	struct Stack *next;
};
Stack *top;
void Init(){
	top = (Stack *)malloc(sizeof(Stack));
	top = NULL;
}
void push(char x){
	Stack *newNode = new Stack;
	newNode->item = x;
	newNode->next = top;
	top = newNode;
}
int pop (){
	Stack* temp = top;
	char x = top->item;
	top = top->next;
	delete (temp);
	return x;  
}
void tinh(Stack *head,char ch){
	char get2= pop();
	char get1= pop();
	printf("\npop %c, %c",get2,get1);
	if(ch=='+'){		
		char tong = (get1 + get2) ;
		printf("\ntong = %c",tong);
		push(tong); 
	}else if(ch=='-'){		
		char hieu = (get1 - get2) ;
		printf("\nhieu = %c",hieu);
		push(hieu);  
	}else if(ch=='*'){		
		char tich = (get1 * get2) ;
		printf("\ntich = %c",tich);
		push(tich);  
	}else if(ch=='/'){
		char thuong = get1/get2 ;
		printf("\nthuong = %c",thuong);
		push(thuong);  
	}
}
int main(){
	Init();
	FILE *f =fopen("dayhauto.txt","r");
	if(f==NULL) printf("\nCan't open file!");
	else{
		char ch;
		ch = (char)getc(f);
		printf("\n%c",ch);
		while(ch!=EOF){
			if((ch=='+')||(ch=='-')||(ch=='/')||(ch=='*')){
				tinh(top,ch);
			}
			else{	
				printf("\npush = %c",ch);
				push(ch);
			}
			ch =(char) getc(f);
			printf("\n%c",ch);
		}
		int x = pop();
		printf("\nket qua tinh hau to la: %d",x);
	}
	fclose(f);
	return 0;
}
