#include <stdio.h>
#include <stdlib.h>
#include <Sort.h>

struct pair
{
    int IndexTeam1;
    int IndexTeam2;
};

typedef struct pair pair;

int ReadFile (FILE *f, unsigned *pn, int **pa, int **pb);


int main ()
{
    FILE *f = NULL;
    f = fopen ("input.txt", "rt");
    unsigned n = 0;
    int *a = NULL; int *b = NULL;

    if (ReadFile (f, &n, &a, &b))
    {
        printf ("Cannot open File input.txt");
        exit (1);
    }
    else
    {
        unsigned Last = n - 1;

        MergeSort (a, 0, Last);
        MergeSort (b, 0, Last);

        unsigned MaxWin = 0, WinCondition = n / 2;
        int i = 0, j = 0;
        unsigned NumberDraw = 0;

        pair *Pairs;

        int *temp = (int *) malloc (n * sizeof(int));
        unsigned Indextemp = 0;
        Pairs = (pair *) malloc (n * sizeof (pair));

        while (j < n)
        {
            if (a[i] > b[j])
            {
                Pairs[MaxWin] . IndexTeam1 = i;
                Pairs[MaxWin] . IndexTeam2 = j;

                MaxWin++;
                i++;
            }
            else
            {
                temp[Indextemp] = j;
                Indextemp++;
            }

            j++;
        }

        if (MaxWin > WinCondition)
            printf ("TEAM BAN CO THE CHIEN THANG\n");
        else
        {
            i = Pairs[MaxWin - 1] . IndexTeam1 + 1;
            j = 0;

            while (j < Indextemp)
            {
                if (a[i] == b[temp[j]])
                {
                    Pairs[MaxWin + NumberDraw] . IndexTeam1 = i;
                    Pairs[MaxWin + NumberDraw] . IndexTeam2 = temp[j];
                    NumberDraw++;
                    i++;
                }

                j++;
            }

            if ((2 * MaxWin + NumberDraw) > n)
                printf ("TEAM BAN CO THE CHIEN THANG\n");
            else
            {
                MaxWin = 0, i = n - 1, j = n - 1;
                NumberDraw = 0;

                temp = (int *) malloc (n * sizeof(int));
                Indextemp = 0;
                Pairs = (pair *) malloc (n * sizeof (pair));

                while (j > -1)
                {
                    if (a[i] > b[j])
                    {
                        Pairs[MaxWin] . IndexTeam1 = i;
                        Pairs[MaxWin] . IndexTeam2 = j;

                        MaxWin++;
                        i--;
                    }
                    else
                    {
                        temp[Indextemp] = j;
                        Indextemp++;
                    }

                    j--;
                }

                if (MaxWin > WinCondition)
                    printf ("TEAM BAN CO THE CHIEN THANG\n");
                else
                {
                    i = Pairs[MaxWin - 1] . IndexTeam1 - 1;
                    j = 0;

                    while (j < Indextemp)
                    {
                        if (a[i] == b[temp[j]])
                        {
                            Pairs[MaxWin + NumberDraw] . IndexTeam1 = i;
                            Pairs[MaxWin + NumberDraw] . IndexTeam2 = temp[j];
                            NumberDraw++;
                            i--;
                        }

                        j++;
                    }

                    if ((2 * MaxWin + NumberDraw) > n)
                        printf ("TEAM BAN CO THE CHIEN THANG\n");
                    else
                    {
                        printf ("TEAM BAN KHONG THE CHIEN THANG\n");
                        return 0;
                    }
                }
            }

        }

        j = MaxWin + NumberDraw;

        for (i = 0; i < j; i++)
            printf ("%d - %d\n", a[Pairs[i] . IndexTeam1], b[Pairs[i] . IndexTeam2]);

        free (a);
        free (b);
        free (Pairs);
        free (temp);
    }

    return 0;
}

int ReadFile (FILE *f, unsigned *pn, int **pa, int **pb)
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

        *pb = (int *) malloc (*pn * sizeof (int));

        if (*pb == NULL)
            return 1;

        for (i = 0; i != *pn; i++)
            fscanf (f, "%d", *pa + i);

        for (i = 0; i != *pn; i++)
            fscanf (f, "%d", *pb + i);
    }

    fclose (f);

    return 0;
}
