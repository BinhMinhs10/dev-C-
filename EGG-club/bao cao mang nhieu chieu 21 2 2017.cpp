#include <stdio.h>
 
void readFile(FILE *fp, int matrix[10][10], int m, int n)
{
    int i, j;
    for(i=0; i < m; i++) {
        for(j = 0; j < n; j++) {
            fscanf(fp,"%d",&matrix[i][j]);
        }
    }
}
 
void printMatrix(int matrix[10][10], int row, int column)
{
    int i,j;
 
    for(i = 0; i < row; i++) {
        for(j = 0; j < column; j++) {
            printf("| %2d |", matrix[i][j]);
        }
        printf("\n");
    }
}
 
void SquareSum( int matrix[10][10], int k, int row, int column)
{
    int i, j, m, n, a = 0;
    int Sum[10][10] = {};
    int max = 0;
 
    for(i = 0; i <= row-k; i++) {
        for(j = 0; j <= column-k; j++) {
            max += matrix[i][j];
        }
    }
 
    for(i = 0; i <= row-k; i++) {
        for(j = 0; j <= column-k; j++) {
 
            for(m = i; m < k + i; m++) {
                for(n = j; n < k + j; n++) {
 
                    Sum[i][j] += matrix[m][n];
 
                }
                if(max < Sum[i][j]) {
                    max = Sum[i][j];
                }
            }
        }
    }
 
    printf("Max Sum: %d\n",max);
 
}
 
int main()
{
    int matrix[10][10];
    FILE *fp = fopen("input.txt", "r");
 
    if(fp == NULL) {
        printf("Cannot open this file!\n");
    } else {
 
        int row, column, k;
        printf("row = ");
        scanf("%d", &row);
        printf("column = ");
        scanf("%d", &column);
 
        readFile(fp, matrix, row, column);
        printf("Print the matrix: \n");
        printMatrix(matrix, row, column);
 
        printf("Max Sum with k*k square: \n");
        printf("k = ");
        scanf("%d", &k);
 
        SquareSum(matrix, k, row, column);
    }
    return 0;
}
