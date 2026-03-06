# include <stdio.h>

#define SIZE 5 

void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    // Loop through the row
    for (int i = 0; i < SIZE; i++) {
        // Loop through the column
        for (int j = 0; j < SIZE; j++) {
            // Add the corresponding elements of m1 and m2 and store in result
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    // Loop through the row
    for (int i = 0; i < SIZE; i++) {
        // Loop through the column
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0; // Initialize the result cell
            // Loop through the elements of the row of m1 and column of m2 to calculate the dot product
            for (int k = 0; k < SIZE; k++) {
                // Multiply the corresponding elements and add to the result
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

void TransposeMatrix(int m[SIZE][SIZE], int result[SIZE][SIZE]) {
    // Loop through the row
    for (int i = 0; i < SIZE; i++) {
        // Loop through the column
        for (int j = 0; j < SIZE; j++) {
            // Transpose the matrix by swapping the row and column indices
            result[j][i] = m[i][j];
        }
    }
}

void printMatrix(int m[SIZE][SIZE]) {
    // Loop through the row
    for (int i = 0; i < SIZE; i++) {
        // Loop through the column
        for (int j = 0; j < SIZE; j++) {
            // Print the element
            printf("%5d ", m[i][j]);
        }
        // Print a new line after each row
        printf("\n");
    }
}

int main() {
    // Matrix definitions with sample input [cite: 22-71]
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    int result[SIZE][SIZE];

    printf("Matrix 1:\n");
    printMatrix(m1);
    printf("\nMatrix 2:\n");
    printMatrix(m2);

    addMatrices(m1, m2, result);
    printf("\nResult of Matrix Addition:\n");
    printMatrix(result);

    multiplyMatrices(m1, m2, result);
    printf("\nResult of Matrix Multiplication:\n");
    printMatrix(result);

    TransposeMatrix(m1, result);
    printf("\nTranspose of Matrix 1:\n");
    printMatrix(result);

    return 0;
}