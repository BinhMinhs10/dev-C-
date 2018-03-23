#include <stdio.h>
#include <map>
using namespace std;
struct Node{
	int id;
	Node *left, *right, *parent;
};
map <Node*, bool> marked;

void printLeaves(Node* root){
	if(root == NULL) return;
	Node* p = root;
	while(1){
		if(p->left == NULL){
			if(p->right == NULL){
				printf("%d ", p->id);
				marked[p] = true;
				p = p->parent;
				if(p == root) break;
				if(marked[p->right] == true)
				    p = p->parent;
				    
				while(p->right == NULL && p->parent->parent != NULL) p = p->parent;
				p = p->right;
			}
			else
				p = p->right;
		}
		else
			p = p->left;
	}	
}

Node *makeNode(int x){
	Node* p = new Node;
	p->id = x;
	p->left = NULL;
	p->right = NULL;
	p->parent = NULL;
}

Node* insert(Node* root, int x){
	Node* p = makeNode(x);
	if(root == NULL) return p;
	
	Node* q = root;
	if(q->left != NULL){
		if(q->right != NULL){
			q->left = insert(q->left, x);
			q->left->parent = q;
		}
		else{
			q->right = insert(q->right,x);
			q->right->parent = q;
		}
	}
	else{
		q->left = insert(q->left, x);
		q->left->parent = q;
	}
	return root;
}
void print(Node* root){
	if(root == NULL) return;
	printf("%d ", root->id);
	if(root->parent != NULL)
	    printf(" | parent: %d\n", root->parent->id);
	print(root->left);
	print(root->right);
}


int main(){
	Node *root = NULL;
	for(int i = 0; i < 10; i++){
		root = insert(root, i);
	}
	print(root);
	
	printf("\n\n");
	printLeaves(root);
}
