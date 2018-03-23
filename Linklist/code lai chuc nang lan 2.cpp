#include <stdio.h>
#include <conio.h>
struct Node{
	int value;
	struct Node *next;
};
Node* first=NULL;
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
void readdata(const char *name){
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
			first=insert(x,first,findlast(first));
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
Node* find(Node* f,int x){
	while(f!=NULL){
		if(f->value==x) return f;
		f=f->next;
	}
	return NULL;
}
Node *prev(Node *head,Node *p){
	Node*f = head;
	while(f!=NULL){
		if(f->next==p) return f;
		f=f->next;
	}
	return NULL;
}
Node* remove(Node* head,Node *p){
	Node *f=head;
	
	while(f!=NULL){
		if(f==p){
			Node *q=prev(head,p);
	        if(q==NULL){
		       head=head->next;
		       delete p;
		       return head;
	        }
			q->next=p->next;
			delete p;
			return head;
		}
		f=f->next;
	}
	if(p==NULL) return head;
	return NULL;
}
Node* removeAll(Node* head,int v){
	Node *f = head;
	while(f!=NULL){
		if( f->value == v ){
			Node *q = prev(head , f);
			Node *temp = f;
			if(q != NULL){
				q->next = f->next;
			}
			f = f->next;
			delete temp;;
		}
		else
		f=f->next;
	}
	return head;
}
Node* removeRecursive(Node *head,Node *p){// khong hay bang thay
	Node* f=head;
	if(p==NULL) return head;
	Node* q=prev(first,p);
	if(q==NULL){
		f=f->next;
		return f;
	}
	if(f==p){
		q->next=p->next;
		delete p;
	}
	else{
		removeRecursive(f->next,p);
	}
	return head;
}
int sum(Node *head){
	Node *f=head;
	if(f==NULL) return 0;
	int s=0;
	while(f!=NULL){
		s+=f->value;
		f=f->next;
	}
	return s;
}
int sumRecursive(Node *f){
	if(f==NULL) return 0;
	return f->value+sumRecursive(f->next);
}
Node* reverse (Node *head){
	Node *p1 = head;
	if(p1==NULL) return NULL;
	if(p1->next==NULL){
		return p1;
	}
	Node *p2 = p1->next;
	Node *p3 = p2->next;
	while(p3!=NULL){
		p2->next = p1;
	    p1 = p2;
	    p2 = p3;
	    p3 = p3->next;
	}
	p2->next = p1;
	p1 = p2;
	head->next = NULL;
	return p1;
}
int findMinOdd(Node *head){
	if(head==NULL) return 0;
	int min=1000000,flag=0;
	while(head!=NULL){
		if(min > (head->value)){
			if((head->value)%2==1){
				flag = 1;
				min = head->value;
			}
		}
		head=head->next;
	}
	if(flag==0) return 0;
	return min;
}
int findMax(Node *pHead){	//tra ve phan tu chan lon nhat trong danh sach tang dan
	int max;
	while(pHead!=NULL){
		if(pHead->value%2==0){
			max = pHead->value;
		}
		pHead=pHead->next;
	}
	return max;
}
void reorganize(struct Node **head){	//ham sap xep danh sach cac so am o cuoi danh sach
	Node * first = *head;
	int temp;
	while(first!=NULL){
		if(first->value >= 0){
			first = first->next;
		}
		else{
			temp = first->value;
			first = remove(first,first);
			insert(temp,first,findlast(first));
			first = first->next;
		}
	}
}
void Sort(Node *head){
	Node *p=head;// luu dau danh sach
	while(head!=NULL){
		Node *temp=head->next;
		while(temp!=NULL){
			if((temp->value)<(head->value)){
				int x = temp->value;
				temp->value=head->value;
				head->value= x;
			}
			temp = temp->next;
		}
		head = head->next;
	}
	printf("\nmang sau khi da sap xep: ");
	printList(p);
}
void printfReverse(Node *pHead){	//print list reverse have used recursion
	if(pHead==NULL) return;
	printfReverse(pHead->next);
	printf("%3d",pHead->value);
}
int main()
{
	first = Init(&first);
	readdata("inputToSort.txt");
	//first = removeAll(first,4);
	printList(first);
	//reorganize(&first);
	printfReverse(first);
	Sort(first);
	//printf("\nMin all odd number of list is : %d",findMinOdd(first));
	//printf("\nMax implement chan in list tang dan: %d",findMax(first));
	/*Node* q = findlast(first);
	printf("\nlast of list is %d \n",q->value);
	    q = prev(first,NULL);
	printf("\nlast of list is %d \n",q->value);
	for(int i=3;i<=3;i++){
		Node *p = find(first,i);
	    first = remove(first,p);
	}
	printList(first);
	first = removeAll(first,2);
	printList(first);
    printf("\ntong danh sach: %d",sum(first));
	printf("\ntong danh sach co de quy: %d\n",sumRecursive(first));
	printf("\nOK\n");
	//first=removeRecursive(first,find(first,2));
	//printList(first);
	printf("\nList after reverse: \n");
	first = reverse(first);
	Node* p = findlast(first);
	first = insert(2 ,first, p);
	printList(first);*/
	
}
