#include<stdio.h>

//viet mot ham de tim cac phan tu cua ma tran nghich dao
//                   a         3        i          i
void reduction(float a[][100], int size, int pivot, int col) {
   int i, j;
   float factor;
   factor = a[pivot][col];

   for (i = 0; i < 2 * size; i++) {
      a[pivot][i] /= factor;
   }

   for (i = 0; i < size; i++) {
      if (i != pivot) {
         factor = a[i][col];
         for (j = 0; j < 2 * size; j++) {
            a[i][j] = a[i][j] - a[pivot][j] * factor;
         }
      }
   }
}

int main() {
   float matrix[100][100];
   int i, j,n;
   printf("\nnhap n: "); scanf("%d",&n);
   for (i = 0; i < n; i++) {
      for (j = 0; j < 2*n; j++) {
         if (j == i + n) {
            matrix[i][j] = 1;
         } else {
            matrix[i][j] = 0;
         }
      }
   }

   printf("\nNhap ma tran co kich co n X n:\n");
   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         scanf("%f", &matrix[i][j]);
      }
   }

   for (i = 0; i < n; i++) {
      reduction(matrix, n, i, i);
   }

   printf("\nMa tran nghich dao cua ma tran da cho la:\n");
   for (i = 0; i < n; i++) {
      printf("\n");
      for (j = 0; j < n; j++) {
         printf("%8.3f", matrix[i][j + n]);
      }
   }
   return(0);
}
