#include <bits/stdc++.h>
using namespace std;
int b,n,value[30],weight[30];// b trong luong lon nhat cua cai tui
int x[30],xopt[30];
int bk=0,fk=0,fopt=-1;

void Input(){
	cin >> n;
	cin >> b;
	for(int i=1;i<=n;i++){
		cin >> value[i];
	}
	for(int i=1;i<=n;i++){
		cin >> weight[i];
	}
}
void TRY(int k){
	for(int y = bk/weight[k];y>=0;y--){
		x[k]=y;
		bk-=y*weight[k];
		fk+=y*value[k];
		if(k==n){
			if(fk>fopt){
				fopt=fk;
				for(int i=1;i<=n;i++){
					xopt[i]=x[i];
				}
			}
			else if( (fk+bk*value[k+1]/weight[k+1]) > fopt )
			TRY(k+1);
		}
	}
}
int main(){
	freopen("input.txt","r",stdin);
	Input();
	
	TRY(1);
	printf("\nket qua: ");
	for(int i=1;i<=n;i++){
		printf("%d",xopt[i]);
	}
	printf("\n gia tri lon nhat cua tui la: %d ",fopt);
	return 1;
}
