#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <queue>
#include <stack>
#include <list>

using namespace std;

struct State{
	int x;
	int y;
	char* msg;// action to generate current state
	State* p;// pointer to the state generating current state
};

bool visited[100][100];

int solve(int a, int b, int c){
	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			visited[i][j] = false;
	queue<State*> Q;
	list<State*> L;
	
	State* S0 = new State;
	S0->x = 0;
	S0->y = 0;
	S0->p = NULL;	
	L.push_back(S0);
	Q.push(S0);
	visited[0][0] = true;
	
	State* SF = NULL;// store finishing state
	while(!Q.empty()){
		State* S = Q.front();
		Q.pop();
		
		int x = S->x;
		int y = S->y;
		
		if(x == c || y == c || x+y == c){
			SF = S;
			break;
		}
		
		// generate neighbor states
		State* NS;
		
		if(!visited[0][y]){
			NS = new State;
			NS->x = 0;
			NS->y = y;
			NS->msg = "do het nuoc tu coc 1 ra ngoai";
			NS->p = S;
			Q.push(NS);
			L.push_back(NS);
			visited[0][y] = true;
		}
		
		if(!visited[x][0]){
			NS = new State;
			NS->x = x;
			NS->y = 0;
			NS->msg = "do het nuoc tu coc 2 ra ngoai";
			NS->p = S;
			Q.push(NS);
			L.push_back(NS);
			visited[x][0] = true;
		
		}
		
		if(!visited[a][y]){
			NS = new State;
			NS->x = a;
			NS->y = y;
			NS->msg = "do day nuoc vao coc 1";
			NS->p = S;
			Q.push(NS);
			L.push_back(NS);
			visited[a][y] = true;
		}
		
		if(!visited[x][b]){
			NS = new State;
			NS->x = x;
			NS->y = b;
			NS->msg = "do day nuoc vao coc 2";
			NS->p = S;
			Q.push(NS);
			L.push_back(NS);
			visited[x][b] = true;
		}
		
		if(x + y <= a && !visited[x+y][0]){
			NS = new State;
			NS->x = x+y;
			NS->y = 0;
			NS->msg = "do het nuoc tu coc 2 vao coc 1";
			NS->p = S;
			Q.push(NS);
			L.push_back(NS);
			visited[x+y][0] = true;
		}
		
		if(x + y > a && !visited[a][x+y-a]){
			NS = new State;
			NS->x = a;
			NS->y = x+y-a;
			NS->msg = "do tu coc 2 vao day coc 1";
			NS->p = S;
			Q.push(NS);
			L.push_back(NS);
			visited[a][x+y-a] = true;
		}
		
		if(x + y <= b && !visited[0][x+y]){
			NS = new State;
			NS->x = 0;
			NS->y = x+y;
			NS->msg = "do het nuoc tu coc 1 vao coc 2";
			NS->p = S;
			Q.push(NS);
			L.push_back(NS);
			visited[0][x+y] = true;
		}
		
		if(x+y > b && !visited[x+y-b][b]){
			NS = new State;
			NS->x = x+y-b;
			NS->y = b;
			NS->msg = "do tu coc 1 vao day coc 2";
			NS->p = S;
			Q.push(NS);
			L.push_back(NS);
			visited[x+y-b][b] = true;
		}
		
	}
	
	int nbSteps = 0;
	// hien thi cac buoc can thuc hien
	if(SF != NULL){
		// print result
		stack<State*> P;
		while(SF != S0){
			P.push(SF);
			SF = SF->p;
		}
		nbSteps = P.size();
		
		while(!P.empty()){
			State* S = P.top();
			P.pop();
			printf("(%d,%d): %s\n",S->x,S->y,S->msg);
		}
	}else{
		printf("KO\n");
	}	
	// free memory allocated
	list<State*>::iterator p;// p contro duyet danh sach L
	for(p = L.begin(); p != L.end(); p++){
		State* S = *p;
		delete S;
	}
	return nbSteps;
}
int main(int argc, char** argv){
	int a; printf("\na= "); scanf("%d",&a);
	int b; printf("\nb= "); scanf("%d",&b);
	int c; printf("\nc= "); scanf("%d",&c);
	printf("total step: %d\n",solve(a,b,c));
	
	return 0;
	
	int maxSteps = 0;
	
	/*for(int a = 2; a <= 100; a++){
		for(int b = 2; b <= 100; b++){
			for(int c = 2; c <= 100; c++){
				int nbSteps = solve(a,b,c);
				if(nbSteps > maxSteps){
					maxSteps = nbSteps;
				}
				//if(a == 36 && b == 64 && c == 24)
				printf("(%d, %d, %d), nbSteps = %d, maxSteps = %d\n",a,b,c,nbSteps,maxSteps);
			}
		}
		getch();
	}*/
}
