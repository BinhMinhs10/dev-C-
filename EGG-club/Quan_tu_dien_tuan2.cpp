#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int Add_new_words (void);

int Learn (void);

int main ()
{
    int Mode, Flag = 1;
    //
    do
    {
        printf ("Ban hay chon che do hoc (1/ 2/ 3):\n");
        printf ("1. Add-new-words.\n");
        printf ("2. Learn.\n");
        printf ("3. Thoat.\n");
        fflush(stdin);
        scanf ("%d", &Mode);
        //Cac che do lam viec
        switch (Mode)
        {
            case 1:
            {
                if(Add_new_words ())
                    exit (1);
            }
            break;
            if (Flag == 0)
                break;
            case 2:
            {
                if(Learn ())
                    exit (1);
            }
            break;
            case 3:
            {
                printf("Thank you\n");
                Flag = 0;
                break;
            }

            default:
            {
                puts("No command");
            }
        }
    }while (Flag);
    return 0;
}

int Add_new_words (void)
{
    FILE *f;
    int i, n = 0; //ElementType TempWord;
    //PointerType *Last = NULL;
    PointerType *First = Last;
    //Doc tep
    f = fopen ("dictionary.txt", "rb");

    if (f == NULL)
    {
        printf ("Tep khong ton tai hoac chua tao\n");
    }
    else
    {
        fread (&n, sizeof(n), 1, f);
        //Ghi 1 phan tu vao dau danh sach lien ket
        fread (&TempWord, sizeof(ElementType), 1, f);
        First = InsertToHead (First, TempWord);
        //
        for (i = 1; i < n; i++)
        {
            fread (&TempWord, sizeof(ElementType), 1, f);
            InsertToLast (First, TempWord);
        }
        fclose(f);
    }
    Print(First);
    //Nhap 10 tu moi va xu ly 10 tu nay

    int count, TempInt; ElementType New_Word; PointerType *TempNode;
    printf ("Ban hay nhap 10 tu tieng Anh va nghia tieng Viet cua tung tu:\n");
    for (i = 1; i <= 10; i++)
    {
        printf ("%-2d. Word: ", i);
        __fpurge (stdin);
        fgets (New_Word. English_Word, sizeof(New_Word. English_Word), stdin);
        * (New_Word. English_Word + strlen(New_Word. English_Word) - 1) = '\0';
        //
        printf ("    Vietnamese meaning: ");
        __fpurge (stdin);
        fgets (New_Word. Vietnamese_Meaning, sizeof(New_Word. Vietnamese_Meaning), stdin);
        * (New_Word. Vietnamese_Meaning + strlen(New_Word. Vietnamese_Meaning) - 1) = '\0';
        //Chen vao linked list

        if ( n == 0)
        {
            First = InsertToHead (First, New_Word);
            n++;
        }
        else
        {
            count = 0; TempInt = 0; //Sua o dong nay, them TempInt = 0
            TempNode = First;
            while (TempNode != NULL)
            {
                TempInt = strcmp ((TempNode->Inf).English_Word, New_Word. English_Word);// TH i:
                if (TempInt >= 0 ) //Sua o dong nay sua > thanh >=
                    break;
                count++;
                TempNode = TempNode->Next;
            }
            int j; TempNode = First;
            if (count == 0)
            {
                First = InsertToHead (First, New_Word);
                n++;
            }
            else if (count == n )
            {
                InsertToLast (First, New_Word);
                n++;
            }
            else
            {
                count -= 1; //Sua o dong nay count -= 2 thanh count -= 1
                for (j = 0; j < count; j++)
                    TempNode = TempNode->Next;
                InsertMiddle (TempNode, New_Word);//Sua o dong nay TempNode->Next thanh TempNode
                n++;
            }
        }
    }
    Print(First);
    //Ghi tep
    f = fopen ("dictionary.txt", "w+b");
    if (f == NULL)
    {
        printf ("Khong mo duoc tep");
        exit (1);
    }
    else
    {
        fwrite (&n, sizeof(n), 1, f);
        TempNode = First;
        while (TempNode != NULL)
        {
            fwrite(&(TempNode->Inf), sizeof(ElementType), 1, f);
            TempNode = TempNode->Next;
        }
        fclose (f);
    }
    First = MakeNull (First);
    return 0;
}

int Learn (void)
{
    FILE *f;
    int i, n = 0; ElementType TempWord;
    PointerType *Last = NULL;
    PointerType *First = Last;
    //Doc tep
    f = fopen ("dictionary.txt", "rb");

    if (f == NULL)
    {
        printf ("Tep khong ton tai hoac chua tao\n");
        exit (1);
    }
    else
    {
        fread (&n, sizeof(n), 1, f);
        //Ghi 1 phan tu vao dau danh sach lien ket
        fread (&TempWord, sizeof(ElementType), 1, f);
        First = InsertToHead (First, TempWord);
        //
        for (i = 1; i < n; i++)
        {
            fread (&TempWord, sizeof(ElementType), 1, f);
            InsertToLast (First, TempWord);
        }
        fclose(f);
    }
    //Mo tep de ghi
    f = fopen ("dictionary.txt", "wb");
    if (f == NULL)
    {
        printf ("Khong tao duoc tep");
        exit (1);
    }
    else
    {
        int i, j, RanDom = rand() % n; char TempString[sizeof(TempWord. English_Word)];

        PointerType *TempNode = First;
        for (i = 0; i < RanDom; i++)
        {
            TempNode = TempNode->Next;
        }
        TempWord = TempNode->Inf;
        printf("Day la nghia Tieng Viet cua 1 tu:\n");
        puts (TempWord. Vietnamese_Meaning);
        puts ("Hay go lai tu tren bang Tieng Anh");
        int N = n - 1;
        for (i = 0; i < 5; i++)
        {
            __fpurge (stdin);
            fgets (TempString, sizeof(TempString), stdin);
            * (TempString + strlen(TempString) - 1) = '\0';
            if (!strcmp(TempString, TempWord. English_Word))
            {
                printf ("Ban da nho tu nay.\n");
                //Xoa tu do khoi danh sach lien ket
                TempNode = First;
                if (RanDom == 0)
                {
                    DeleteHead (First);
                    n--;
                }
                else if (RanDom == N)
                {
                    DeleteLast (First);
                    n--;
                }
                else
                {
                    RanDom--;
                    for (j = 0; j < RanDom; j++)
                        TempNode = TempNode->Next;
                    Delete (TempNode);
                    n--;
                }
                break;
            }
            printf("Ban da go sai xin moi go lai:\n");
        }
        if ( i == 5)
            printf ("Ban chua nho tu nay.\n");
        Print(First);
        f = fopen ("dictionary.txt", "wb");
        if (f == NULL)
        {
            printf ("Khong tao duoc tep");
            exit (1);
        }
        else
        {
            fwrite (&n, sizeof(n), 1, f);
            TempNode = First;
            while (TempNode != NULL)
            {
                fwrite(&(TempNode->Inf), sizeof(ElementType), 1, f);
                TempNode = TempNode->Next;
            }
            fclose (f);
        }
    }
    First = MakeNull (First);
    return 0;
}
