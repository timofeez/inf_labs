#include <stdio.h>

#define MAX_SIZE 8

void multiplyUpperByMaxLower(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int maxLower = -10000;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (matrix[i][j] > maxLower) {
                maxLower = matrix[i][j];
            }
        }
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            matrix[i][j] *= maxLower;
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int size;

    printf("Введите размер матрицы (2 <= N <= 8): ");
    scanf("%d", &size);

    int matrix[MAX_SIZE][MAX_SIZE];

    printf("Введите элементы матрицы %d x %d:\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    multiplyUpperByMaxLower(matrix, size);

    printf("Результат:\n");
    printMatrix(matrix, size);

    return 0;
}
