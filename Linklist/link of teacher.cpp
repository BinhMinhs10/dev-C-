#include <stdio.h>

struct Node{
	int value;// value of the element
	Node* next;// pointer to the next element
};

Node* first;
Node* last;

Node* findLast(Node* f){
	Node* p = f;
	while(p != NULL){
		if(p->next == NULL) return p;
		p = p->next;
	}
	return NULL;
}

Node* insert(Node* f, int x, Node* p){
	//if(p == NULL) return f;
	
	Node* q = new Node;
	q->value = x;
	if(f == NULL){
		q->next = NULL;
		f = q;
	}
	else{
		q->next = p->next;
		p->next = q;
	}
	return f;
}

void printList(Node* f){
	Node* p = f;
	while(p != NULL){
		printf("%d ",p->value);
		p = p->next;
	}
}

void readData(char* fn){
	FILE* f = fopen(fn,"r");
	first = NULL;
	while(true){
		int x;
		fscanf(f,"%d",&x);
		if(x == -1) break;
		first = insert(first,x,findLast(first));
	}
	fclose(f);
}

int sum(Node* f){
	// TODO
	int s = 0;
	Node* p = f;
	while(p != NULL){
		s = s + p->value;
		p = p->next;
	}
	return s;
}

int sumRecursive(Node* f){
	if(f == NULL) return 0;
	return f->value + sumRecursive(f->next);
}
Node* prev(Node* f, Node* p){
	// return the pointer to the previous Node of p
	if(p == NULL) return NULL;
	
	Node* q = f;
	while(q != NULL){
		// do something
		if(q->next == p) return q;
		q = q->next;
	}
	return NULL;
}

Node* remove(Node* f, Node* p){
	// TODO
	if(f == NULL) return NULL;
	if(f == p){
		f = f->next;
		delete p;
		return f;
	}
	
	Node* q = prev(f,p);
	
	
	if(q != NULL){
		q->next = p->next;
		delete p;
	}
	return f;
}

Node * find(Node* f, int x){
	// return the first Node having value x
	Node* p = f;
	while(p != NULL){
		if(p->value == x) return p;
		p = p->next;
	}		
	return NULL;
}

Node* removeRecursive(Node* f, Node* p){
	if(f == NULL) return NULL;
	if(f == p){
		f = f->next;
		delete p;
		return f;
	}
	f->next = removeRecursive(f->next,p);
	return f;
}

Node* reverse(Node* f){
	//TODO
	Node* p1;
	Node* p2;
	Node* p3;
	if(f == NULL) return NULL;
	p3 = f;
	if(f->next == NULL){
		return f;
	}	
	p1 = p3->next;
	p2 = p1->next;
	p3->next = NULL;
	while(p1 != NULL){
		p1->next = p3;
		p3 = p1;
		p1 = p2;
		if(p2 != NULL)
			p2 = p2->next;
	}
	return p3;
}
int main(int argc, char** argv){
	readData("input");
	printList(first);
	printf("sum = %d\n",sumRecursive(first));
	
	for(int i = 1; i <= 5; i++){
		Node* p = find(first,i);
		first = removeRecursive(first,p);
		printf("after removing %d, list = ",i);
		printList(first);
		printf("\n");
	}
	
	printf("after reversing, list = ");
	first = reverse(first);
	printList(first);
}
