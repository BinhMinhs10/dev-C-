#include <string.h>
#include <ctype.h>
void  display (char str[],int (*Xtype)(int c)){
	int index= 0;
	while(str[index]!='\0'){
		cout << (*Xtype)(str[index]);
		index ++;
	}
	return;
}
main()
{
	char input[500];
	cout << " Enter string: ";
	cin >> input;
	char reply;
	cout <<"display the string in uppercase or lowercase (u,l): ";
	cin >> reply;
	if(reply=='l')
	    display( str,tolower);
	else 
	display(str,toupper);
	return;    
	
}
