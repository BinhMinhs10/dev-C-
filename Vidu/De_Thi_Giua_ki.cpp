#include <stdio.h>
int count;
	int s=0;
int a[5];
void TRY(int k, int last){

	for(int v = last +1 ; v <=10 ; v++){
		s+= v;
		a[k]=v;
		if(k==3){
			if(s==10){
				for(int i=1; i<=3;i++){
					printf(" %d ",a[i]);
				}
				printf("\n");
				count++;
			} 
		}
		else TRY(k+1,v);
		s-= v;
	}
}
int main(){
	
	TRY(1,0);
	printf("\n%d ",count);
}
