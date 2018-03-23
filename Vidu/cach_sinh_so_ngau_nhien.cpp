#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
   int i;

   srand(time(0));
   printf("Ten random numbers from 0 to 99\n\n");
   for(i=0; i<10; i++)
       printf("%d\n", -100+rand()%200);
   return 0;
}
