#include<stdio.h>
char end(void);//Tiep tuc thuc hien hay dung chuong trinh
int main()
{
    char mark;
    do
    {
        printf("Nhap vao diem mon hoc DSA:");
        fflush(stdin);
        scanf("%c",&mark);
        switch (mark)
        {
            case 'A': printf("Excellent!"); break;
            case 'B': printf("Very Good"); break;
            case 'C': printf("Good"); break;
            case 'D': printf("You passed!"); break;
            case 'F': printf("Better try again"); break;
            default : printf("Invalid grade"); break;
        }
        printf("\n");
    }while(end());
    return 0;
}
char end(void)
{
	char command,flag;
	do
	{
		printf("Do you want continue (Y/N)?");
		fflush(stdin);
		scanf("%c",&command);
		switch (command)
		{
			case 'y':
			case 'Y':
			case 'N':
			case 'n':
				flag=0; break;
			default:
			{
                puts("No command");
                flag=1;
            }
		}
	}while (flag);
return ((command=='y')||(command=='Y'));
}
