#include <stdio.h>
struct Node{
	int id;
	struct Node* leftChild;
	struct Node* rightChild;
};
Node *root;
Node* find(Node *r, int v){
	if(r==NULL) return NULL;
	Node* Left= r->leftChild;
	if(Left->id == v) return Left;
	Node* Right= r->rightChild;
	if(Right->id == v) return Right;
	while(Left!=NULL){
		Node* p = find(Left,v);
		if(p!=NULL) return p;
	}
	while(Right!=NULL){
		Node*p = find(Right,v);
		if(p!=NULL) return p;
	}
	return NULL;
}
Node * addToLeft(Node *r,Node *p, int v){
	Node* q = new Node;
	q->id = v;
	q->leftChild = NULL;
	q->rightChild = NULL;
	p->leftChild = q;
	return r;
}
Node * addToRight(Node *r,Node *p, int v){
	Node* q = new Node;
	q->id = v;
	q->leftChild = NULL;
	q->rightChild = NULL;
	p->rightChild = q;
	return r;
}
Node* readdata(char *name){
	Node *root= NULL;
	FILE* f = fopen(name,"r");
	if(f == NULL ){
		printf("\nCan't open file");
		return NULL;
	}
	while(1){
		int g;
	    fscanf(f,"%d",&g);
	    if(g==-4){
	    	break;
	    }
	    Node *p = find(root,g);
		if(p==NULL){
	        Node *root = new Node;
	        root->id = g;
	        root->leftChild = NULL;
	        root->rightChild = NULL;
	        p = root;
		}
		while(1){
			int flag;
		    fscanf(f,"%d",&flag);
		    if(flag == -3) break;
		    if(flag== -1){
		    	    int inf;
		    	    fscanf(f,"%d",&inf);
		        	root = addToLeft(root,p,inf);
		    }
		    else if(flag == -2){
		    	    int inf;
		    	    fscanf(f,"%d",&inf);
			        root = addToRight(root,p,inf);
		    }
		}
	}
	fclose(f);
	return root;
}
void preorder(Node *r){
	if(r==NULL) return;
	printf(" %d ",r->id);
	Node *p = r->leftChild;
	while(p!=NULL){
		preorder(p);
		p = p->leftChild;
	}
	Node *q = r->rightChild;
	while(q!=NULL){
		preorder(q);
		q = q->rightChild;
	}
	printf("\n ");
}
int main(){
	printf("\nOK");
	root = readdata("Treebinary.txt");
	printf("\nPreorder: ");
	preorder(root);
	printf("\nOK");
}
