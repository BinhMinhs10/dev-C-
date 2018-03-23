#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Random(int n)
{
   return rand()%(n+1);
}

 
int main()
{
   int a, b,k;
   srand(time(NULL));
   printf("a = %d\n", rand()%50); //Ng?u nhiên t? 0 d?n 99
   printf("b = %d\n", 50+rand()%51); // 50 d?n 10
   k=Random(50);
   printf("k=%d\n",k);
   return 0;
}
