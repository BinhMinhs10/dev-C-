#include <stdio.h>
int calc(int subkey,int bitoff){
	subkey = subkey >> (bitoff & 0x1f);
	return subkey;
}
int calc1(int subkey,int bitoff){
	subkey = subkey >> (bitoff - ((bitoff >> 5) << 5));
	return subkey;
}
int main(){
	printf("\nsubkey = %d",calc(123444,108));
	return 0;
}
