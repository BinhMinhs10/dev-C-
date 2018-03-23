#include <fstream>
#include <iostream>
#include <string>
main(){
char c,buff[222];
int i=0;
FILE *f;  
  
f = fopen ("C:/Users/ThuyLinh Computer/Documents/dev-C++/input.txt", "r");  
while (!feof(f))  
{  
    c = fgetc(f);  
    buff[i++]=c;  
}  
fclose(f);  
  
buff[i-1]='\0';  
  
printf ("%s\n", buff);  
}
