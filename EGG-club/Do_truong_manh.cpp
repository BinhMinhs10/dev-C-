#include <stdio.h>
#include <conio.h>

//float giaithua(int n);

int main()
{
      int i=1;
      float e=1, epsilon, tmp=1;
      printf("\n Nhap so epsilon: ");
      scanf("%f",&epsilon);
      while(tmp>epsilon)
     {
        tmp = 1/(giaithua(i));
        e+=tmp;
        i++;
     }
      printf("\n %10.5f",e);
      getch();
}

    float giaithua(int n)
{
    float a=1;
    int i=1;
    while(i<=n)
    {
       a*=i;
       i++;
    }
     return a;
}
