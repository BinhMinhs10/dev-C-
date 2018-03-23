#include <stdio.h>
#include <conio.h>
#include <string.h>
enum {MAX_WORD_LEN = 20};
enum {MAX_LINE_LEN = 50};
int IsWhilespace(int ch){
	return (ch=='\n')||(ch=='\t')||(ch==' ');
}
int ReadWord(char *word){
	int ch,pos=0;
	/*Bo qua ki tu cach*/
	ch=getchar();
	while(IsWhilespace(ch)){
		ch=getchar();
	}
	while(!IsWhilespace(ch)&&(ch!=EOF)){
		if(pos<MAX_WORD_LEN){
			word[pos]=(char)ch;
			pos++;
		}
		ch=getchar();
	}
	word[pos]='\0';
	//tra ve do dai tu
	return pos;
	
}
void AddWord(const char *word,char *line, int *linelen){
	if(*linelen>0){
		line[*linelen]=' ';
		line[*linelen + 1]='\0';
		(*linelen)++;
	}
	strcat(line,word);
	(*linelen)+= strlen(word);
}
void WriteLine(const char *line, int linelen, int numWords){
	int extraSpaces, spacesToInsert,i,j;
	for(i=0;i<linelen;i++){
		if(line[i]!=' ')
			putchar(line[i]);
		else{
			spacesToInsert = extraSpaces /(numWords - 1);
			for(j=1;j<=spacesToInsert + 1;j++ )
			      putchar(' ');
			extraSpaces -= spacesToInsert;
			numWords--;
		}
	}
	putchar('\n');
}
void ClearLine(char *line,int *linelen,int *numWords){
	line='\0';
	*linelen=0;
	*numWords=0;
}
int main(){
	char* name;
	printf("nhap file input: "); gets(name);
	FILE *f=fopen(name,"r");
	if(f==NULL) printf("\ncan't open file");
	else{
		char word[MAX_WORD_LEN + 1];
	    int wordlen;
	    char line[MAX_WORD_LEN + 1];
	    int linelen=0;
	    int numWords=0;
	    ClearLine(line,&linelen,&numWords);
	    for( ; ; ){
	    	
		     wordlen=ReadWord(word);
		     /*neu het tu in dong khong can le */
		     if((wordlen==0)&&(linelen>0)){
			       puts(line);
			       break;
		     }
		      if((wordlen + 1 + linelen) > MAX_LINE_LEN){
			      WriteLine(line, linelen, numWords);
			    ClearLine(line,&linelen,&numWords);
		      }
		    AddWord(word,line,&linelen);
		    numWords++;
	    }
	}
	fclose(f);
	return 0;
}
