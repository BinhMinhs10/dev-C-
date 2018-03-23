#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b;
    FILE *f=fopen("sonhohon.txt","wt");
    if (f==NULL)
    {
        printf("Khong tao duoc tep");
        exit(1);
    }
    else
    {
        printf("Nhap 2 so nguyen a va b:\n");
        //Nhap a
        printf("a=");
        scanf("%d",&a);
        //Nhap b
        printf("b=");
        scanf("%d",&b);
        //In so lon hon va ghi vao tep so nho hon
        if (a==b)
            printf("Khong co so nao lon hon");
        else
        {
            printf("So lon hon la: ");
            if (a>b)
            {
                printf("%d",a);
                fprintf(f,"%d",b);
            }
            else
            {
                printf("%d",b);
                fprintf(f,"%d",a);
            }
        }
    }
    fclose(f);
    return 0;
}
