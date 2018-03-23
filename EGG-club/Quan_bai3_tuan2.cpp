#include<stdlib.h>
#include<stdio.h>
int main()
{
    FILE *f=fopen("input.txt","rt");
    char temp;
    if (f==NULL)
    {
        printf("Khong mo duoc tep");
        exit(1);
    }
    else
    {
       fflush(stdin);
       while(1)
       {
            fscanf(f,"%c",&temp);
            if (feof(f))
                break;
            fprintf(stdout,"%c",temp);
       }
    }
    fclose(f);
    return 0;
}
