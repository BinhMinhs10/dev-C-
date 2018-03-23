#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Ctype.h>
#include <stdlib.h>

// Gan cac gia tri mac dinh
	int MAX_LINE_LEN=50;  //do dai toi da 1 dong
	int MAX_WORD_LEN=20;  //do dai toi da 1 tu
	char spaceTable[10]={'\n',' ','\t'};  //mang cac ki tu duoc coi la dau cach
	char input[100],output[100];  //mang chua ten file dau vao va dau ra
	int canlevanban=1;  //if canlevanban=0 => can le trai va phai
	int canledongcuoi=1;  //if canledongcuoi=0 => can le trai dong cuoi
    int option; char x;
	int dem=3;
// Ham kiem tra ki tu ch co phai la khoang trang khong

int IsWhitespace(int ch){
	int i=0;
	while(i<=3) 
	{
		if(spaceTable[i]==ch) return 1;                           
		i++;
	}
	return 0;
}

// Ham doc tu file
char* ReadWord_File(char *word, FILE *p){  //p la con tro tro den file dau vao, ket qua doc duoc se luu vao mang word.
	int ch, pos = 0;					 	
	  ch = getc(p);
	while(IsWhitespace(ch))				//bo qua whitespace
		ch = getc(p);
	while(!IsWhitespace(ch) && (!feof(p))){			//luu cac ki tu vao cho den MAX_WORD_LEN
		if (pos < MAX_WORD_LEN){
			word[pos]= (char) ch;
			pos++;
		}
		ch = getc(p);
	}
	word[pos]='\0';
	if(pos==0) return NULL;
	 return word;				//tra ve tu
}
// Ham doc tu ban phim
char* ReadWord_KeyBoard(char *word){
	int ch, pos = 0;
	ch = getchar();
	while(IsWhitespace(ch))	//bo qua whitespace
	  ch = getchar();   
	while(!IsWhitespace(ch) && (ch !='$')){             
		if (pos < MAX_WORD_LEN) {
			word[pos]=(char)ch;
			pos++;
		}
		ch = getchar();
	}
	word[pos]='\0';
	if(pos==0) return NULL;
	return word;                //tra ve tu
}
//do dai word
int CountLenWord(char *word){
	int pos = 0;
	while(word[pos]!='\0'){             
			pos++;
	}
	return pos;
}

// Ham xoa dong

int ClearLine(char *line, int *lineLen, int *numWords) {
	line[0] = '\0';
	*lineLen = 0;
	*numWords = 0;
	return 1;
}

// Ham them mot tu vao dong

void AddWord(const char *word, char *line, int *lineLen) {		//line la dong can them tu vao, lineLen la do dai dong truoc khi them tu
	if(*lineLen > 0) {                                         
		line[*lineLen] = spaceTable[1];
		line[*lineLen + 1] = '\0';
		(*lineLen)++;
	}
	strcat(line, word);
	(*lineLen ) += strlen(word);
}

// Ham in dong ra man hinh

