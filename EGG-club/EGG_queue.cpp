#include <stdio.h>
#include <stdlib.h>
int begin=-1,end=-1,stop=0;
int* queue=(int*)malloc(100*sizeof(int));
int isempty()
{
	if(begin==end)
	return 1;
	return 0;
}
void push(int x)
{
	queue[end]=x;
	end++;
}
void pop()
{
	if(isempty())
	{
		stop=1;
	}
	else
	{
		free( queue+begin );
		begin++;
	}
	  
}
int main()
{
	FILE *f;
	f=fopen("test_case","r");
	if(f==NULL)
	{
		printf("\nkhong mo duoc file");
	}
	else
	{
		int x,tmp;
		while(fscanf(f,"%d",&x)!=EOF)
		{
			if(x==0)
			{
				fscanf(f,"%d",&tmp);
				printf("\n%d",tmp);
				push(tmp);
			}
			else
			  pop();
			    
		}
	}
	if(stop!=1)
	{
		printf("\n day trong queue: \n");
		for(int i=begin;i<end;i++)
	    { 
		    printf("  %d",queue[i]);
	    }
	}
	else
	   printf("\n ----------------thao tac pop sai -----------------");
	fclose(f);
	return 0;
}
