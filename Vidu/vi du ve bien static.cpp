#include <stdio.h>
 
/* phan khai bao ham */
void ham(void);
 
int biendem = 4; /* day la bien toan cuc */
 	int i=0;
main()
{

   while(biendem--)
   {
   	 printf("\n 1. i=%d",i);
      ham();
      i+=2;
      printf("\n 2. i=%d",i);
   }
   printf("===========================\n");
   printf("VietJack chuc cac ban hoc tot! \n");
   return 0;
}
/* phan dinh nghia ham */
void ham( void )
{
   static int i = 6; /* bien cuc bo static */
   i++;

   printf("\ni co gia tri la %d va biendem co gia tri la %d\n", i, biendem);

}
