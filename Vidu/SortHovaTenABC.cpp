#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    char name[]="nguyen binh minh",name1[]="chu van an",
        buff[30],buff1[30];
    int doi=0;
    char *tmp;
    strcpy( buff, strrev( name ) );
    strcpy( buff1, strrev( name1 ) );
    char *token = strtok( buff, " " );
    char *token1 = strtok( buff1, " " );
    while ( token != NULL && token1 != NULL )
    {
         strrev( token ) ;
         strrev( token1 ) ;
         printf("-------%s",token); printf("-------%s",token1);
         if(strcmp(token,token1)>0){
         	doi=1;
         	break;
         }
        token = strtok( NULL, " " );//lay token tiep theo
        token1 = strtok( NULL, " " );//lay token tiep theo
    } // end while
    strrev(name); strrev(name1);
    if(doi==1){
    	tmp=name;
    	strcpy(name,name1);
    	
    }
    printf("\n%s",name);
    printf("\n%s",tmp);
    return 0;
}
