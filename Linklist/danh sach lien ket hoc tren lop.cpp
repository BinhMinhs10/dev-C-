#include <stdio.h>
#include <stdlib.h>
int x;
struct Node{
	int value;
	Node *next;
};
Node* first=NULL;
Node* insertion(Node* f,int x,Node *p)//them phan tu co gia tri x vao truoc p
{
	Node* q=new Node;
	q->value=x;
	if(f==NULL)
	{
		q->next =NULL;
		f=q;
	}
	else
	{
		q->next=p->next;
		p->next=q;
	}
	delete q;
    return f;
}
Node* insertionfirst(Node* f,int x)
{
	Node* q=new Node;
	q->value=x;
	if(f==NULL) 
	{
		return q;
	}
	else
	{
		q->next=f->next;
		f->value=x;
	}
	return f;
}
void readdata(char *fn)
{
	FILE* fc;
	if((fc=fopen(fn,"r"))==NULL)
	{
		printf("\n khong mo duoc file");
	}
	else{
		while(true)
	   {
		fscanf(fc,"%d",&x);
		if(x==-1) break;
		first=insertionfirst(first,x);
	   }
	}
	
	fclose(fc);
}
Node* findlast(Node *f)
{
	Node* p=f;
	while(p!=NULL){
		if(p->next==NULL) return p;
	}
	return NULL;
}
int sum(Node *f)
{
	int s=0;
	Node* p=f;
	while(p!=NULL)
	{
		s=s+p->value;
		p=p->next;
	}
	return s;
}
int sumrecursive(Node *f)
{
	if(f==NULL)
		return 0;
	return f->value + sumrecursive(f->next);
}
Node* prev(Node *f,Node* p)
{
	//return the pointer to the prev nope of p
	if(p==NULL) return NULL;
	Node* q=f;
	while(q!=NULL)
	{
		if(q->next==p)
			return q;
		q=q->next;
	}
	return NULL;
}
Node* remove(Node *f,Node *p)//xoa 1 phan tu p tren f khoi list
{
	if(f==NULL) return NULL;
	if(f==p)
	{
		f=f->next;
		delete p;
		return f;
	}
	
	Node* q=prev(f,p);
	printf("\nOK");// 1 trong cach debug
	if(q!=NULL){
		q->next=p->next;
	    delete p;//luon nho giai phong bo nho
	}
	return f;
}
Node* find(Node*f,int x)
{
	//return the first nopde having value x
	Node* p=f;
	while(p!=NULL)
	{
		if(p->value==x)
			return p;
		p=p->next;	
	}
	return NULL;
}
Node* removeRecursive(Node* f, Node* p)
{
	if(f==NULL) return NULL;
	if(f==p)
	{
		f=f->next;
		delete p;
		return f;
	}
	f->next = removeRecursive(f->next,p);// neu khong gan sau khi giai phong danh sach se bi tach roi
	return f;
}
Node* reverse(Node *f)//dao nguoc list
{
	Node* p1;
	Node* p2;
	Node* p3;
	if(f==NULL ) return NULL;
	p3=f;
	if(f->next==NULL) return f;
	p1=f->next;
	p2=p1->next;
	p3->next=NULL;
	while(p1!=NULL)
	{
		p1->next=p3;
		p3=p1;
		p1=p2;
		if(p2!=NULL)
		{
			p2=p2->next;
		}
	}
	return p3;
	
}
void printList(Node *f)
{
	while(f!=NULL)
	{
		printf("%3d",f->value);
		f=f->next;
	}
	printf("\n");
}
int main()
{
	
	readdata("input");
	printf("\nok\n");
	printList(first);
	printf("\nok\n");
	printf("sum= %d\n", sumrecursive(first));
	Node* p=find(first,5);
	first=remove(first,p);
	printList(first);
}
// find tat ca cac phan tu co gia tri bang x
