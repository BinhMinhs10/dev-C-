#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdlib.h>
typedef int dataType;

typedef struct _Node{
	dataType inf;
	struct _Node* next;
}Node;
struct LinkList{
	Node *first;
};
typedef struct LinkList *List;

void Init(List *list_ptr){
	*list_ptr = (List)malloc(sizeof(struct LinkList));
	(*list_ptr)->first = NULL;
}
int IsEmpty(List list){
	return list->first==NULL;
}
Node* FindLast(List list){
	if(IsEmpty(list)) return NULL;
	Node *temp=list->first;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	return temp;
}
Node* PrevNode(List list, Node* f){
	if(IsEmpty(list)) return NULL;
	Node *temp=list->first;
	Node *temp1=NULL;
	while(temp!=NULL){
		if(temp->next == f) return temp;
		temp=temp->next;
	}
	return NULL;
}
void DeleteFirst(List list){
	if(!IsEmpty(list)){
		Node* temp=list->first;
	    list->first=temp->next;
	    delete(temp);
	}
}
void DeleteLast(List list){//delete phan tu cuoi
	if(IsEmpty(list)) return;
	Node * temp = FindLast(list);
	Node * temp1 = PrevNode(list,temp);
	temp1 -> next=NULL;
	delete(temp);
}
void InsertToHead(List list,dataType x){
	Node * newNode;
	newNode = (Node *)malloc(sizeof(Node));
	newNode->inf=x;
	newNode->next=list->first;
	list->first=newNode;
}
void InsertToLast(List list,dataType x){
	Node * tempNode=list->first;
	while(tempNode->next!=NULL){
		tempNode=tempNode->next;
	}
	Node * newNode;
	newNode =(Node *) malloc(sizeof(Node));
	newNode->inf=x;
	newNode->next=NULL;
	tempNode->next=newNode;
}
void DeleteElement(List list,int k){
	Node* temp = list->first;
	//if(temp->inf == k) DeleteFirst(list);	
      while(temp!=NULL){
		
		if(temp->inf == k){
			Node *temp2 = temp;
			Node *temp1 = PrevNode(list,temp);
			if(temp1!=NULL){
				temp1->next=temp2->next;
			    temp=temp2->next;
			    
			}
			else{
				temp=temp2->next;
			}
			delete(temp2);
		}
		else{
			temp = temp->next;
		}
	  }
}
void printList(List list){
	Node *tempNode=list->first;
	while(tempNode!=NULL){
		printf("%4d ",tempNode->inf);
		tempNode=tempNode->next;
	}
	printf("\nEND. \n");
	
}
void readdata(char* fn,List list){
	FILE* f=fopen(fn,"r");
	if( f == NULL ) printf("\nCan't open file!");
	else{
		while(!feof(f)){
			int x;
			fscanf(f,"%d",&x);
			InsertToLast(list,x);
		}
	}
}
int CheckSoNguyenTo(int k){
	int flag = 1;
	for(int i=2;i<(k/2);i++){
		if(k%i == 0) flag=0;
	}
	return flag;
}
void ChanceSNT(List list){
	Node *temp = list->first;
	while(temp!=NULL){
		if(!CheckSoNguyenTo(temp->inf))
		   temp->inf = -1;
		temp = temp->next;
	}
}
void makeToListChan(List list,List chan){
	Node *temp = list->first;
	while(temp!=NULL){
		if((temp->inf % 2) == 0)
		     InsertToHead(chan,temp->inf);
		temp=temp->next;
	}
}
List makeToListLe(List list,List le){
	Node *temp = list->first;
	while(temp!=NULL){
		if((temp->inf % 2) != 0)
		     InsertToHead(le,temp->inf);
		temp=temp->next;
	}
	return le;
}
int main()
{
	List list;
	Init(&list);
	InsertToHead(list,-2);
	readdata("Linkinput.txt",list);
	
	//DeleteElement(list,5760);
	ChanceSNT(list);
	printList(list);
	/*List Chan;
	Init(&Chan);
	makeToListChan(list,Chan);
	printList(Chan);*/
	
	/*
	List Le;
	Init(&Le);
	Le = makeToListLe(list,Le);
	printList(Le);*/
	return 0;
}
