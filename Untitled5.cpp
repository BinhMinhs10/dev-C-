#include <map>
#include <set>
#include <iostream>
using namespace std;
set<int> V;//set of node
map<int, set<int>>A;//a[v] in the set of adj node of v

map(int,int )d;
map<int, int>f;
map<int, char> color;
map<int, int > 
void readdata(char* fn){
	FILE* f = fopen(fn,"r");
	while(1){
		int v;
		fscanf("%d",&v);
		if(v==-1) break;
		v.insert(v);
	}
	while(1){
		int u;
		int v;
		fscanf(f,"%d",&u);
		if(u==-1) break;
		a[v].insert(u);
		A[u].insert(v);
	}
}
void printGraph(){
	set<int>::iterator p;
	cout << "v= ";
	for(p=v.begin(),p!= v.end();p++){
		int v=*p;
		cout<<v<<",A["<<v<<"]=";
		for(set<int>::interator pv = A[v].begin();pv!=A[v].end();pv++){
			
		}
	}
}
void DFSvisit(int v){
	t=t+1;
	d[u]=t;
	color[u]='G';
	for(set<int>::iterator p = A[v].begin();p!= A[v].end();p++){
		int u=*p;
		if(color[v]=='W'){
			p[u]=v;
			DFSvisit(u);
		}
	}
	color[u]='B';
	t=t+1;
	f[v]=t;
}
void DFS(){
	for(set<int>::iterator pi = v.begin(),pi!=v.end(),pi++){
		int v=*pi;
		color[v]='w';
	
	}
	t=0;
	for(set<int>::iterator pi = v.begin();pi!=v.end();pi++){
		
	}
	
}
int main(){
	
}
