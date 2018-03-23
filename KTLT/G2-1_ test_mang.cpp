#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
int main()
{
	int n,count;
	int MAX[100];
	char name[40],flag;
	FILE *fp;
	  tt: printf("chon file nhap day MAX: ");
	fflush(stdin);
       scanf("%s",name);
	   if((fp=fopen(name,"r"))==NULL)
	 {
		printf("khong mo duoc file ban co muon nhap lai (C/K)\n");
		fflush(stdin);
		scanf("%c",flag);
		if(toupper(flag)=='C')
		{
			goto tt;
	    }
	 }
	  else
	 {
		fscanf(fp,"%d",&count);
		for(int i=0;i<count;i++)
		{
			fscanf(fp,"%d",&MAX[i]);
		}
		for(int i=0;i<count;i++)
		{
			printf("\t%d",MAX[i]);
		}
		printf("\n1. khoi tao mot phien ban moi cua chinh no"
		"\n2. Gan gia tri cho cac thanh phan thong tin cua mot ADT Array"
		"\n3. sap xep cac phan tu cua mang theo giai thuat bubble sort"
		"\n4. sap xep cac phan tu cua mang theo giai thuat insertion sort"
		"\n5. sap xep cac phan tu cua mang theo giai thuat selection sort"
		"\n6. Tim gia tri lon nhat duoc luu tru trong mang va vi tri cua cac phan tu co gia tri lon nhat trong mang"
		"\n7. Tim gia tri nho nhat duoc luu tru trong mang va vi tri cua cac phan tu co gia tri nho nhat trong mang"
		"\n8. Tim gia tri trung binh cua cac phan tu trong mang"
		"\n9. Tim do lech ve gia tri giua 2 phan tu co vi tri biet truoc trong mang"
		"\n10. Tim do lech ve gia tri trung binh cua cac phan tu trong mang"
		"\n11. Tim kiem (theo giai thuat sequential seach) phan tu cua mang co gia tri x,neu tim thay thi dua ra , neu khong tim thay tra ve 0"
		"\n12. Tim kiem (theo giai thuat binary search) phan tu cua mang co gia tri x,neu tim thay thi dua ra , neu khong tim thay thi thong bao khong tim thay"
		"\n13. Bieu dien do phuc tap theo ki phap big O va hien thi thoi gian tinh toan thuc te bang micro-second"
		"\n14. thoat khoi chuong trinh"
		);
		ts: printf("\nnhap so bieu thi chuc nang ban muon: ");
		scanf("%d",&n);
		switch (n)
		{
		  case 2:{
		     printf("--nhap lai thong tin tu file: ");
		     scanf("%s",name);
		     if((fp=fopen(name,"r"))==NULL)
		     printf("khong mo duoc du lieu");
		     else{
		     	fscanf(fp,"%d",&count);
		     	for(int j=0;j<count;j++)
		        {
		        	fscanf(fp,"%d",&MAX[j]);
		        }
		        goto ts;
		     }
			 break;
		  	
		  }
		  case 1:	
	      {
	      	 goto tt;
	         break;	
	      }
	      case 3:
	      {
	      	int temp;
	      	for(int j=0;j<count;j++)
	      	for(int i=0;i<count;i++)
	      	{
	      		if(MAX[i]>MAX[j])
	      		{
	      			temp=MAX[j];
	      			MAX[j]=MAX[i];
	      			MAX[i]=temp;
	      		}
	      	}
	      	printf("\n--sau khi thuc hien giai thuat bubble sort:");
	      	for(int i=0;i<count;i++)
	      	{
	      		printf("\t%d",MAX[i]);
	      	}
	      	goto ts;
	         break; 		
	      }
	      case 4:
	      	{
	      		int temp,j;
	      		for(int i=1;i<count;i++)
	      		{
	      			temp=MAX[i];
	      			j=i-1;
	      			while((j>=0)&&(MAX[j]>temp))
	      			{
	      				MAX[j+1]=MAX[j];
	      				j--;
	      			}
	      			MAX[j+1]=temp;
	      		}
	      		 printf("\n--Sau khi thuc hien giai thuat insertion sort: ");
	      	     for(int i=0;i<count;i++)
	      	     {
	      		     printf("\t%d",MAX[i]);
	      	     }
	      	     goto ts;
	              break; 	
	      		
	      	}
	        case 6:
			{
				int max=MAX[0],j=0;
				for(int i=1;i<count;i++)
				{
					if(max<MAX[i])
					{
						max=MAX[i];
						j=i;
					}
				}
				printf("\nphan tu MAX[%d] lon nhat la: %d",j+1,max);
				goto ts;
				break;
			}	
			case 5:
				{
					for(int i=0;i<count;i++)
					{
						int min=MAX[i],temp;
						for(int j=i+1;j<count;j++)
						{
							if(min>MAX[j])
							{
							    min=MAX[j];
							    temp=j;
							}
						}
						MAX[temp]=MAX[i];
						MAX[i]=min;
					}
					printf("\n--Sau khi thuc hien giai thuat selection sort: ");
	      	        for(int i=0;i<count;i++)
	      	        {
	      		         printf("\t%d",MAX[i]);
	      	        }
					goto ts;
					break;
				}
				case 7:
					{
						int min=MAX[0],j=0;
				        for(int i=1;i<count;i++)
				         {
					           if(min>MAX[i])
					       {
						        min=MAX[i];
						        j=i;
					       }
				         }
				        printf("\nphan tu MAX[%d] lon nhat la: %d",j+1,min);
						goto ts;
						break;
					}
				case 8:
				   {
				   	    int s=0;
				   	    for(int i=0;i<count;i++)
				   	    {
				   	    	s+=MAX[i];
				   	    }
				   	    printf("\ngia tri trung binh cua cac phan tu trong mang: %d",s/count);
				   }
				case 9:
				   {
				   	    int m,n;
				   	    printf("\nnhap 2 phan tu trong mang: "); scanf("%d%d",&m,&n);
				   	    if((m<count)&&(n<count))
				   	    {
                              int c=abs(MAX[m]-MAX[n]); 				   	    
				   	          printf("\n do lech ve gia tri phan tu thu %d va %d la: %d",m,n,c);
				   	    }
				   	    else
				   	    {
				   	    	printf("ban da nhap vuot qua so phan tu!");
				   	    }
				   	    goto ts;
				   	    break;
				   }
				case 10:
				   {
				   	    int s=0,j,array[count];
				   	    for(int i=0;i<(count-1);i++)
				   	    {
				   	    	 array[j]= abs(MAX[i]-MAX[i+1]);
				   	    	 j++;
				   	    }
				   	    for(int i=0;i<(j-1);i++)
				   	    {
				   	    	s=s+array[i];
				   	    }
				   	    printf("\n--Do lech trung binh ve gia tri cua cac phan tu trong mang: %d",(s/(j-1)));
				   	    goto ts;
				   	    break;
				   }
				case 11:
				   {
				   	    int s,array[100],j=0;
				   	    printf("\n nhap gia tri can tim: "); scanf("%d",&s);
				   	    for(int i=0;i<n;i++)
				   	    {
				   	    	if(s==MAX[i])
				   	    	{
				   	    		array[j]=i;
				   	    		j++;
				   	    	}
				   	    }
				   	    printf("\nvi tri co gia tri %d la: ",s);
				   	    if(j>0)
				   	    {
				   	    	 for(int i=0;i<j;i++)
				   	    	 {
				   	    		    printf("%3d",array[i]);
				   	    	 }
				   	    }
				   	    else
				   	    printf("0");
				   	    goto ts;
				   	    break;
				   }	
			    case 14:
			       {
					    break;
			       }
		}
		
		
	 }
	fclose(fp);
}
