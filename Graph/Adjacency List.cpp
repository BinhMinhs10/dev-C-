#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct Node{
	int value;
	Node * next;
};
Node *vertice[50];
int index = 0, start;//start la vi tri bat dau duyet
int *Marked = (int *)malloc(100*sizeof(int));//mang danh dau la dinh duoc duyet chua
typedef struct TagList
{
        Node *Head; //Tro vao dau cua hang doi
        Node *Tail;//Tro vao cuoi hang doi
}Queue;

//Cac thao tac voi Queue

//Khoi tao
void Init_Queue(Queue &Q)
{
     Q.Head = Q.Tail = NULL; //Khoi tao gia tri ban dau bang rong
}

//Kiem tra rong
bool IsEmpty_Queue(Queue Q)
{
     if(Q.Head == NULL)
     return 1; //Neu Queue rong tra ve 1
     return 0; //Nguoc lai tra ve 0
}

void EnQueue(Queue &Q, int v)
{
     //Khoi tao mot node de chen vao Queue
     Node *P;
     P = new Node;  //Cap phat bo nho cho node
     
     //Kiem tra xem HDH da cap phat bo nho cho node chua
     if(P == NULL)
     {
          std::cout<<std::endl<<"Empty Memory. "<<std::endl;
          return;
     }
     
     //Gan gia tri cho Node moi
     P->value = v;
     P->next = NULL; //P khong tro di dau ca
     
     if(IsEmpty_Queue(Q))
     {
                         Q.Head = P; //Neu Q rong, P vua la Head vua la Tail
     }
     else
     {
         Q.Tail->next = P; //Tao lien ket giua Q voi P
     }
     
     Q.Tail = P; //P la Tail;
}

int DeQueue(Queue &Q)
{
    int v; //Luu gia tri cua node bi xoa
    Node *P; //Tro den Node bi xoa
    
    P = Q.Head; //P tro vao Head
    
    if(IsEmpty_Queue(Q))return 0;
    Q.Head = Q.Head->next; // Head tro vao node sau cua no
    
    v = P->value; // v luu lai gia tri node bi xoa
    
    if(Q.Head ==NULL)Q.Tail = Q.Head;
    
    delete(P); //Giai phong bo nho cho Head cu
    return v; //Tra ve gia tri node bi xoa
}

Node *findLast(Node *p){
	if(p==NULL) return NULL;
	while(p->next != NULL){
		//printf("\nOK");
		p = p->next;
	}
	return p;
}
void readFile(const char *name){
	FILE* f=fopen(name,"r");
	if(f==NULL){
		fprintf(stderr,"\nCan't open file");
	}
	else{		
		int x;
		while(!feof(f)){
			fscanf(f,"%d",&x);
			Node *p = new Node;
			p->value = x;
			p->next = NULL; 
			vertice[index] = p;
			while(1){
				fscanf(f,"%d",&x);
				if(x==-1) break;
				Node *q = new Node;
				q->value = x;
				q->next = NULL;
				Node *last = findLast(vertice[index]);
				last->next = q;
			}
			index++;
		}
	}
	fclose(f);
}
void printList(){
	for(int i=0;i<index;i++){
		printf("Vertice %d: ",vertice[i]->value);
		Node *temp = vertice[i]->next;
		while(temp != NULL){
			printf("%d ",temp->value);	
			temp = temp->next;
		}
		printf("\n");
	}
	}
void DFS(int start){
	printf("%d ",start);
	Marked[start] = 1;
	Node *p = vertice[start - 1];
	while(p != NULL){
		if(Marked[p->value]==0){
			DFS(p->value);
		}
		p = p->next;
	}
}
void BFS(int start,Queue &Q){
	bool *visited = new bool[index];
	for(int i = 0 ; i<=index ; i++){
		visited[i] = false;
	}
	visited[start] = true;
	EnQueue(Q,start);
	while(!IsEmpty_Queue(Q)){
		start = DeQueue(Q);
		printf("%d ",start);
		Node * temp = vertice[start - 1]->next;
		int x;
		while(temp != NULL){
			x = temp->value;
			if(visited[x] == false){
				visited[x] = true;
				EnQueue(Q,x);
			}
			temp = temp->next;
		}
	}
}
int main(){
	readFile("inputAdjacencyList.txt");
	printList();
	printf("\nnhap dinh bat dau duyet : "); scanf("%d",&start);
	
	printf("\nduyet Depth First Search: ");
	for(int i = 1; i<=index ;i++){
		Marked[i] = 0;
	}
	DFS(start);
	
	printf("\nduyet Breadth First Search: ");
	Queue Q;
    Init_Queue(Q);
    BFS(start,Q);	
}
