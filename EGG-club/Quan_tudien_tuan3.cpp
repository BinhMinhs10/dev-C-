#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "linked_list.h"


PointerType *ReadFile (void);//Doc tep va ghi du lieu cu tu tep len danh sach lien ket
int WriteFile (void);//Ghi du lieu tu danh sach lien ket vao tep
PointerType *OrderInsert (PointerType *First, ElementType x);//Chen vao danh sach lien ket theo thu tu abc
PointerType *DeleteNode (PointerType *First, int RanDom);//Xoa tu o vi tri RanDom khoi danh sach lien ket
int Add_new_words (void);
int Learn (void);
void Show_English_Word (void);
void Show_Vietnamese_meaning (void);


int n, i, mark = 0;
PointerType *First = NULL;


int main ()
{
    int Mode, Flag = 1;
    //Doc tep va ghi du lieu cu tu tep len danh sach lien ket
    First = ReadFile ();
    //
    do
    {
        system("cls"); 
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
                puts("Press any key to exit...");
                fflush(stdin);
                getchar();
            }
            break;

            case 2:
            {
                if(Learn ())
                {
                    WriteFile();
                    exit (1);
                }
                puts("Press any key to exit...");
                fflush(stdin);
                getchar();
            }
            break;

            case 3:
            {
                printf("Thank you\n");
                Flag = 0;
                break;
            }

            default:
                puts("No command");

        }
    }while (Flag);
    //Ghi tep
    if (WriteFile())
        return 1;
    First = MakeNull (First);
    return 0;
}



/////////////////////////////////////////////////////////////////////////////////
PointerType *ReadFile (void)
{
    FILE *f;
    ElementType TempWord;
    n = 0;
    f = fopen ("dictionary.txt", "rb");

    if (f == NULL)
    {
        printf ("Tep khong ton tai hoac chua tao\n");
        puts("Press any key to continue...");
        fflush(stdin);
        getchar();
    }
    else
    {
        fread (&n, sizeof(n), 1, f);
        fread (&mark, sizeof(n), 1, f);
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
    return First;
}


////////////////////////////////////////////////////////////////////////////////
int WriteFile (void)
{
    PointerType *TempNode;
    FILE *f;
    f = fopen ("dictionary.txt", "wb");
    if (f == NULL)
    {
        printf ("Khong tao duoc tep");
        exit (1);
    }
    else
    {
        fwrite (&n, sizeof(n), 1, f);
        fwrite (&mark, sizeof(n), 1, f);
        TempNode = First;
        while (TempNode != NULL)
        {
            fwrite(&(TempNode->Inf), sizeof(ElementType), 1, f);
            TempNode = TempNode->Next;
        }
        fclose (f);
    }
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////
PointerType *OrderInsert(PointerType *First, ElementType New_Word)
{
    int count, TempInt; PointerType *TempNode;

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
            InsertMiddle (TempNode, New_Word);//Sua o dong nay TempNode->Next thanh TempNode, do khong co First->Next.
            n++;
        }
    }
    return First;
}

//////////////////////////////////////////////////////////////////////////////////
PointerType *DeleteNode (PointerType *First, int RanDom)
{
    PointerType *TempNode = First;
    int j;

    if (RanDom == 1)
    {
        First = DeleteHead (First);//Sua o dong nay ham DeleteHead lam thay doi gia tri cua First nen can gan DeleteHead cho First
        n--;
    }
    else if (RanDom == n)
    {
        DeleteLast (First);
        n--;
    }
    else
    {
        RanDom-=1;
        for (j = 1; j < RanDom; j++)
            TempNode = TempNode->Next;
        Delete (TempNode);
        n--;
    }
    return First;
}

////////////////////////////////////////////////////////////////////////////////
void Show_English_Word (void)
{
    system("cls"); 
    puts ("\t\t    Day la che do Show English Word");
    puts ("\t\t(Qua trinh hoc ket thuc khi ban xau ###)");
    int Flag = 1;
    do
    {
        if (n == 0)
        {
            system("cls"); 
            printf("Da het tu trong tep dictionary.txt.\n");
            printf("Diem cua ban la: %d\n", mark);
            break;
        }
        ElementType TempWord;
        int RanDom = rand() % n + 1;
        PointerType *TempNode = First;
        char TempString[sizeof(TempWord. Vietnamese_Meaning)];
        for (i = 1; i < RanDom; i++)
        {
            TempNode = TempNode->Next;
        }
        TempWord = TempNode->Inf;
        printf ("Day la 1 tu Tieng Anh:\n");
        puts (TempWord. English_Word);
        puts ("Hay go lai nghia Tieng Viet cua tu tren:");

        for (i = 0; i < 3; i++)
        {
            fflush(stdin);
            fgets (TempString, sizeof(TempString), stdin);
            * (TempString + strlen(TempString) - 1) = '\0';
            if (!strcmp(TempString, "###"))
            {
                Flag = 0;
                break;
            }
            if (!strcmp(TempString, TempWord. Vietnamese_Meaning))
            {
                printf ("Ban da nho tu nay.\n");
                mark++;
                //Xoa tu do khoi danh sach lien ket
                First = DeleteNode (First, RanDom);
                break;
            }
            if ( i == 2)
                printf ("Ban chua nho tu nay.\n");
            else
                printf("Ban da go sai xin moi go lai:\n");
        }
    }while (Flag);
}


