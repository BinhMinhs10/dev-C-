#include <stdio.h>

void max_day(FILE *fpout, int tongsp[], int n)
{
	int i;
	int max = tongsp[0], index_max;

	for(i=1; i<=n; i++){
		if(max < tongsp[i]){
		max = tongsp[i];
		index_max = i;
		}
	}
	fprintf(fpout, "%d - %d\n",index_max, max);

	for(i=1; i<=n; i++){
		if(tongsp[i] == 0){
			fprintf(fpout,"%d - %d\n", i, tongsp[i]);
		}
	}

}

int tong_i_j(int tongsp[], int i, int j)
{
	int a, tong = 0;

	for(a = i; a <= j; a++){
		tong += tongsp[a];
	}

	return tong;
}

void check(FILE *fout,int tongsp[],int n)
{
	for(int i=1; i<=n; i++){

		int count = 0, flag = -1;

		if(tongsp[i] == 0){
			int start = i, end;
			flag = 1;

			for(int j = i; j<=n; j++){
				if(tongsp[j]==0 && flag == 1){
					end = j;
					flag = 1;
					count++;
				} else{
					break;
				}
			}

			i += count;
			fprintf(fout, "%d - %d\n", start, end);
		}
	}
}
int main()
{
	FILE *fp = fopen("C:\\Users\\ThuyLinh Computer\\Documents\\dev-C++\\input.txt", "r");
	FILE *fout = fopen("C:\\Users\\ThuyLinh Computer\\Documents\\dev-C++\\output.txt", "w");

	if(fout == NULL){
		printf("MEMORY ERROR!\n");
	} else if(fp == NULL){
		printf("Cannot open file input.txt!\n");
	} else {
		int n,i, sosanpham, songay, ngayi, ngayj;
		int tongsp[30] = {}, ngay[30];
		fscanf(fp,"%d",&n);

		fprintf(fout,"PHAN 1\n");

		for(i=1; i<=n; i++){
			fscanf(fp,"%d %d",&ngay[i],&sosanpham);
			tongsp[ngay[i]] += sosanpham;
		}

		songay = ngay[n];
		fscanf(fp,"%d %d", &ngayi, &ngayj);

		for(i=1; i<=songay; i++){
			fprintf(fout,"%d - %d\n",i, tongsp[i]);
		}

		fprintf(fout, "PHAN 2\n");
		max_day(fout,tongsp,songay);
		
		fprintf(fout, "PHAN 3\n");
		fprintf(fout, "%d\n",tong_i_j(tongsp, ngayi, ngayj));
		
		fprintf(fout, "PHAN 4\n");
		check(fout,tongsp,songay);
		
		fclose(fp);
		fclose(fout);
	}
	return 0;
}
