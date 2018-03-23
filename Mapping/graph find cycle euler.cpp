#include <map>
#include <iostream>
#include <set>
#include <stdio.h>
#include <stack>
using namespace std;

set<int> V;                 // set of nodes
map <int, set<int> > A;                                                       // A[v] is the set of adjacent nodes of v


int t; // time
void readData(const char* fn){
	FILE* f = fopen(fn, "r");
	
	//read nodes
	while(1){
		int v;
		fscanf(f, "%d", &v);
		if(v == -1) break;
		V.insert(v);
	}
	
	// read edges
	while(1){
		int u;
		int v;
		fscanf(f, "%d", &u);
		if(u == -1) break;
		fscanf(f, "%d", &v);
		A[v].insert(u);
		A[u].insert(v);
	}
	fclose(f);
}

void printGraph(){
	set <int> :: iterator p;
//	cout << "V = ";
	for(p = V.begin(); p != V.end(); p++){
		int v = *p;
		cout << v << ", A[" << v << "] = ";
		for(set <int>:: iterator pv = A[v].begin(); pv != A[v].end(); pv++){
			cout << *pv << " ";
		}
		cout << endl;
	}
}
void euler(){
	stack<int> s;
	stack<int> ce;
	int u = *(V.begin());
	x.push(u);
	while(!s.empty()){
		int x = s.top();
		if(!A[x].empty()){
			int y = *(A[x].begin());
			s.push(y);
			//loai x khoi tap ke cua y va nguoc lai
			A[x].erase(y);
			A[y].erase(x);
		}
		else{
			s.top();
			ce.push();
		}
	}
	while(!ce.empty()){
		int x= ce.top(); ce.pop();
		printf("%d ",x);
	}
}
int main(){
	readdata("input.txt")
}
