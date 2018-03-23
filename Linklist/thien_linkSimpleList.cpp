#include <stdio.h>
#include <stdlib.h>
/*
struct elementType{
	int data;
};*/
typedef int elementType;
struct node {
	elementType value;
	node *next;
};

node *tail;

int readData(node *head, char *fn);
node *findLast(node *head);
node *insert(node *head, elementType x, node *p);
void printList(node *head);
int sum(node *head);
int sumRecursive(node *head);
node *remove(node *head, node *p);
node *prev(node *head, node *p);
node *find(node *head, int x);

int readData(node **head, char *fn)
{
	elementType temp;
	FILE *f = fopen(fn, "r");
	if(f ==  NULL){
		printf("read file fail\n");
		return 1;
	}
	while(!feof(f)){
		fscanf(f,"%d",&temp);
		*head = insert(*head,temp,tail);
		/*printList(head);
		printf("\n");*/
	}
	
	fclose(f);
	return 0;
}
void printList(node *head)
{
	node *p = head;
	while(p != NULL){
		printf("%d ",p->value);
		p = p->next;
	}
	printf("\n");
}

node *findLast(node *head)
{//tim va tra ve con tro tro vao phan tu cuoi trong list
	node *p = head;
	while(p != NULL){
		if(p->next == NULL) return p;
		p = p->next;
	}
	return p;
}

node *insert(node *head, elementType x, node *p)
{// chen phan tu co gia tri bang x vao sau phan tu p
	node *q = new node;
	q->value = x;
	q->next = NULL;
	
	if(head == NULL){
		head = q;
		tail = q;
		return head;
	}
	
	if(p == tail)
		tail = q;
	else 
		q->next = p->next;
	p->next = q;
	return head;
}

int sum(node *head)
{//tinh tong cac thanh phan cua day
	node *p = head;
	int sum = 0;
	while(p != NULL){
		sum += p->value;
		p = p->next;
	}
	return sum;
}
int sumRecursive(node *head)
{
	if(head->next == NULL){
		return head->value;
	}
	else{
		int sum = head->value + sumRecursive(head->next);
		return sum;
	}
}

node *remove(node *head, node *p)
{//xoa node p khoi danh sach
	if(head == NULL) return NULL;
	if(head == p){
		head = head->next;
		delete p;
		return head;
	}
	node *q = prev(head,p);
	if(p != NULL){
		q->next = p->next;
		delete p;
	}
	return head;	
	
}

node *prev(node *head, node *p)
{//tim node truoc p
	if(p == NULL) return NULL;
	node *q = head;
	while(q != NULL){
		if(q->next == p) return q;
		q = q->next;
	}
	return NULL;
}
node *find(node *head, int x)
{//tim phan tu co gia tri bang x
	node *p = head;
	while(p != NULL){
		if(p->value == x) return p;
		p = p->next;
	}
	return NULL;
}


int main(int argc, char **agrv)
{
	node *head = NULL;
	char fn[] = "input";
	readData(&head,fn);
	printList(head);
	printf("\n\n");
	printf("\ntong cac thanh phan trong day la: %d",sum(head));
	printf("\ntong  de quy cac thanh phan trong day la: %d\n",sumRecursive(head));
	
		node *p = find(head,5);
		remove(head,p);
		printList(head);
	
	
	return 0;
}
