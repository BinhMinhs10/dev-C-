#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node {
	const char * key;
	int value;
	struct Node* next;
};
struct Table{
	Node * first;
};
Table * table_creat(){
	Table *t = (struct Table*) malloc(sizeof(Table));
	t->first = NULL;
	return t;
}
void Table_add(Table * t,const char *key,int value){
	Node * p = new Node;
	p->value = value;
	p->key = key;
	p->next = t->first;
	t->first = p;
}
int Table_search( Table * t, const char* key, int *value){
	Node *temp = t->first;
	while(temp!=NULL){
		if(strcmp(key,temp->key) == 0){
			*value = temp->value;
			return 1;
		}
		temp = temp->next;
	} 
	return 0;
}
void Table_free(Table *t){
	Node *p = t->first;
	Node *nextp;
	while(p == NULL){
		nextp = p->next;
		delete(p);
		p = nextp;
	}
	free(t);
}
int main(){
	struct Table* t;
	t = table_creat();
	
	Table_add(t,"binh minh",5);
	Table_add(t,"do quang",8);
	
	Table_add(t,"duc canh",12);

	Table_add(t,"xxx",100);
	//	Table_free(t);
	int value;
	int found;
	const char * key ="xxx";
	found = Table_search(t , key , &value);
	if(found == 1) printf("\n cau thu %s so %d",key ,value);
	return 0;
}
