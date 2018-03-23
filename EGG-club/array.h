#include <stdio.h>
#include <conio.h>
#include <math.h>

typedef struct array{
	int count;
	float max[1000];
} Array;

Array makeArray()
{
	int n;
	printf("\nNhap so phan tu cua mang muon khoi tao:"); scanf("%d",&n);
	Array a;
	a.count=n;
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nmax[%d]=",i);
		scanf("%f",&a.max[i]);
	}
	return a;
}

void gangiatri(Array a)
{
	int n;
	printf("\nNhap phan tu cua mang muon khoi tao:"); scanf("%d",&n);
	a.count=n;
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nNhap gia tri cua phan tu thu %d:",i+1); 
		scanf("%f",&a.max[i]);
	}
	printf("\nKet qua sau khi gan gia tri la:");
	for(i=0;i<n;i++)
	{
		printf("%f ",a.max[i]);
	}
}

void swap(float *a, float *b){
	float temp=*a;
	*a=*b;
	*b=temp;
}

void bubbleSort(Array a)
{
	int i,j;
	for(i=a.count-1;i>=0;i--){
		for(j=1;j<=i;j++){
			if(a.max[j-1]>a.max[j])
			swap(&a.max[j-1],&a.max[j]);
		}
	}
	printf("\nKet qua sau khi sap xep la:\n");
	for(i=0;i<a.count;i++)
	printf("%f ",a.max[i]);
}

void insertionSort(Array a)
{
	int i,j;
	float last;
	for(i=1;i<a.count;i++)
	{
		last=a.max[i]; //phan tu can chen vao mang
		j=i;
		while(j>0&&a.max[j-1]>last)
		{
			a.max[j]=a.max[j-1]; //day phan tu lon hon last len 1 nhip
			j--;
		}
		a.max[j]=last; //chen phan tu vao
	}
		printf("\nKet qua sau khi sap xep la:\n");
	for(i=0;i<a.count;i++)
	printf("%f ",a.max[i]);
}

void selectionSort(Array a)
{
	int i,j,min;
	for(i=0;i<a.count;i++)
	{
		min=i;
		for(j=i+1;j<a.count;j++)
		{
			if(a.max[j]<a.max[min]) min=j;
		}
		swap(&a.max[i],&a.max[min]);
	}
		printf("\nKet qua sau khi sap xep la:\n");
	for(i=0;i<a.count;i++)
	printf("%f ",a.max[i]);
}

void findMax(Array a)
{
	int i;
	float max=a.max[0];
	for(i=0;i<a.count;i++)
	{
		if(a.max[i]>max) max=a.max[i];
	}
	printf("\nPhan tu lon nhat la %f",max);
	printf("\nVi tri cac phan tu lon nhat la:\n");
	for(i=0;i<a.count;i++)
	{
		if(a.max[i]==max) printf("%d ",i);
	}
}

void findMin(Array a)
{
	int i;
	float min=a.max[0];
	for(i=0;i<a.count;i++)
	{
		if(a.max[i]<min) min=a.max[i];
	}
	printf("\nPhan tu nho nhat la %f",min);
	printf("\nVi tri cac phan tu nho nhat la:\n");
	for(i=0;i<a.count;i++)
	{
		if(a.max[i]==min) printf("%d ",i);
	}
}

float average(Array a)
{
	float sum=0;
	int i;
	for(i=0;i<a.count;i++) sum=sum+a.max[i];
	printf("\nGia tri trung binh cua cac phan tu trong mang la %f",sum/a.count);
	return sum/a.count;
}

void sub(Array a)
{	int i,j;
	printf("\nNhap vi tri phan tu dau tien:"); scanf("%d",&i);
	printf("\nNhap vi tri phan tu thu 2:"); scanf("%d",&j);
	float sub;
	sub=a.max[i]-a.max[j];
	printf("Do lech ve gia tri giua max[%d] va max[%d] la %f",i,j,sub);
}

void dolechchuan(Array a)
{
	float trungbinh=average(a);
	int i;
	float phuongsai=0;
	for(i=0;i<a.count;i++)
	{
		phuongsai=phuongsai+pow((a.max[i]-trungbinh),2);
	}
	phuongsai=phuongsai/a.count;
	printf("\nDo lech trung binh ve gia tri cua cac phan tu la:%f",sqrt(phuongsai));
}

int search(Array a)
{	
	float x;
	printf("\nNhap phan tu can tim:"); scanf("%f",&x);
	int i;
	for(i=0;i<a.count;i++)
	{
		if(a.max[i]==x)
		{
			printf("Phan tu can tim o vi tri %d",i);
			return i;
		}
	}
	return -1;
}

int binarySearch(Array a)
{
	float target;
	printf("\nNhap phan tu can tim:"); scanf("%f",&target);
	insertionSort(a);
	int first=0,last=a.count-1,mid;
	while(first<=last)
	{
		mid=(first+last)/2;
		if(a.max[mid]<target) first=mid+1;
		if(a.max[mid]>target) last=mid-1;
		if(a.max[mid]==target) 
		{
			printf("Phan tu can tim o vi tri %d",mid);
			return mid;
		}
	}
	return -1;
}

/*int main()
{
	Array a;
	a=makeArray();
	//gangiatri(a);
	//bubbleSort(a);
	//insertionSort(a);
	//selectionSort(a);
	//findMax(a);
	//findMin(a);
	//average(a);
	//sub(a);
	//dolechchuan(a);
	//search(a);
	binarySearch(a);
	getch();
} */