void WriteLine(char *line, int lineLen, int numWords, int option) {		//numWords: so tu dang co trong dong
   
	if(option==0){          //can le hai ben
		int extraSpaces, spacesToInsert,i,j;
		extraSpaces = MAX_LINE_LEN - lineLen;
		for(i=0; i<lineLen; i++) {
		 if(line[i] != ' ' )
			putchar(line[i]);
		 else {
			spacesToInsert = extraSpaces / (numWords - 1);
			for(j=1; j<= spacesToInsert+1; j++)
				putchar(' ');
			extraSpaces -= spacesToInsert;
			numWords--;
		 }
		}
		putchar('\n');
	}
	else if(option==1){      // can le trai
		puts(line);
		putchar('\n'); 
	}
	else {                   //can le phai 
		int i=0;
		while(line[i]!='\0') i++;
		i--;
		while(line[i]== ' '){
			line[i]='\0';
			lineLen--;
		}
		int extraSpaces = MAX_LINE_LEN - lineLen;
		for(i=0;i<extraSpaces;i++) putchar(' ');
		puts(line);
		putchar('\n');
	}
}
// Ham ghi dong ra file
void StoreLine(char *line, int lineLen, int numWords, FILE *q, int option) {
	int i;
	if(option==0){
		int extraSpaces, spacesToInsert,j;
		extraSpaces = MAX_LINE_LEN - lineLen;
		for(i=0; i<lineLen; i++) {
			if(line[i] !=' ')
				fprintf(q,"%c",line[i]);
				else {
					spacesToInsert = extraSpaces / (numWords - 1);
					for(j=1; j<= spacesToInsert+1; j++)
					fprintf(q," ");
					extraSpaces -= spacesToInsert;
					numWords--;
				}
			}
		fprintf(q,"\n");
	}
	else if(option==1){
		fputs(line,q);
		fprintf(q,"\n");
	}	
	else {
		int i=0;
		while(line[i]!='\0') i++;
		i--;
		while(line[i]==' '){
			line[i]='\0';
			lineLen--;
		}
		int extraSpaces = MAX_LINE_LEN - lineLen;
		for(i=0;i<extraSpaces;i++) fprintf(q,"%c",' ');
		fputs(line,q);
		fprintf(q,"\n");
	}
}
int PrintMenu1(){
	int input;
	printf("-------------------------------------------------------------------------");
	printf("\nBuoc 1. Tuy chinh cach thuc trinh bay van ban");
	printf(     "\nNhan 1 de quy dinh so ky tu toi da tren mot dong"
			    "\nNhan 2 de quy dinh ky tu nao la ky tu khoang trang"
		 	    "\nNhan 3 de quy dinh cach thuc can le cho van ban"
		     	"\nNhan 4 de quy dinh cach thuc can le cho dong cuoi cung"
		     	"\nNhan 5 de bo qua thao tac nay hoac xac nhan da tuy chinh xong"
	  			"\n**Luu y: Neu nguoi dung khong quy dinh, chuong trinh se su dung cac gia tri mac dinh, mot tu toi da 20 ki tu.\n"
				  "->");
	  	scanf("%d",&input);
	return input;
}
int PrintMenu2(){
	int input;
	printf("-------------------------------------------------------------------------");
	printf( "\nBuoc 2. Chon cach thuc nhap xuat van ban");
		printf(	"\nNhap tu ban phim, xuat ra man hinh, nhan 1"
				"\nNhap tu ban phim, xuat ra file, nhan 2"
				"\nNhap tu file, xuat ra man hinh, nhan 3"
				"\nNhap tu file, xuat ra file, nhan 4\n"
				"->");
		scanf("%d",&input);
	return input;
}
int MaxLine(){
	int max;
	printf("\n Nhap so ki tu toi da tren mot dong:	");
	scanf("%d",&max);
	return max;	
}
char BackMenu(){
	char opt;
	printf("\n Quay lai bang tuy chinh?(c/k) "); 
	fflush(stdin); scanf("%c",&opt);
	return opt;
}
void luachoncanle(int flag){   //in chua luon cach can le
	if(flag==0) printf("Can giua");
	else if(flag==1) printf("Can trai");
	else if(flag==2) printf("Can phai");
}
void InputAndOutput(int flag){
	if(flag==1) printf(	"\nnhap tu ban phim, xuat ra man hinh");
	else if(flag==2) printf("\nnhap tu ban phim, xuat ra file");
	else if(flag==3) printf("\nnhap tu file, xuat ra man hinh");
	else if(flag==4) printf("\nnhap tu file, xuat ra file");
	
}
void Design(int _MAX_LINE_LEN,int _canlevanban, int _canledongcuoi, int _dem,char* _spaceTable,int _option ){
	int i;
	printf("\nSo ki tu toi da tren mot dong: %d",_MAX_LINE_LEN);
	printf("\nKi tu la khoang trang: ");
	for( i=1 ; i<=_dem ; i++){
		printf("%c ",_spaceTable[i]);
	}
	printf("\nCach can le van ban: ");
	luachoncanle(_canlevanban);
	printf("\nCach can le dong cuoi: ");
	luachoncanle(_canledongcuoi);
	printf( "\nCach thuc nhap xuat van ban: ");
	InputAndOutput(_option);
	printf("\n");
}
int main(void) {
	// Khai bao cac bien trung gian
	int i;
	
	// Bat dau chuong trinh
	do{
		option = PrintMenu1();
	  	switch(option){
	  		case 1: {
	  			MAX_LINE_LEN = MaxLine();
	  			MAX_WORD_LEN = MAX_LINE_LEN - 1 ;
	  			x = BackMenu();
	  			break;
			}
			case 2: {
				printf("\n **Luu y chuong trinh mac dinh ky tu xuong dong luon la khoang trang\n");
	  			printf("\n Nhap so ki tu khac duoc coi la khoang trang (toi da 10 ki tu):	");
				scanf("%d",&dem);
	  			if((dem<=10)&&(dem>0)) {
				  	for(i=1;i<=dem;i++) {
	  					printf("\n	Ky tu thu %d la: ",i);
						fflush(stdin); 
						scanf("%c",&spaceTable[i]);
					}
					spaceTable[dem+1]='\0'; 
				}
				else {
					printf("Syntax error");
					dem=0;
				}
	  			x = BackMenu();
				break;
			}
			case 3: {
	  			printf( "\n Nhap cach thuc can le cho van ban"
				  		"\n Nhan 0 de can le deu hai ben"
						"\n Nhan 1 de can le trai"
						"\n Nhan 2 de can le phai\n"
						"->");
			    scanf("%d",&canlevanban);
				if((canlevanban!=0)&&(canlevanban!=1)&&(canlevanban!=2))
				{
					printf("\nSyntax error");
					canlevanban=0;
				}
	  			x = BackMenu();
				break;
			}
			case 4: {
	  			printf( "\n Nhap cach thuc can le cho dong cuoi"
				  		"\n Nhan 0 de can le deu hai ben"
						"\n Nhan 1 de can le trai"
						"\n Nhan 2 de can le phai\n"
						"->");
				scanf("%d",&canledongcuoi);
				if((canledongcuoi!=0)&&(canledongcuoi!=1)&&(canledongcuoi!=2))
				{
					printf("\nSyntax error");
					canledongcuoi=0;
				}
	  			x = BackMenu();
				break;
			}
			case 5: {
				x = BackMenu();
				break;
			}
			default: {
				printf("\nSyntax error");
	  			x = BackMenu();
				break;
			}
		}
	} while(toupper(x)!='K');
	
	// Khai bao cac bien phuc vu chuong trinh
	char word[MAX_WORD_LEN + 1];
	int wordLen;
	char line[MAX_LINE_LEN + 1];
	int lineLen = 0;
	int numWords = 0;
	ClearLine(line, &lineLen, &numWords);
	
	// Buoc 2
	option = PrintMenu2();
	
	// Cac thao tac da lua chon
	system("cls");
	Design( MAX_LINE_LEN, canlevanban, canledongcuoi, dem, spaceTable, option);
	//
		switch(option){
			case 1: {
				printf("\n**Luu y: De ket thuc thao tac nhap van ban, hay go lan luot 'Enter','$' va 'Enter'\n");
				FILE *q=fopen("temp.txt","w");
				while(1) {
					ReadWord_KeyBoard(word);
					wordLen = CountLenWord(word);
					if((wordLen == 0) && (lineLen > 0)) {
						StoreLine(line, lineLen, numWords, q, canledongcuoi);
						break;
					}
					 if((wordLen + 1 +lineLen) > MAX_LINE_LEN) {
						StoreLine(line, lineLen, numWords, q, canlevanban);
						ClearLine(line, &lineLen, &numWords);
					}
					AddWord(word, line, &lineLen);
					numWords++;
				}
				  fclose(q);
				  FILE *p=fopen("temp.txt","r");
				  printf("\n	Van ban sau khi duoc can le la:\n\n");
				   char temp;
				  fscanf(p,"%c",&temp);
				while(!feof(p)){
					printf("%c",temp);
					fscanf(p,"%c",&temp);
				}
				fclose(p);
				break;
			}
			case 2: {
				printf("\nNhap ten file de ghi du lieu: "); fflush(stdin); gets(output);
				printf("\n**Luu y: De ket thuc thao tac nhap van ban, hay go lan luot 'Enter','$' va 'Enter'\n");
				printf("\nNhap van ban o duoi day\n");
				FILE *q=fopen(output,"w");
				while(1) {
				    ReadWord_KeyBoard(word);
					wordLen = CountLenWord(word);
					if((wordLen == 0) && (lineLen > 0)) {
						StoreLine(line, lineLen, numWords, q, canledongcuoi);
						break;
					}
					else if((wordLen + 1 +lineLen) > MAX_LINE_LEN) {
						StoreLine(line, lineLen, numWords, q, canlevanban);
						ClearLine(line, &lineLen, &numWords);
						AddWord(word,line,&lineLen);
						numWords++; 
					}
					else {
					AddWord(word, line, &lineLen);
					numWords++;
					}
				}
				fclose(q);
				printf("\n Da luu file thanh cong");
				break;
			}
			case 3: {
				printf("\nNhap ten file de doc du lieu: "); fflush(stdin); gets(input);
				FILE *p=fopen(input,"r");
				if(p==NULL){
					printf("\nCan't open file!");
					break;
				}
				printf("\n--------------Van ban sau khi duoc can le la: \n\n");
				while(1) {
					ReadWord_File(word,p);
					wordLen = CountLenWord(word);
					if((wordLen == 0) && (lineLen > 0)) { // Can le cho dong cuoi o day
						WriteLine(line, lineLen, numWords,canledongcuoi);
						break;
					}
					if((wordLen + 1 +lineLen) > MAX_LINE_LEN) {
						WriteLine(line, lineLen, numWords,canlevanban);
						ClearLine(line, &lineLen, &numWords);
						
					}
						AddWord(word, line, &lineLen);
						numWords++;
			
				}
				fclose(p);
				break;
			}
			case 4: {
				printf("\nNhap ten file de doc du lieu:	"); fflush(stdin); gets(input);
				printf("\nNhap ten file de ghi du lieu: "); fflush(stdin); gets(output);
				FILE *p=fopen(input,"r");
				FILE *q=fopen(output,"w");
				while(1) {
					ReadWord_File(word,p);
					wordLen = CountLenWord(word);
					if((wordLen == 0) && (lineLen > 0)) {
						StoreLine(line, lineLen, numWords, q, canledongcuoi);
						break;
					}
					else if((wordLen + 1 +lineLen) > MAX_LINE_LEN) {
						StoreLine(line, lineLen, numWords, q, canlevanban);
						ClearLine(line, &lineLen, &numWords);
						AddWord(word,line,&lineLen);
						numWords++;
					}
					else {
					AddWord(word, line, &lineLen);
					numWords++;
					}
				}
				fclose(p);
				fclose(q);
				printf("\n Da luu vao file %s thanh cong",output);
				break;
			}
			default: {
				printf("\n Syntax error");
				break;
			}
		}
}



