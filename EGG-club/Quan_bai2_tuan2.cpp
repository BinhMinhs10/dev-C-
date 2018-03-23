#include<stdio.h>
#include<stdlib.h>
char ktZ(float x);//Kiem tra so nguyen
char ktN(float x);//Kiem tra so nguyen duong
int main ()
{
    long *a, max=0; unsigned long n; int i;
    float temp;
    FILE *f=fopen("solonnhat.txt","wt");
    if (f==NULL)
    {
        printf("Khong tao duoc tep.");
        exit(1);
    }
    else
    {
        //Nhap do dai n va khoi tao mang a
        do
        {
            printf("Nhap vao do dai cua mang: n=");
            scanf("%f",&temp);
        }while(ktN(temp));
        n=(unsigned long) temp;
        a=(long*) malloc(n*sizeof(long));
        //Nhap mang a va tim so lon nhat va ghi so do vao file
        printf("Nhap mang a:\n");
        for (i=0;i<n;i++)
        {
            do
            {
                printf("a[%d]=",i);
                scanf("%f",&temp);
            }while(ktZ(temp));
            *(a+i)=(long) temp;
            if (max<*(a+i))
                max=*(a+i);
        }
        fprintf(f,"%ld",max);
        free(a);
    }
    fclose(f);
    return 0;
}

char ktZ(float x)
{
	return (x-(long)x!=0);
}

char ktN(float x)
{
	return (x<=0)||(x-(long)x!=0);
}
