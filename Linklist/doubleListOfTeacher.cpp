#include <stdio.h>

struct Node{
	int value;
	Node* left;
	Node* right;
};

Node* first;
Node* last;

void insertAfter(int x, Node* p);

void readData(char* fn){
	first = NULL; last = NULL;
	
	FILE* f = fopen(fn,"r");
	if(f==NULL) printf("\ncan't open file");
	while(true){
		int x;
		fscanf(f,"%d",&x);
		if(x == -1) break;
		insertAfter(x,last);	
	}
	fclose(f);
}
void printLeft2Right(){
	Node* p = first;
	while(p != NULL){
		printf("%d ",p->value);
		p = p->right;
	}
	printf("\n");
}
void printRight2Left(){
	Node* p = last;
	while(p != NULL){
		printf("%d ",p->value);
		p = p->left;
	}
	printf("\n");
}
void remove(int x){
	Node *p = first;
	while(p!=NULL){
		if(p->value==x){
			Node *t=p->left;
			if(t==NULL){
				
			}
			Node *s=p->right;
			if(s==NULL){
				
			}
			t->left = s;
			s->right = t;
			delete(p);
		}
		p = p->right;
	}
}
void insertAfter(int x, Node* p){
	Node* q = new Node;
	q->value = x;
	q->right = NULL;
	q->left = NULL;
	if(p == NULL) return;
	
	if(first == NULL && last == NULL){
		first = q; last = q; return;
	}
	
	Node* pp = p->right;
	if(p == last){
		last = q;
	}else{
		pp->left = q;
	}
	p->right = q;
	q->left = p;
	q->right = pp;
}

void insert(int x, Node* p){
	if(p == NULL) return;
	
	Node* q = new Node;
	q->value = x;
	q->left = NULL; q->right = NULL;
	
	if(first == NULL && last == NULL){
		first = q; last = q; return;
	}

	Node* pp = p->left;
	
	if(p == first){
		first = q;
	}else{
		pp->right = q;
	}
	
	p->left = q;
	q->left = pp;
	q->right = p;
}

int main(int argc, char** argv){
	readData("list");
	printLeft2Right();
	printRight2Left();
}
