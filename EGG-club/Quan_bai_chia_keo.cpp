#include <stdio.h>

struct Node
{
    int Sum;
    int x;
};

int abs(int x);
double pow(float x, int y);

int main ()
{
    int n = 8;
    int maxb = pow(2, n) - 1;
    struct Node b[maxb];
    int i, j = 0, k, h, min = 0, Mid, count = 0, a[n], y;

    for (i = 0; i < n; i++)
    {
        printf("\na[%d]= ", i);
        scanf("%d",&a[i]);
        Mid += a[i];
    }
    Mid /= 2;

    for (i = 0; i < n; i++)
    {
        h = j;
        for (k = 0; k < h; k++)
        {
            b[j].Sum = b[k].Sum + a[i];
            b[j].x = a[i];
            j++;
        }

        b[j].Sum = a[i];
        b[j].x = a[i];
        j++;
    }
    min = abs(Mid - b[0].Sum);

    for (i = 1; i < j; i++)
    {
        if (abs(Mid - b[i].Sum) < min)
        {
            min = abs(Mid - b[i].Sum);
            count = i;
        }
    }

    y = count;
    while (b[y].Sum - b[y].x != 0)
    {
        printf("%d\n", b[y].x);
        for (i = 0; i < j; i++)
        {
            if (b[i].Sum == b[y].Sum - b[y].x)
            {
                y = i;
                break;
            }
        }
    }
    printf("%d\n", b[y].x);
    return 0;
}

int abs(int x)
{
    if (x < 0)
        return (-x);
    return x;
}

double pow(float x, int y)
{
    int i;
    double p = 1;
    for (i = 0; i < y; i++)
        p *= x;
    return p;
}
