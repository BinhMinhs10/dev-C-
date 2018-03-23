#include <stdio.h>
#include <conio.h>
#define hang 3
#define cot 3
main()
{
  int matran[hang][cot]={{7,8,9},{10,13,15},{2,7,8}};
  int i,j;
  for(i=0;i<hang;i++)
  {
    for(j=0;j<cot;j++)
	{
		printf("%5d",matran[i][j]);
	}
	printf("\n");
  }
  for(i=0;i<hang;i++)
  {
  	for(j=0;j<cot;j++)
  	{
  		*(*(matran+i)+j)=*(*(matran+i)+j)+10;
  		printf("%20d",*(*(matran+i)+j));
  	}
  	printf("\n");
  }
}
