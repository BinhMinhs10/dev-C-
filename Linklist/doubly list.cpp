 #include <stdio.h>
 struct Node {
 	int value;
 	Node* left;
 	Node* right;
 };
 Node* first;
 Node* last;
 //them phan tu vao list
 void insertfirst(int x,Node* p)
 {
 	if(p==NULL) return;
 	Node* q=new Node;
 	q->value=x;
 	q->left=NULL; q->right=NULL;
 	if(first==NULL&&last==NULL)
 	{
 		first=q; last=q; return;
 	}
 	Node*pp=p->left;
 	if(p==first)
 	{
 		first=q;
 	}
 	else
 	{
 		pp->right=q;
 	}
 	p->left=q;
 	q->left=pp;
 	q->right=p;
 }
 void insertlast(int x,Node *p)
 {
 	if(p==NULL) return;
 	Node* q=new Node;
 	q->value=x;
 	q->left=NULL; q->right=NULL;
 	if(first==NULL&&last==NULL)
 	{
 		first=q; last=q;
 	}
 	Node* pp=p->right;
 	if(p==last)
 	{
 		last=q;
 	}
 	else
 	{
 		pp->left=q;
 	}
 	q->right=pp;
 	q->left=p;
 	p->right=q;
 }
 void displayBackward(){

   //bat dau tu cuoi list
   struct Node *ptr = last;
	
   //duyet toi phan dau list
   //printf("\n[ ");
	
   while(ptr != NULL){    
	
      //in du lieu
      printf("(%d)",ptr->value);
		
      //di chuyen toi phan tu tiep theo
      ptr = ptr -> left;
   }
}

 int main()
 {
 	insertfirst(5,first);
 	insertlast(4,last);
 	displayBackward();
 }
