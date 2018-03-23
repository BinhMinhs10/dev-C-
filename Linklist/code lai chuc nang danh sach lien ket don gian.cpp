#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
int n;
int *a=(int* ) malloc(100*sizeof(int));
struct Node
{
	int data;
	struct Node* NEXT; 
};
Node *first=NULL;
void readdata(char *fn)
{
	FILE *f;
	if((f=fopen(fn,"r"))==NULL)
	{
		printf("\n can't open file! ");
	}
	else
	{
		fscanf(f,"%d",&n);
		for(int i=0;i<n;i++)
		{
			fscanf(f,"%d",&a[i]);
		}
	}
}
Node* insertsion(int x,Node *p,Node *head)//them phan tu vao link list
{
	Node *q=new Node;
	q->data=x;
	q->NEXT=NULL;
	if(head==NULL)
	{
		head=q;
		return head;
	}
	else
	{
		p->NEXT=q;
		q->NEXT=p->NEXT;
	}
	return head;
}
void insertFirst(int key)// chen phan tu len dau
{
	struct Node* link=(Node *)malloc(sizeof(Node));
	link->data=key;
	link->NEXT=first;
	first=link;
}
void delet(Node *p)
{
	if(p==first)
	{
		Node *tmp=first->NEXT;
		delete  first;
		first=tmp;
	}
	else
	{
		Node *pi=first;
		while(pi!=NULL&&pi->NEXT!=p)//khong hieu ro lam
		   pi=pi->NEXT;
		if(pi!=NULL)
		{
			pi->NEXT= p->NEXT;
			delete p;
		}
		
		
	}
}
 Node* find(int key)//find key 
{
	Node* current=first;
	if(first==NULL)
	{
		return NULL;
	}
	while(current->data!=key)
	{
		if(current->NEXT==NULL)
		{
			return NULL;
		}
		else
		{
			current=current->NEXT;
		}
	}
	return current;
}
void printList(Node* head)//in day
{
	Node *p=head;
	while(p!=NULL)
	{
		printf(" %d ",p->data);
		p=p->NEXT;
	}
	printf("\n");
}
Node * makeNull()
{
	while(first!=NULL){
		Node *tmp=first->NEXT;
		delete first;
		first=tmp;
	}
	return NULL;
}
Node *locate(int x,Node* head)
{
	Node* p=head;
	while(p!=NULL)
	{
		if(p->data==x)
	    return p;
	    p=p->NEXT;
	}
	return NULL;
}
void reverse(struct Node *r)//dao nguoc list
{
	
}
Node *prev(Node *p)//gia tri truoc
{
	Node* tmp=first;
	while(tmp!=NULL)
	{
		if(tmp->NEXT==p)
	    return tmp;
	    tmp=tmp->NEXT;
	}
	return NULL;
}
int main()
{
	Node *p;
	readdata("input");
	printf("\n n=%d\n",n);
	for(int i=0;i<n;i++)
	{
		printf("\ta[%d]=%d",i+1,a[i]);
		insertFirst(a[n-i-1]);
	}
	printf("\nlist sau khi nhap: ");
	printList(first);//in list
	//tim element of position
	int tim,xoa;
	do{
		printf("\n ban muon tim phan tu co chi so: "); scanf("%d",&tim);
	    
	}while((tim-1>n)||(tim-1<0));
	//-----------------------------------------------
	    struct Node* found;
	    found=find(a[tim-1]);
	    printf(" phan tu vi tri %d la %3d",tim,found->data);
	//-----------------------------------------------    
	int chen;
	printf("\nchen phan tu vao day:\n"); scanf("%d",&chen);
	    first=insertsion(chen,locate(a[tim-1],first),first);
	printList(first);    
    //-----------------------------------------------
	printf("\n dao nguoc danh sach\n");
	reverse(first);//dao nguoc list
	printList(first);    
	free(a);
	return 0;
}
