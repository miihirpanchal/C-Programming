#include <stdio.h>
int main()
{
    int ARows, AColumns, BRows, BColumns;
    int sum;
start:
    printf("Enter The Number of Rows in your Matrix A.\n");
    scanf("%d", &ARows);
    printf("Enter The Number Of Columns In Your Matrix A.\n");
    scanf("%d", &AColumns);

    printf("Enter The Number of Rows in your Matrix B.\n");
    scanf("%d", &BRows);
    printf("Enter The Number Of Columns In Your Matrix B.\n");
    scanf("%d", &BColumns);

    if (AColumns == BRows)
    {
        printf("The Multiplication of These Matrices is possible.\n");
        printf("Result Matrix Will be a %d * %d Matrix\n", ARows, BColumns);
    }
    else
    {
        printf("The Multiplication Of These Matrices Isn't Possible.\n Try with Different Matrices.\n");
        goto start;
    }
    int matrixA[ARows][AColumns];
    int matrixB[BRows][BColumns];
    int Result[ARows][BColumns];

    for (int i = 0; i < ARows; i++)
    {
        for (int j = 0; j < AColumns; j++)
        {
            printf("Give The Number for row %d & column %d in matrix A.\n", i + 1, j + 1);
            scanf("%d", &matrixA[i][j]);
        }
    }
    printf("MATRIX A  \n");
    for (int i = 0; i < ARows; i++)
    {
        for (int j = 0; j < AColumns; j++)
        {
            printf("%d ", matrixA[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < BRows; i++)
    {
        for (int j = 0; j < BColumns; j++)
        {
            printf("Give The Number for row %d & column %d in matrix B.\n", i + 1, j + 1);
            scanf("%d", &matrixB[i][j]);
        }
    }
    printf("MATRIX B  \n");
    for (int i = 0; i < BRows; i++)
    {
        for (int j = 0; j < BColumns; j++)
        {
            printf("%d ", matrixB[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < ARows; i++)
    {
        for (int j = 0; j < BColumns; j++)
        {
            sum = 0;
            for (int k = 0; k < AColumns; k++)
            {
                sum += matrixA[i][k] * matrixB[k][j];
            }
            Result[i][j] = sum;
        }
    }
    printf("THE RESULT OF MATRIX A * MATRIX B IS\n");

    for (int i = 0; i < ARows; i++)
    {
        for (int j = 0; j < BColumns; j++)
        {
            printf("%d ", Result[i][j]);
        }
        printf("\n");
    }

    return 0;
}