/*Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is
 equal to element at position [j][i] for all valid i and j).*/

#include <stdio.h>

int main() {
    int m, n;

    // Read number of rows and columns
    scanf("%d %d", &m, &n);

    // If not square, it cannot be symmetric
    if (m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    int matrix[m][n];

    // Read matrix elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check symmetry
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                printf("Not a Symmetric Matrix");
                return 0;
            }
        }
    }

    printf("Symmetric Matrix");
    return 0;
}
