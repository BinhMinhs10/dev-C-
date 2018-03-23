#include <stdio.h>
struct Node{
	int value;
	struct Node *next;
};
Node* first1 = NULL;
Node* first2 = NULL;
int n;
Node* Init(Node **first){
	*first=NULL;
	return *first;
}
Node* findlast(Node* p)
{
	if(p == NULL) return NULL;
	while(p->next!= NULL){
		p = p->next;
	}
	return p;
}
Node * insert(int x,Node *head, Node * p)// insert after *p
{
	Node* q= new Node;
	q->value=x;
	q->next=NULL;
	if(head==NULL){
		head=q;
	}
	else{
		q->next=p->next;
	    p->next=q;
	}
	return head;
} 
void readfile1(const char *name){
	FILE *f;
	f=fopen(name,"r");
	if(f==NULL)
	{
		printf("\n khong mo duoc file");
	}
	else
	{
		int x;
		while(true)
		{
			fscanf(f,"%d",&x);
			if(x==-1) break;
			first1=insert(x,first1,findlast(first1));
		}	
	}
	fclose(f);
}
void readfile2(const char *name){
	FILE *f;
	f=fopen(name,"r");
	if(f==NULL)
	{
		printf("\n khong mo duoc file");
	}
	else
	{
		int x;
		while(true)
		{
			fscanf(f,"%d",&x);
			if(x==-1) break;
			first2=insert(x,first2,findlast(first2));
		}	
	}
	fclose(f);
}
void printList(Node *head){
	while(head!=NULL)
	{
		printf("%d ",head->value);
		head=head->next;
	}
	printf("\n");
}
Node* mergeLists(Node * List1, Node *List2){
	Node *r = NULL;
	while(List1!=NULL || List2 != NULL){
		if(List1==NULL){
			r = insert(List2->value,r,findlast(r));
			List2 = List2->next;
		}
		else if(List2==NULL){
			r = insert(List1->value,r,findlast(r));
			List1 = List1->next;
		}
		else {
			if((List1->value)<(List2->value)){
				r = insert(List1->value,r,findlast(r));
				List1 = List1->next;
			}
			else{
				r = insert(List2->value,r,findlast(r));
				List2 = List2->next;
			}
		}
	}
	return r;
}
int main(){
	first1 = Init(&first1);
	readfile1("input1.txt");
	printList(first1);
	first2 = Init(&first2);
	readfile2("input2.txt");
	printList(first2);
	Node *root = mergeLists(first1,first2);
	printList(root);
}
