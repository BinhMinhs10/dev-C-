#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int top=-1,stop=0;
int* stack=(int*)malloc(100*sizeof(int));
int isempty()
{
	if(top==-1)
	  return 1;
	return 0;
}
void pop()
{
	if(top==-1)
	{
		//printf("\nstack is empty");
		stop=1;
	}
    else
    {
    	free(stack+top);
    	top=top-1;
    }
}
int push(int x)
{
	top=top+1;
	stack[top]=x;
	return x;
}
void readdata(char *name)
{
	FILE *f;
    f=fopen(name,"r");
    if(f==NULL)
    {
    	printf("khong mo duoc file");
    }
    else
    {
    	int x,tmp;
    	while(fscanf(f,"%d",&x)!=EOF)
    	{
    		if(x==0)
			{
				fscanf(f,"%d",&tmp);
				printf("\t%d",tmp); 
    			push(tmp);
    		}
    		else
    		{
    			pop();
    			//flag=pop();
    		}
    	}
    }
    fclose(f);
}
int main()
{
	readdata("test_case");
	if(stop==0)
	{
		printf("\n cac phan tu trong danh sach: \n");
		for(int i=0;i<=top;i++)
		  printf("  %d",stack[i]);
	}
	else
	  printf("\n------------thao tac pop element sai !--------------");
	return 0;
}
