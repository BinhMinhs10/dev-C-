#include <stdio.h>
#include <conio.h>
main()
{
	int i,n,d,mangnguyen[10],N,s;
	do{
		printf("nhap so nguyen N");
		scanf("%d",&N);
	}while(N<0||N>10);
	for(i=0;i<N;i++)
	{
		printf("\nnhap phan tu thu %d: ",i+i);
		scanf("%d",&mangnguyen[i]);
		
	}
	printf("\n mang vua nhap la:");
	for(i=0;i<N;i++)
	printf("%3d",mangnguyen[i]);
	s=0;  d=0;
	for(i=1;i<N;i++)
	{
		if(mangnguyen[i]==mangnguyen[i-1]+mangnguyen[i+1])
		{
		s=s+mangnguyen[i];
		d++;
	    }
	}
	if(d==0)
	printf("\n khong co phan tu xung quanh ");
	else
	printf("\n tong cac phan tu xung quanh cua mang: %3d",s);
	getch();
	return 0;
}
