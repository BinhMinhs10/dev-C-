#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct Mark
{
    int Flag;
    int x;
}Mark;

int ran_dom (void);//tao ngau nhien 1 so nguyen tu 1 den 20
void selection(int ia[],int n);//Sap xep noi bot (Code duoc copy tren mang)

//Gia su da co day duoc sap xep theo tu tu tang dan a[n]
int main ()
{
    int n = 50;
    int i, Mid = 0;

    //Khoi tao ngau nhien 1 mang a co n phan tu
    int a[n];
    for (i = 0; i < n; i++)
    {
        a[i] = ran_dom();
        Mid += a[i];
    }
    selection(a, n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]= %d\n", i, a[i]);
    }
    Mid /= 2;//Mid co gia tri bang tong so keo chia 2
    int leng = Mid + 1;//Do dai cua mang danh dau
    Mark b[leng];

    //Gan tat ca b.Flag = 0 (Gia tri 0 bieu thi so do khong phai tong co the tao ra tu day a)
    for (i = 0; i < leng; i++)
        b[i].Flag = 0;

    b[a[0]].Flag = 1;//a[0] la tong dau tien co the tao ra tu day a
    b[a[0]].x = a[0];

    int S = a[0];//S la tong cua cac so hang tu a[0] den a[i]
    int Sum; //Chi so cua mang b dong thoi la so can xet xem co phai la tong tao ra tu day a khong

    //Danh dau tat ca tong co the tao tu a[1] den Mid
    //Flag = 0 Sum khong phai tong tao nen tu day a
    //Flag >= 1 Sum la tong duoc tao nen tu day a, trong do Flag chi so lan Sum duoc tao nen tu day a
    for (i = 1; i < n; i++)
    {
        S += a[i];

        //Truong hop S <= Mid ta xet tu a[i] den S
        if (S <= Mid)
        {
            for (Sum = a[i]; Sum <= S; Sum++)
            {
                if (b[Sum - a[i]].Flag)//Neu Sum - a[i] duoc danh dau la tong duoc tao nen tu day a
                {
                    if (b[Sum - a[i]].Flag > 1)//Neu Sum - a[i] duoc danh dau la tong duoc tao nen tu day a va co Flag > 1 thi Sum chac chan la tong duoc tao tu day a
                    {
                        b[Sum].Flag += 1;
                        b[Sum].x = a[i];
                    }

                    else if (b[Sum - a[i]].x != a[i])//Neu Sum - a[i] co Flag = 1 va Sum - a[i] khong duoc tao nen tu a[i] thi no cung la tong cua day a
                    {
                        b[Sum].Flag += 1;
                        b[Sum].x = a[i];
                    }
                    //Cac truong hop con lai thi khong thay doi gia tri cua Flag
                }
            }
            //Sau khi xet het cac so tu a[i] den S thi danh dau a[i] la tong cua day a
            b[a[i]].Flag += 1;
            b[a[i]].x = a[i];
        }

        //Truong hop S > Mid ta chi can xet tu a[i] den Mid
        else
        {
            for (Sum = a[i]; Sum <= Mid; Sum++)
            {
                if (b[Sum - a[i]].Flag)
                {
                    if (b[Sum - a[i]].Flag > 1)
                    {
                        b[Sum].Flag += 1;
                        b[Sum].x = a[i];
                    }
                    else if (b[Sum - a[i]].x != a[i])
                    {
                        b[Sum].Flag += 1;
                        b[Sum].x = a[i];
                    }

                }
            }

            b[a[i]].Flag += 1;
            b[a[i]].x = a[i];
        }

    }
    //In ra mang danh dau
    for (i = 0; i < leng; i++)
        printf("%d ", b[i].Flag);
    getchar();
    printf("\n");

    //Tim tong S1 gan Mid nhat
    leng--;
    for (i = leng; i >= 0; i--)
        if (b[i].Flag)
            break;
    int S1 = i;//Tong cua day can tim

    //Tim phan tu lon nhat cua day va nho hon S1
    for (i = 0; a[i] <= S1 && i < n; i++);//Tim chi so cua phan tu lon nhat cua day va nho hon S1
    int max = i - 1;//Chi so cua phan tu lon nhat cua day va nho hon S1
    //Tim cac phan tu tao nen tong S1
    printf ("Cac phan tu can tim la:\n");
    while (S1 - a[max] != 0 )
    {
        /*Neu S1 lon hon a[max] va S1 - a[max] la 1 so duoc danh dau la tong cua day a thi a[max] la phan tu tao nen tong S1
        Tiep tuc thuc hien lai buoc nay nhieu lan cho den khi tim duoc phan tu cuoi cung*/
        if(S1 - a[max]>0 && b[S1 - a[max]].Flag)
        {
            S1 = S1-a[max];//Sau buoc nay S1 co the nho hon a[max - 1]
            printf("%d\n", a[max]);//in ra phan tu tao nen tong S1
            max--;//Xet phan tu tiep theo co so thu tu nho hon a[max]
        }
        //Neu S1 nho hon a[max] ta giam chi so cua a cho den khi duoc so a[max] tiep theo nho hon S1
        else
            max--;

    }
    printf("%d", a[max]);//Phan tu nho nhat tao nen tong S1
    return 0;
}
int ran_dom (void)
{
    //srand(time(NULL));
    return (ran_dom() % 20 + 1);
}
void selection(int ia[],int n)
{
    int i,j,t;
    for(i=n;i>0;i--)
        for(j=1;j<i;j++)
            if(ia[j-1] >ia[j])
            {
                t=ia[j-1];
                ia[j-1]=ia[j];
                ia[j]=t;
            }
}
