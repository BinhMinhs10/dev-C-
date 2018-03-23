#include <stdio.h>
#include <conio.h>

int n;
int a[30];
void print_permutation()
{
    int i;
    for(i=1;i<=n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int check_permuattion()
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(a[i]!=n-i+1)
        {
            return 1;
            break;
        }
    }
    return 0;

}
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void Next_permutation()
{
    int i=n-1;
    int k=n;
    while(a[i]>a[i+1]) i--;
    while(a[k]<a[i]) k--;
    swap(&a[k],&a[i]);
    int r=n,s=i+1;
    while(r>s)
    {
        swap(&a[r],&a[s]);
        r--;
        s++;
    }

}
int main()
{
    int i;
    printf("\nnhap n= "); scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        a[i]=i;
    }
    char stop=0;
    while(!stop)
    {
        print_permutation();
        if(check_permuattion()==1)
        {
            Next_permutation();
        }
        else stop=1;
    }
    return 0;
}

