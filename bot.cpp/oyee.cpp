#include <stdio.h>

#define MAX 10 // Maximum size of the matrix

void inputMatrix(int matrix[MAX][MAX], int rows, int cols, char name) {
    printf("Enter elements of Matrix %c (%dx%d):\n", name, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;
    int choice;

    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);

    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    inputMatrix(A, rowsA, colsA, 'A');
    inputMatrix(B, rowsB, colsB, 'B');

    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            if (rowsA == rowsB && colsA == colsB) {
                addMatrices(A, B, C, rowsA, colsA);
                printf("Result of Addition:\n");
                printMatrix(C, rowsA, colsA);
            } else {
                printf("Addition not possible. Matrices must have the same dimensions.\n");
            }
            break;

        case 2:
            if (rowsA == rowsB && colsA == colsB) {
                subtractMatrices(A, B, C, rowsA, colsA);
                printf("Result of Subtraction:\n");
                printMatrix(C, rowsA, colsA);
            } else {
                printf("Subtraction not possible. Matrices must have the same dimensions.\n");
            }
            break;

        case 3:
            if (colsA == rowsB) {
                multiplyMatrices(A, B, C, rowsA, colsA, colsB);
                printf("Result of Multiplication:\n");
                printMatrix(C, rowsA, colsB);
            } else {
                printf("Multiplication not possible. Columns of A must equal rows of B.\n");
            }
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}