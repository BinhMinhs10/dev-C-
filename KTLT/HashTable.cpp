#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum{
	BUCKET_COUNT = 1024
};
struct Node{
	const char *key;
	int value;
	Node *next;
};
struct Table{
	struct Node *array[BUCKET_COUNT];
};
unsigned int hash(const char *x){
	int i;
	unsigned int h = 0U;
	for(i = 0; x[i]!='\0' ; i++){
		h = h*65599 +(unsigned char) x[i];
		return h % 1024;
	}
}
Table* Table_creat(){
	Table * t= (struct Table * ) calloc(1, sizeof(struct Table));
	return t;
}
void Table_add(Table *t, const char *key,int value){
	Node *p = new Node;
	int h = hash(key);
	p->key = key;
	p->value = value;
	p->next = t->array[h];
	t->array[h] = p; 
}
int Table_search( Table * t, const char* key, int *value){
	int h = hash(key);
	Node *temp = t->array[h];
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
	Node *nextp;
	for(int b = 0;b< BUCKET_COUNT; b++){
		struct Node * p = t->array[b];
		while(p!=NULL){
			nextp = p->next;
			delete(p);
			p = nextp; 
		}
	}
	free(t);
}
int main(){
	Table * t = Table_creat();
	Table_add(t,"hoc ",1);
	Table_add(t,"hoc nua ",2);
	Table_add(t,"hoc mai ",3);
	
}
