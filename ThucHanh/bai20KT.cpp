#include <stdio.h>
#include <conio.h>
main()
{
	int tg,i,M,N,s=0;
	do{
		printf("nhap M :");  scanf("%d",&M);
		printf("\n nhap N: "); scanf("%d",&N);
	}while((M<=0)||(N<=0));
	if(N>M){
		tg=N; N=M; M=tg;
	}
	for(i=1;i<=N;i++)
	{
		if(((M%i)==0)&&((N%i)==0))
		s=s+i;
	}
	printf("tong cac uc cua %d va %d la: %d",M,N,s);
	getch();
	return 0;
}
