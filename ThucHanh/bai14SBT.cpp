#include <stdio.h>
#include <conio.h>
int main()
{
	FILE *f; int i,a[10],b[10];
	for(i=0;i<10;i++){
		printf("\n a[%d]=",i);
		scanf("%d",&a[i]);
		
	}
	f=fopen("C:\\SONGUYEN.SL","wb");
	fwrite(a,sizeof(a),1,f);
	fclose(f);
	f=fopen("C:\\SONGUYEN.SL","rb");
	fread(b,sizeof(a),1,f);
	fclose(f);
	printf("\nDay so doc duoc la: ");
	for(i=0;i<10;i++) printf("\n%d",b[i]);
	getch();
	return 1;
}
