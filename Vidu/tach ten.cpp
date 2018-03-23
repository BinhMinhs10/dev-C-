#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    char name[]="Ho Van Ten",
        buff[30];
    strcpy( buff, strrev( name ) );
    char *token = strtok( buff, " " );
    while ( token != NULL )
    {
        printf ( "%s", strrev( token ) );
        printf("\n");
        token = strtok( NULL, " " );//lay token tiep theo
    } // end while
    getch();
    return 0;
}
