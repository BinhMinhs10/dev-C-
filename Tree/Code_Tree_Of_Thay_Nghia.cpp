#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <process.h>
struct Tnode{
	char word[20];
	struct Tnode * left;
	struct Tnode * right;
};

typedef struct Tnode treeNode;
treeNode * makeTreeNode(char *word);
treeNode * RandomInsert(treeNode *tree,char *word);
void freeTree(treeNode *tree);
void printPreorder(treeNode *tree);
void printPostorder(treeNode *tree);
void printInorder(treeNode *tree);
int countNodes(treeNode *tree);
int depth(treeNode *tree);

int main(){
	treeNode *randomTree=NULL;
	char word[20] = "a";
	while(strcmp(word,"~")!=0){
		printf("\nEnter item (~ to finish) : ");
		scanf("%s",word);
		if(strcmp(word,"~")==0){
			printf("Chan dut nhap thong tin nut...\n");
		}
		else{
			randomTree = RandomInsert(randomTree,word);
		}
	}
	printf("The tree in preorder:\n");
	printPreorder(randomTree);
	printf("\n**********************************************\n");
	
	printf("The tree in Inorder:\n");
	printInorder(randomTree);
	printf("\n**********************************************\n");
	
	printf("The tree in Postorder:\n");
	printPostorder(randomTree);
	printf("\n**********************************************\n");
	
	printf("The number of node is : %d \n",countNodes(randomTree));
	freeTree(randomTree);
	printf("depth of tree is %d",depth(randomTree));
	getch();
	return 0;
}
treeNode * makeTreeNode(char *word){
	treeNode* newNode = new treeNode;
	if(newNode==NULL){
		printf("Out of memery\n");
		exit(1);
	}
	else{
		newNode->left = NULL;
		newNode->right = NULL;
		strcpy(newNode->word,word);
	}
	return newNode;
}
treeNode * RandomInsert(treeNode * tree, char *word){
	treeNode *newNode, *p;
	newNode = makeTreeNode(word);
	if(tree == NULL) return newNode;
	if(rand()%2==0){
		p=tree;
		while(p->left!=NULL) p=p->left;
		p->left = newNode;
		printf("Node %s is left child of %s\n",word,(*p).word);
	}
	else{
		p=tree;
		while(p->right!=NULL) p=p->right;
		p->right = newNode;
		printf("Node %s is right child of %s\n",word,(*p).word);
	}
	return tree;
}
void freeTree(treeNode * tree){
	if(tree == NULL) return;
	freeTree(tree->left);
	freeTree(tree->right);
	free(tree);
	return;
}
void printPreorder(treeNode * tree){
	if(tree != NULL){
		printf("%s ",tree->word);
		printPreorder(tree->left);
		printPreorder(tree->right);
	}
}
void printInorder(treeNode * tree){
	if(tree != NULL){
		printPreorder(tree->left);
		printPreorder(tree->right);
		printf("%s ",tree->word);
	}
}
void printPostorder(treeNode * tree){
	if(tree != NULL){
		printPreorder(tree->left);
		printf("%s ",tree->word);
		printPreorder(tree->right);
	}
}
int countNodes(treeNode *tree){
	if(tree==NULL) return 0;
	else{
		int ld = countNodes(tree->left);
		int rd = countNodes(tree->right);
		return 1+ld+rd;
	}
}
int depth(treeNode *tree){
	if(tree==NULL) return 0;
	else{
		int ld = depth(tree->left);
		int rd = depth(tree->right);
		int max=ld<rd?rd:ld;
		return max+1;
		
	}
}

