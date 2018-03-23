struct Word
{
    char English_Word [31];
    char Vietnamese_Meaning [100];
};

typedef struct Word ElementType;

struct  PointerType
{
    ElementType Inf;
    struct PointerType *Next;
};

typedef struct PointerType PointerType;
int n;


PointerType *OrderInsert (PointerType *First, ElementType x);//Chen vao danh sach lien ket theo thu tu abc
PointerType *DeleteNode (PointerType *First, int RanDom);//Xoa tu o vi tri RanDom khoi danh sach lien ket
PointerType *InsertMiddle (PointerType *Prev, ElementType x);
PointerType *InsertToHead (PointerType *First, ElementType x);
PointerType *InsertToLast (PointerType *First, ElementType x);
ElementType Delete(PointerType *Prev);
PointerType *DeleteHead(PointerType *First);
PointerType *DeleteLast(PointerType *First);
int IsEmpty(PointerType *First);
PointerType *MakeNull(PointerType *First);
void Print(PointerType *First);

//Chen 1 phan tu vao giua
PointerType *InsertMiddle (PointerType *Prev, ElementType x)
{
    PointerType *TempNode;
    TempNode = (PointerType *) malloc (sizeof (PointerType));
    TempNode->Inf = x;
    TempNode->Next = Prev->Next;
    Prev->Next = TempNode;
    return TempNode;
}

//Chen 1 phan tu vao dau
PointerType *InsertToHead (PointerType *First, ElementType x)
{
    PointerType *TempNode;
    TempNode = (PointerType *) malloc (sizeof (PointerType));
    TempNode->Next = First;
    TempNode->Inf = x;
    First = TempNode;
    return First;
}

//Chen 1 phan tu vao cuoi
PointerType *InsertToLast (PointerType *First, ElementType x)
{
    PointerType *TempNode, *NewNode;
    NewNode = (PointerType *) malloc (sizeof (PointerType));
    TempNode = First;
    while (NULL!= TempNode->Next)
        TempNode = TempNode->Next;
    TempNode->Next = NewNode;
    NewNode->Inf = x;
    NewNode->Next = NULL;
    //NewNode->Next = NULL;
    return NewNode;
}

//Chen 1 phan tu vao danh sach lien ket theo thu tu abc
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

//Xoa tu o vi tri RanDom khoi danh sach lien ket
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
ElementType Delete(PointerType *Prev)
{
    PointerType *TempNode; ElementType X;

    TempNode = Prev->Next;
    X = TempNode->Inf;

    Prev->Next = Prev->Next->Next;

    free (TempNode);
    return X;
}

PointerType *DeleteHead (PointerType *First)
{
    PointerType *TempNode;

    TempNode = First->Next;

    free (First);
    return TempNode;
}

PointerType *DeleteLast (PointerType *First)
{
    PointerType *TempNode, *Temp1;
    TempNode = First;

    while (TempNode->Next->Next != NULL)
    {
        TempNode = TempNode->Next;
    }

    Temp1 = TempNode->Next;
    TempNode->Next = NULL;

    free (Temp1);
    return First;
}

PointerType *MakeNull(PointerType *First)
{
    int i;
    for (i = 0; i < n; i++)
        First = DeleteHead(First);
    return First;
}

void Print(PointerType *First)
{
    PointerType *TempNode;

    TempNode = First;
    printf("%d", n);

    while(TempNode!=NULL)
    {
        printf("%s\n",TempNode->Inf.English_Word);
        TempNode = TempNode->Next;
    }
}
