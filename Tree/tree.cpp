#include <stdio.h>

struct Node{
	int id;
	Node* leftMostChild;
	Node* rightSibling;
};

Node* root;

Node* find(Node* r, int v){
	// return the pointer to the node having id = v
	if(r == NULL) return NULL;
	if(r->id == v) return r;
	Node* p = r->leftMostChild;
	while(p != NULL){
		Node* q = find(p,v);
		if(q != NULL) return q;
		p = p->rightSibling;
	}
	return NULL;
}

Node* findRightMostChild(Node* p){
	if(p == NULL) return NULL;
	Node* q = p->leftMostChild;
	while(q != NULL){
		if(q->rightSibling == NULL) return q;
		q = q->rightSibling;
	}
	return NULL;
}
		
Node* addNode(Node*r, Node* p, int v){
	Node* h = new Node;
	h->id = v;
	h->leftMostChild = NULL;
	h->rightSibling = NULL;
	if(r == NULL) return h;
	if(p == NULL) return r;// p is not a node of tree
	Node* q = findRightMostChild(p);
	if(q == NULL) p->leftMostChild = h;
	else q->rightSibling = h;
	
	return r;
}
	
void readData(char* fn){
	root = NULL;
	FILE* f = fopen(fn,"r");
	while(true){
		int v;
		fscanf(f,"%d",&v);
		if(v == -2) break;
		Node* p = find(root,v);
		if(p == NULL){
			//printf("find p = NULL\n");
			root = new Node;
			root->id = v;
			root->leftMostChild = NULL;
			root->rightSibling = NULL;
			p = root;
		}
		// read children of v
		while(true){
			int u;
			fscanf(f,"%d",&u);
			if(u == -1) break;
			root = addNode(root,p,u);
		}
	}
	fclose(f);
}

void printTree(Node* r){
	if(r == NULL) return;
	Node* p = r->leftMostChild;
	printf("node %d: ",r->id);
	while(p != NULL){
		printf("%d ",p->id);
		p = p->rightSibling;
	}
	printf("\n");
	// print sub-tree of r
	p = r->leftMostChild;
	while(p != NULL){
		printTree(p);
		p = p->rightSibling;
	}
}

Node* parent(Node* r, Node* p){
	if(r == NULL) return NULL;
	Node* q = r->leftMostChild;
	while(q != NULL){
		if(q == p) return r;
		Node* h = parent(q,p);
		if(h != NULL) return h;
		q = q->rightSibling;
	}		
	return NULL;
}
int height(Node* r, Node* p){
	if(p == NULL) return 0;
	int maxh = 0;
	Node* q = p->leftMostChild;
	while(q != NULL){
		int h = height(r,q);
		maxh = maxh < h ? h : maxh;
		q = q->rightSibling;
	}
	return maxh + 1 ;
}
int depth(Node* r, Node* p){
	if(r == NULL) return 0;
	if(p == r) return 1;
	Node* q = r->leftMostChild;
	while(q != NULL){
		if(q == p) return 2;
		int dd = depth(q,p);
		if(dd > 0) return 1 + dd;
		q = q->rightSibling;
	}
	return 0;
}

int count(Node* r){
	if(r == NULL) return 0;
	int c = 1;
	Node* p = r->leftMostChild;
	while(p != NULL){
		int ci = count(p);
		c += ci;
		p = p->rightSibling;
	}
	return c;
}

int countLeaves(Node* r){
	// return number of leaves of the tree rooted at r
	if(r == NULL) return 0;
	Node* p = r->leftMostChild;
	if(p == NULL) return 1;
	int count = 0;
	while(p != NULL){
		int c = countLeaves(p);
		count += c;
		p = p->rightSibling;
	}
	return count;
}
Node* findLeftSibling(Node* r, Node* p){
	if(r==NULL) return NULL;
	Node *q = r->leftMostChild;
	if(q == NULL || q == p) return NULL;
	while(q!=NULL){
		if(q->rightSibling == p) return q;
		Node* qq = findLeftSibling(q,p);
		if(qq != NULL) return qq;
		q = q->rightSibling;
	}
	return NULL;
}

void preorder(Node* r){
	if(r == NULL) return;
	printf("%d ",r->id);
	Node* p = r->leftMostChild;
	while(p != NULL){
		preorder(p);
		p = p->rightSibling;
	}
}
void inorder(Node* r){
	if(r == NULL) return;
	Node* p = r->leftMostChild;
	if(p == NULL){
		printf("%d ",r->id);
		return;
	}
	inorder(p);
	printf("%d ",r->id);
	p = p->rightSibling;
	while(p != NULL){
		inorder(p);
		p = p->rightSibling;
	}	
}
void postorder(Node* r){
	if(r == NULL) return;
	Node* p = r->leftMostChild;
	while(p != NULL){
		postorder(p);
		p = p->rightSibling;
	}
	printf("%d ",r->id);
}

int main(int argc, char** argv){
	readData("tree.txt");
	printTree(root);
	int c = count(root);
	printf("number of nodes of the tree = %d\n",c);
	
	for(int i = 1; i <= 12; i++){
	Node* p = find(root,i);
	int h = height(root,p);
	int d = depth(root,p);
	printf("height of %d is %d, depth = %d\n",p->id,h,d);
	}
	c = countLeaves(root);
	printf("number of leaves is %d\n",c);
	
    Node *p = find(root,1);
	Node *pp = findLeftSibling(root,p);
	if(pp!=NULL)
	printf("\nNode left of node %d is %d",p->id,pp->id);
	else printf("\nNode %d don't have node left",p->id);
	
	printf("\nINORDER: ");
	inorder(root);
	printf("\n");
	
	printf("PREORDER: ");
	preorder(root);
	printf("\n");
	
	printf("POSTORDER: ");
	postorder(root);
	printf("\n");
	
}
