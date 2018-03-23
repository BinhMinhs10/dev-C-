#include <conio.h>
#include <stdio.h>
main()
{
	int size=3,matran[3][3];
	int row,column,sum=0,sum1=0,sum2=0;
	int flat;
	for(int row=0;row<size;row++)
	   for(column=0;column<size;column++)
	   {
	   	printf("matran[%d][%d]=",row+1,column+1);
	   	scanf("%d",&matran[row][column]);
	   }
    //in ma tran
    for(row=0;row<size;row++)
    {
    	printf("\n");
    	for(column=0;column<size;column++)
    	{
    		printf("%4d",matran[row][column]);
    	}
    }
    //kiem tra phan tu tren duong cheo
    for(int row=0;row<size;row++)
	   for(column=0;column<size;column++)
	   	if(row==column)
	   	{
	   		sum=sum+matran[row][column];
	   	}
	   	printf("\ntong tren duong cheo chinh la: %d",sum);
    //kiem tra tong phan tu tren cac hang
     for(int row=0;row<size;row++)
	  {
	    for(column=0;column<size;column++)
	     {sum1=sum1+matran[row][column];}
	     if(sum==sum1)
	     flat=1;
	     else
	     {
	       flat=0;
	       break;}
	  }
	  //kiem tra tong phan tu tren cot
	   for(int row=0;row<size;row++)
	  {
	    for(column=0;column<size;column++)
	     {
	     sum2=sum2+matran[column][row];}
	     if(sum==sum2)
	     flat=1;
	     else
	     {
	       flat=0;
	       break;}
	  }
	  if(flat==1)
	  printf("\n day so nay la magic square");
	  else
	  printf("\n  day so nay khong phai magic square!");
	  return 0;
}