//////////////////////////////////////////////////////////////////////////////////
void Show_Vietnamese_meaning (void)
{
    system("cls"); 
    puts ("\t\t Day la che do Show Vietnamese meaning");
    puts ("\t\t(Qua trinh hoc ket thuc khi ban xau ###)");
    int Flag = 1;
    do
    {
        if (n == 0)
        {
            system("cls"); 
            printf("Da het tu trong tep dictionary.txt.\n");
            printf("Diem cua ban la: %d\n", mark);
            break;
        }
        ElementType TempWord;
        int RanDom = rand() % n + 1;
        PointerType *TempNode = First;
        char TempString[sizeof(TempWord. English_Word)];
        for (i = 1; i < RanDom; i++)
        {
            TempNode = TempNode->Next;
        }
        TempWord = TempNode->Inf;
        printf("Day la nghia Tieng Viet cua 1 tu:\n");
        puts (TempWord. Vietnamese_Meaning);
        puts ("Hay go lai tu tren bang Tieng Anh");

        for (i = 0; i < 5; i++)
        {
            fflush(stdin);
            fgets (TempString, sizeof(TempString), stdin);
            * (TempString + strlen(TempString) - 1) = '\0';
            if (!strcmp(TempString, "###"))
            {
                Flag = 0;
                break;
            }
            if (!strcmp(TempString, TempWord. English_Word))
            {
                printf ("Ban da nho tu nay.\n");
                mark++;
                //Xoa tu do khoi danh sach lien ket
                First = DeleteNode (First, RanDom);
                break;
            }
            if ( i == 4)
                printf ("Ban chua nho tu nay.\n");
            else
                printf("Ban da go sai xin moi go lai:\n");
        }
    }while (Flag);
}

//////////////////////////////////////////////////////////////////////////////////
int Add_new_words (void)
{
    //Nhap 10 tu moi va xu ly 10 tu nay
    ElementType New_Word;
    printf ("Ban hay nhap 10 tu tieng Anh va nghia tieng Viet cua tung tu:\n");

    system("cls"); 
    for (i = 1; i <= 10; i++)
    {
        printf ("%-2d. Word: ", i);
        fflush(stdin);
        fgets (New_Word. English_Word, sizeof(New_Word. English_Word), stdin);
        * (New_Word. English_Word + strlen(New_Word. English_Word) - 1) = '\0';
        //
        printf ("    Vietnamese meaning: ");
        fflush(stdin);
        fgets (New_Word. Vietnamese_Meaning, sizeof(New_Word. Vietnamese_Meaning), stdin);
        * (New_Word. Vietnamese_Meaning + strlen(New_Word. Vietnamese_Meaning) - 1) = '\0';
        //Chen vao danh sach lien ket theo thu tu abc
        First = OrderInsert (First, New_Word);
    }
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////
int Learn (void)
{
    if (n == 0 )
    {
        printf ("Tep chua tao, hoac rong\n");
        return 1;
    }

    //Phan thao tac tren danh sach lien ket
    int Mode, Flag = 1;
    //
    do
    {
        system("cls"); 
        printf ("1. Show English Word.\n");
        printf ("2. Show Vietnamese meaning.\n");
        printf ("3. Previous.\n");
        fflush(stdin);
        scanf ("%d", &Mode);
        //Cac che do lam viec
        switch (Mode)
        {
            case 1:
            {
                Show_English_Word ();
                puts("Press any key to exit...");
                fflush(stdin);
                getchar();
            }
            break;

            case 2:
            {
                Show_Vietnamese_meaning ();
                puts("Press any key to exit...");
                fflush(stdin);
                getchar();
            }
            break;

            case 3:
            {
                Flag = 0;
                break;
            }

            default:
                puts("No command");

        }
    }while (Flag);
    return 0;
}
