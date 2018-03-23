#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
using namespace std;
void docnguoc(){
	char s;
	s=getchar();
	if(s=='\n') return;
	docnguoc();
	cout << s;
	
}
main()
{
	char a[20];
	printf("nhap 1 xau: ");
	docnguoc();
}
