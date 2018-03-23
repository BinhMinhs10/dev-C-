#include <stdio.h>
#include <conio.h>
int n,m;
int a[30];
void print_combination()
{
    int i;
    for(i=1;i<=m;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
int check_combination()
{
    int i;
    for(i=1;i<=m;i++)
    {
        if(a[i]!=(n-m+i))
        {
            return 0;
            break;
        }
    }
    return 1;
}
void Next_combination(int m,int n)
{
    int i=m,j;
    while(a[i]==n-m+i)   i--;
    a[i]++;
    for(j=i+1;j<=m;j++)
    {
        a[j]=a[i]+j-i;
    }
}
int main()
{
    printf("\n nhap n= "); scanf("%d",&n);
    printf("\n nhap m= "); scanf("%d",&m);
    int stop=1,i;
    for(i=1;i<=m;i++)
    {
        a[i]=i;
    }
    while(stop)
    {
        print_combination();
        if(check_combination()==0)
        {
            Next_combination(m,n);
        }
        else stop=0;
    }
}

