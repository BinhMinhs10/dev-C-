#include <stdio.h>

struct Node{
	int data;
	Node * pNext;
};
Node* first = NULL;
Node *findlast(Node *head){
	while(head->pNext!=NULL){
		head = head->pNext;
	}
	return head;
}
Node* inserstHead(int x,Node *head){
	Node *p = new Node;
	p->data = x;
	p->pNext = NULL;
	if(head == NULL) return p;
	p->pNext = head;
	head = p;
	return head;
}
Node* findMid(Node *head){
	Node * first = head;
	Node * mid = head;
	if(first==NULL) return NULL;
	while(first->pNext!=head){
		first = first->pNext;
		if(first->pNext == head) break;
		mid = mid->pNext;
		first = first->pNext;
	}
	return mid;
}
void printList(Node* head){
	printf("\nList of element: ");
	while(head!=NULL){
		printf("%3d",head->data);
		head=head->pNext;
	}
	printf("\n");
}
int main(){
	for(int i=1;i<=10;i++){
		first = inserstHead(i,first);
	}
	printList(first);
	Node *last = findlast(first);
	last->pNext = first;
	Node * mid = findMid(first);
	printf("\nOK");
	printf("\nphan tu giua la: %d",mid->data);
	return 0;
}



//bai 2 20133-01
