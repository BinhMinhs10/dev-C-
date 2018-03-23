#include <stdio.h>
#include <stdlib.h>

int ReadFile (FILE *f, unsigned *pn, int **pa, float **pb);

void MaxFirst_MaxSecond (unsigned **pIndex, float *HuHai, int n);

void WriteFile (unsigned *Index, unsigned nIndex, float Sum);

int main ()
{
    FILE *f = NULL;
    f = fopen ("input.txt", "rt");
    unsigned n;
    int *a = NULL; float *b = NULL;

    if (ReadFile (f, &n, &a, &b))
    {
        printf ("Cannot open File input.txt");
        exit (1);
    }
    else
    {
        float *HuHai = (float *) malloc (n * sizeof(float));

        if (HuHai == NULL)
        {
            printf ("Not enough memory.");
            exit (1);
        }

        unsigned i, *Index = NULL, nIndex; float Sum = 0;
        Index = (unsigned *) malloc (n * sizeof(unsigned));

        for (i = 0; i != n; i++)
        {
            *(HuHai + i) = (*(a + i)) * (*(b + i));
            Sum += (*(a + i) - *(HuHai + i));
        }

        if (n == 0)
        {
            printf ("ATM haven't something.\n");
            nIndex = 0;
        }
        else if (n == 1)
        {
            nIndex = 1;

            Index = (unsigned *) malloc (nIndex * sizeof(unsigned));
            *Index = 0;

            Sum = *a;
        }
        else
        {
            nIndex = 2;

            Index = (unsigned *) malloc (nIndex * sizeof(unsigned));

            MaxFirst_MaxSecond (&Index, HuHai, n);

            Sum += (*(HuHai + *Index) + *(HuHai + *(Index + 1)));
        }

        WriteFile (Index, nIndex, Sum);

        free (a);
        free (b);
        free (HuHai);
        free (Index);
    }

    return 0;
}

int ReadFile (FILE *f, unsigned *pn, int **pa, float **pb)
{
    if (f == NULL)
        return 1;
    else
    {
        int i;
        fscanf (f, "%d", pn);

        *pa = (int *) malloc (*pn * sizeof (int));

        if (*pa == NULL)
            return 1;

        *pb = (float *) malloc (*pn * sizeof (float));

        if (*pb == NULL)
            return 1;

        for (i = 0; i != *pn; i++)
            fscanf (f, "%d", *pa + i);

        for (i = 0; i != *pn; i++)
            fscanf (f, "%f", *pb + i);
    }

    fclose (f);

    return 0;
}
void MaxFirst_MaxSecond (unsigned **pIndex, float *HuHai, int n)
{
    unsigned iMaxFirst = 0, iMaxSecond = 1;
    unsigned i;

    for (i = 1; i != n; i++)
    {
        if (*(HuHai + iMaxFirst) <= *(HuHai + i))
        {
            iMaxSecond = iMaxFirst;
            iMaxFirst = i;
        }
        else if (*(HuHai + iMaxSecond) < *(HuHai + i))
        {
            iMaxSecond = i;
        }
    }

   **pIndex = iMaxFirst;
   *(*pIndex + 1) = iMaxSecond;

}

void WriteFile (unsigned *Index,unsigned nIndex, float Sum)
{
    FILE *f;
    f = fopen ("output.txt", "at");

    if (nIndex == 1)
        fprintf (f, "%d\n%f", *Index + 1, Sum);

    else if (nIndex == 2)
        fprintf (f, "%d %d\n%f", *Index + 1, *(Index + 1) + 1, Sum);

    fclose (f);

}
