#include <stdio.h>
#include <stdlib.h>

struct ZeroPeriod
{
    int start;
    int end;
};

typedef struct ZeroPeriod ZeroPeriod;

int ReadFile (int *pn, int *pSoNgay, int *pNgayi, int *pNgayj, int *TongMuaNgay);

inline void AddSentinel (int *Array, int Number, int x);

int DaySellMax (int *TongMuaNgay, int SoNgay);

int FindDaySellZero (int *TongMuaNgay, int SoNgay, int *DaySellZero);

void InitTableFindSum (int *TongMuaNgay, int SoNgay, int *TableFindSum);

inline int SumSell_iToj (int *TableFindSum, int Ngayi, int Ngayj);

int FindZeroPeriod (int *DaySellZero, int NumberDaySellZero, ZeroPeriod *ZeroPeriodArray);

void WriteFile (int TongMuaNgay[], int SoNgay, int MaxDay, int DaySellZero[], int NumberDaySellZero, int Sumij, ZeroPeriod ZeroPeriodArray[], int NumberZeroPeriod);

int main ()
{
    int n, Ngayi, Ngayj, SoNgay, TongMuaNgay[32] = {};

    if (ReadFile (&n, &SoNgay, &Ngayi, &Ngayj, TongMuaNgay))
    {
        printf ("Cannot open File input.txt");
        exit (1);
    }
    else
    {
        //Phan 2
        int DaySellZero [32], MaxDay = DaySellMax (TongMuaNgay, SoNgay), NumberDaySellZero;

        NumberDaySellZero = FindDaySellZero (TongMuaNgay, SoNgay, DaySellZero);

        //Phan 3
        int Sumij = 0, TableFindSum [31];

        InitTableFindSum(TongMuaNgay, SoNgay, TableFindSum);
        Sumij = SumSell_iToj(TableFindSum, Ngayi, Ngayj);

        //Phan 4
        ZeroPeriod ZeroPeriodArray [32];
        int NumberZeroPeriod;

        NumberZeroPeriod = FindZeroPeriod(DaySellZero, NumberDaySellZero, ZeroPeriodArray);

        //WriteFile
        WriteFile (TongMuaNgay, SoNgay, MaxDay, DaySellZero, NumberDaySellZero, Sumij, ZeroPeriodArray, NumberZeroPeriod);

    }

    return 0;
}


int ReadFile (int *pn, int *pSoNgay, int *pNgayi, int *pNgayj, int *TongMuaNgay)
{
    FILE *f = NULL;
    f = fopen ("input.txt", "rt");

    if (f == NULL)

        return 1;

    else
    {
        int i, NgayMua, SoLuongMua;

        fscanf (f, "%d", pn);

        *TongMuaNgay = 0;

        for (i = 0; i != *pn; i++)
        {
            fscanf (f, "%d %d", &NgayMua, &SoLuongMua);
            *(TongMuaNgay + NgayMua - 1) += SoLuongMua;
        }

        *pSoNgay = NgayMua;

        fscanf (f, "%d %d", pNgayi, pNgayj);
    }

    fclose (f);

    return 0;
}


void AddSentinel (int *Array, int Number, int x)
{
    *(Array + Number) = x;
}


int DaySellMax (int *TongMuaNgay, int SoNgay)
{
    int i, IndexMax = 0;

    for (i = 1; i < SoNgay; i++)
    {
        if (*(TongMuaNgay + IndexMax) < *(TongMuaNgay + i))
            IndexMax = i;
    }

    return IndexMax;
}


int FindDaySellZero (int *TongMuaNgay, int SoNgay, int *DaySellZero)
{
    int i = -1;
    int NumberDaySellZero = 0;

    SoNgay --;

    while (i < SoNgay)
    {
        i++;

        if (*(TongMuaNgay + i) != 0)
        {
        }
        else
        {
            *(DaySellZero + NumberDaySellZero) = i;
            NumberDaySellZero++;
        }
    }

    return NumberDaySellZero;
}


void InitTableFindSum (int *TongMuaNgay, int SoNgay, int *TableFindSum)
{
    int i;

    *TableFindSum = *TongMuaNgay;

    for (i = 1; i < SoNgay; i++)
        *(TableFindSum + i) = *(TableFindSum + i - 1) + *(TongMuaNgay + i);
}


int SumSell_iToj (int *TableFindSum, int Ngayi, int Ngayj)
{
    if (Ngayi == 1)
        return *(TableFindSum + Ngayj - 1);
    else
        return (*(TableFindSum + Ngayj - 1) - *(TableFindSum + Ngayi - 2));
}


int FindZeroPeriod (int *DaySellZero, int NumberDaySellZero, ZeroPeriod *ZeroPeriodArray)
{
    int i = 0, NumberZeroPeriod = 0;

    AddSentinel(DaySellZero, NumberDaySellZero, -1);

    while (i < NumberDaySellZero)
    {
        (*(ZeroPeriodArray + NumberZeroPeriod)) .start = *(DaySellZero + i);

        while ((*(DaySellZero + i + 1) - *(DaySellZero + i)) == 1)
        {
            i++;
        }

        (*(ZeroPeriodArray + NumberZeroPeriod)) .end = *(DaySellZero + i);
        NumberZeroPeriod++;

        i++;
    }

    return NumberZeroPeriod;
}


void WriteFile (int TongMuaNgay[], int SoNgay, int MaxDay, int DaySellZero[], int NumberDaySellZero, int Sumij, ZeroPeriod ZeroPeriodArray[], int NumberZeroPeriod)
{
    FILE *f;
    f = fopen ("output.txt", "wt");

    int i;

    fprintf (f, "Phan 1\n");

    for (i = 0; i < SoNgay; i++)
        fprintf (f, "%d - %d\n", i + 1, TongMuaNgay [i]);

    fprintf (f, "Phan 2\n");

    fprintf (f, "%d - %d\n", MaxDay + 1, TongMuaNgay [MaxDay]);

    for (i = 0; i < NumberDaySellZero; i++)
        fprintf (f, "%d - %d\n", DaySellZero[i] + 1, 0);

    fprintf (f, "Phan 3\n");

    fprintf (f, "%d\n", Sumij);

    fprintf (f, "Phan 4\n");

    for (i = 0; i < NumberZeroPeriod; i++)
        fprintf (f, "%d - %d\n", ZeroPeriodArray[i] .start + 1, ZeroPeriodArray[i] .end + 1);

    fclose (f);
}
