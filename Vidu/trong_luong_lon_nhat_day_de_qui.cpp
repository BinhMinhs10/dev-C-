#include <stdio.h>
#include <conio.h>
maxright (a,i,j)
{
	int i,j;
	maxsum=-99999999999; sum=0;
	for(int k=i;k=j;k++){
		sum=sum+a[k];
		maxsum=sum>maxsum?sum:maxsum;
	}
	return maxsum;
};
maxleft(a,i,j);
{
	maxsum=-99999999999; sum=0;
	for(int k=j;k=i;k--){
		sum=sum+a[k];
		maxsum=sum>maxsum?sum:maxsum;
	}
	return maxsum;
}
maxsub(a,i,j);
{
	if (i=j) return a[i];
	else
	{
		m=(i+j)/2;
		wl=maxleft(a,i,m);
		wr=maxright(a,m+1,j);
		wm=maxsub(a,i,m)+maxsub(a,m+1,j);
		return max(wl,wr,wm);
	}
}
main()
{
	int l,a[23];
	printf("nhap so phan tu day con: "); scanf("%d",&n);
	for(l=0;l<n;l++){
		printf("a[%d]= ",l+1);
		scanf("%d",&a[l]);
	}
	printf("tong day la: %d",maxsub);
}
