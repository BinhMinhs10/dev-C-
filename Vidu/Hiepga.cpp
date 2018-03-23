#include <stdio.h>

int main(){
	int i;
	for(i=100;i<=999;i++){
		int flag = 0,sum=0;
		int j,temp = i;
		for(j=1;j<=3;j++){
			sum+=(temp%10);
			temp = temp/10;
			flag = 1;
		}
		if(flag==1 && sum%2 != 0){
			printf("%4d",i);
		}
		
	}
	return 0;
}
