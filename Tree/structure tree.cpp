#include <stdio.h>
struct Node{
	int id;
	Node* leftMostChild;
	Node* rightSibling;
};
Node* root;
Node * find(Node *r, int v){
	if(r==NULL) return NULL;
	if(r->id==v) return r;
	Node* p=r->leftMostChild;
	while(p!=NULL){
		Node *q=find(p,v);
		if(q!=NULL) return q;
		p=p->rightSibling;
	}
	return NULL;
}
Node * findNotGood(Node *r, int v){
	Node* left=r->leftMostChild;
	Node* right=r->rightSibling;
	if(r->id=v) return r;
	else{
		Node* p=find(left,v);
		if(p!=NULL) return p;
		return find(right,v);
	}
}
Node* findRightMostChild(Node*p){
	if(p==NULL) return NULL;
	Node* q=p->leftMostChild;
	while(q!=NULL)
	{
		if(q->rightSibling == NULL) return q;
		q=q->rightSibling;
	}
	return NULL;
}
Node *addNode(Node*r,Node *p,int u){
	Node* h= new Node;
	h->id=u;
	h->leftMostChild=NULL;
	h->rightSibling=NULL;
	if(r==NULL) return h;
	if(p==NULL) return r;
	Node*q=findRightMostChild(p);
	if(q==NULL) 
	     p->leftMostChild=h;
	else 
	     q->rightSibling=h;
	
	return r;
	
}
//another way to add node to tree
void addChild(Node *r,int u){
	Node *h= new Node;
	h->id = u;
	h->leftMostChild = NULL;
	h->rightSibling = NULL;
	Node *pi=r->leftMostChild;
	if(pi==NULL){
		pi->leftMostChild = h;
	}
	else{
		while(pi->rightSibling!=NULL){
			pi=pi->rightSibling;
		}
		pi->rightSibling = h;
	}
}
void readdata(char *fn){
	 root=NULL;
	FILE* f = fopen( fn , "r" );
	if(f == NULL)  printf("\ncan't open file!");
	while(true){
		int v;
		fscanf(f,"%d",&v);
		if(v==-2) break;
		Node* p=find(root,v);
		if(p==NULL){
			root = new Node;
			root->id = v;
			root->leftMostChild = NULL;
			root->rightSibling = NULL;
			p = root;
		}
		while(true){
			int u;
		 fscanf(f,"%d",&u);
		 if(u==-1) break;
		 root = addNode(root,p,u);
		   //addChild( root , u);
	    }
	}
	fclose(f);
}
int countLeaves(Node* r){
	//return number of leaves of the tree rooted at r
	if(r==NULL) return 0;
	int c=1;
	Node *p=r->leftMostChild;
	while(p!=NULL){
		int ci=countLeaves(p);
		c+=ci;
		p=p->rightSibling;
	}
	return c;
}
Node *parent (Node *r,Node* p){
	if( r ==NULL ) return NULL;
	Node *q = r->leftMostChild;
	while( q!=NULL ){
		if( q==p ) return r;
		Node *qq = parent( q, p);
		if(qq!= NULL) return qq;
		q=q->rightSibling;
	}
	return NULL;
}
int height(Node* r, Node* p){
	if( p == NULL ) return 0;
	int maxh = 0;
	Node *q = p->leftMostChild;
	while(q!=NULL){
		int h = height(r,q);
		maxh = maxh < h? h : maxh;
		q=q->rightSibling;
	}
	return maxh+1;
}
int depth(Node* r, Node *p){
	if(r == NULL) return 0;
	if(r == p) return 1;
	Node *q= r->leftMostChild;
	while(q!=NULL){
		if(q == p) return 2;
		int d=depth(q,p);
		if( d > 0 ) return d+1; 
		q=q->rightSibling;
	}
	return 0;
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
void Preorder(Node *r){
	if(r==NULL) return;
	printf("%d ",r->id);
	Node *p=r->leftMostChild;
	while(p!=NULL){
		Preorder(p);
		p=p->rightSibling;
	}
}
void Inorder(Node *r){
	if( r == NULL ) return;
	Node *p = r->leftMostChild;
	if( p == NULL ){
		printf("%d ",r->id);
		return;
	} 
	Inorder(p);
	printf("%d ",r->id);
	p = p->rightSibling;
	while(p!=NULL){
		Inorder(p);
		p=p->rightSibling;
	}
}
void Postorder(Node *r){
	if(r==NULL) return;
	Node *p=r->leftMostChild; 
	while(p!=NULL){
		Postorder(p);
		p=p->rightSibling;
	}
	printf("%d ",r->id);
}
int main(){
    readdata("tree.txt");
	
	printTree(root);
	int l = countLeaves(root);
	
	printf("\ntree have %d leaves\n",l);
	printf("\nduyet theo preorder: ");    Preorder(root);
	printf("\nduyet theo postorder: ");   Postorder(root);
	printf("\nduyet theo inoder: ");      Inorder(root);
    printf("\n");
	//printf("\nOK\n");
	int x;
	//
	for(int i=1;i<=12 ; i++){
		Node *pp = find(root,i);
		int h=height(root , pp);
		int d=depth(root, pp);
		Node *qq = parent(root,pp);
	    if(qq== NULL) printf("\nnode %2d have height is %3d , depth is   1 don't have parent",i,h);
	    else
	    printf("\nnode %2d have height is %3d , depth is %3d parent is %3d ",pp->id,h,d,qq->id);
	}
	//
}
