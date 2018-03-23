#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <cstdio>
int main()
{
    FILE *fpInput=fopen("C:\\Users\\ThuyLinh Computer\\Documents\\dev-C++\\vocabs","r");
	if(fpInput==NULL)
	{
		printf("khong mo duoc tep\n");
		//exit 1;
	}	
	string word;
	string vocabs[20];
	int numberofword=0;
	while(fscanf(fpInput,"%s",word)!=EOF)
	{
		vocabs[numberofword]=word;
		numberofword++;
	}
	fclose(fpInput);
	vocabs[numberofword++]="keyboard";
	vocabs[numberofword++]="shoe";
	FILE *fpOutput=fopen("C:\\Users\\ThuyLinh Computer\\Documents\\dev-C++\\vocabs","w");
	for(int i=0;i<numberofword;i++)
	{
		fprintf(fpOutput,"%s",vocabs[i]);
		
	}
	fclose(fpOutput);
	return 0;
}
