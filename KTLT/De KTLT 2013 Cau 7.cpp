#include <stdio.h>
int main(){
	int y=5,z=6;
	int x=y++ + 2*(y+z) + ++z;
	printf("\nx=%d, y=%d, z=%d",x,y,z);
	return 0;
}
