#include<conio.h>
#include<stdio.h>
void quaylui(int i,int n)
{
    int j,k;
       static int a[30];
    for(j=0;j<=1;j++)
    {
        a[i]=j;
        if(i==n-1)
        {
            for(k=0;k<n;k++)
                printf("%d",a[k]);
            printf("\n");
        }
        else quaylui(i+1,n);
    }
}
int main()
{       int n;
    printf("nhap n=");
        scanf("%d",&n);
    quaylui(0,n);
    return 0;
getch();
}
