#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 
int main()
{
   int a, b;
   srand(time(NULL));
   printf("a = %d\n", rand()%100); //Ng?u nhiên t? 0 d?n 99
   printf("b = %d\n", 50+rand()%51); // 50 d?n 100
   return 0;
}
