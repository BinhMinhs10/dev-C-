#include <bits/stdc++.h>
#define MAXN 30
#define INF 10000000
using namespace std;
int c[MAXN][MAXN], n, cmin=INF, x[MAXN], xopt[MAXN], fk=0, fopt=INF;
int check[]={};
void Input(){
	cin >> n;
	for(int i=1; i<=n ; i++){
		for(int j=1; j<=n ; j++){
			cin >> c[i][j];
			if(c[i][j]!=0){
				cmin = cmin > c[i][j] ? c[i][j] : cmin;
			}
		}
	}
}
void printSol(){
	for(int i=1; i<=n ;i++){
		cout << xopt[i];
	}
	cout << endl;
	cout << "Min cost : " << fopt + c[x[n]][1];
}
void TRY(int k){
	//xay dung xong x1,x2,...,x(k-1).
	for(int i=2 ; i<=n ; i++ ){
		if(check[i]==0){
			check[i]=1;
			x[k] = i;
			fk+= c[x[k-1]][i];
			if(k==n){
				if(fk < fopt){
				    fopt = fk;
				    for(int i=1; i<=n ;i++){
					   xopt[i] = x[i];
				    }
			    }
			}
			
			if((fk + (n-k+1)*cmin) < fopt) TRY(k+1);
			check[i]=0;
			fk-= c[x[k-1]][i];
		}
	}
}
int main(){
	freopen("DATA.INP","r",stdin);
	Input();
	x[1] = 1;
	TRY(2);
	printSol();
	return 0;
}

