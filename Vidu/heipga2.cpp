#include <stdio.h>
#include <math.h>
int main(){
	for(int i=1;i<=100;i++){
		if((int)sqrt(i)==sqrt(i)){
			printf("%3d",i);
		}
	}
	return 0;
}
