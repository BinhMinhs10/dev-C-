#include <stdio.h>

#define N 100
int Array[N]={0};
char Mark[N]={0};

void printResult(int k);
int toHop(int i, int k, int n);
int totalByN(int n);

main()
{
    totalByN(30);
}

//hien thi ket qua
void printResult(int k)
{
    
    for(int i=1; i<k; i++)
    {
        printf("%d ",Array[i]);
    }
    printf("\n");

}

//tinh to hop cac phan tu
int toHop(int i,int k, int n )
{
    int j,l;
    for(j =Array[i-1] +1; j <= n-k + i; j++)
    {

        Array[i] = j;
        if(i==k)
        {
            int Total=0;
            for(l=0;l<k+1;l++)
            {
                Total+=Array[l];
            }
            if(Total==n)
                printResult(k+1);
        }
        else
        {
            toHop(i+1,k,n);
        }
    }
    return 0;
}

//chon tung to hop co k phan tu
int totalByN(int n)
{
    int k;
    for(k=2;k<n/10+4;k++)
    {
       	toHop(1,k,n);
    }
    return 0;
}
