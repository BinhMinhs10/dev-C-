#include <map>
#include <iostream>
#include <set>
#include <stdio.h>

using namespace std;

set<int> V;                 // set of nodes
map <int, set<int> > A;                                                       // A[v] is the set of adjacent nodes of v

map <int, int> d;
map <int, int> f;
map <int, char> color;
map <int, int> p;

map <int ,int> cc;                                                            // cc[v] is the index of the connected component containning v
int nbCC; // number of CC of the given graph

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

void DFSvisit(int u){
	t = t + 1;
	d[u] = t;
	color[u] = 'G';
	cc[u] = nbCC;
	
	for(set<int>::iterator pi = A[u].begin(); pi != A[u].end(); pi++){
		int v = *pi;
		if(color[v] == 'W'){
			p[v] = u;
			DFSvisit(v);
		}
	}
	color[u] = 'B';
	t++;
	f[u] = t;
}

void DFS(){
	for(set<int>::iterator pi = V.begin(); pi != V.end(); pi++){
		int v = *pi;
		color[v] = 'W';
	}
	t = 0;
	nbCC = 0;
	
	for(set<int>::iterator pi = V.begin(); pi != V.end(); pi++){
		int v = *pi;
		if(color[v] == 'W'){
			nbCC++;
			DFSvisit(v);
		}
	}
	
	// print lines: d, f, p, color
	for(set<int>::iterator pi = V.begin(); pi != V.end(); pi++){
		int v = *pi;
		cout << v << "  ";
	}
	cout << endl;
	for(set<int>::iterator pi = V.begin(); pi != V.end(); pi++){
		int v = *pi;
		cout << d[v] << "  ";
	}
	cout << endl;
	for(set<int>::iterator pi = V.begin(); pi != V.end(); pi++){
		int v = *pi;
		cout << f[v] << "  ";
	}
	cout << endl;
	for(set<int>::iterator pi = V.begin(); pi != V.end(); pi++){
		int v = *pi;
		cout << p[v] << "  ";
	}
	cout << endl;
	for(set<int>::iterator pi = V.begin(); pi != V.end(); pi++){
		int v = *pi;
		cout << color[v] << "  ";
	}
	cout << endl;
	cout << "number of cc  = " << nbCC << endl;
	for(int i = 1; i <=  nbCC ; i++){
		cout << i << "th cc: ";
		for(set<int>:: iterator pi = V.begin(); pi != V.end(); pi++){
			int v = *pi;
			if(cc[v] == i){
				cout << v << " ";
			}
		}
	}
}

int main(int argc, char** argv){
	char fn[] = "graph.txt";
	readData(fn);
	printGraph();
	DFS();
	return 0;
}
