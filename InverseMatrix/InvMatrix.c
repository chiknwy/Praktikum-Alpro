#include <stdio.h>

// Invers Matrix Functions
void inverseMatrix(float matrix[3][3], float inverse[3][3]) {
    float determinant = 0;

    // Determinan matrix
    for (int i = 0; i < 3; i++)
        determinant += (matrix[0][i] * (matrix[1][(i + 1) % 3] * matrix[2][(i + 2) % 3] - matrix[1][(i + 2) % 3] * matrix[2][(i + 1) % 3]));

    //  Adjoin Matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            inverse[j][i] = ((matrix[(i + 1) % 3][(j + 1) % 3] * matrix[(i + 2) % 3][(j + 2) % 3]) -
                             (matrix[(i + 1) % 3][(j + 2) % 3] * matrix[(i + 2) % 3][(j + 1) % 3])) / determinant;
        }
    }
}

// Function Display the Matrix
void printMatrix(float matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}


// Main function
int main() {
    float matrix[3][3];
    float inverse[3][3];

    // Get Input from user
    printf("Masukkan elemen matriks 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("[%i][%i]: ",i+1,j+1);
            scanf("%f", &matrix[i][j]);
        }
    }

    // Use the Matriks Invers Function
    inverseMatrix(matrix, inverse);

    // Display Result Invers Matrix
    printf("\nMatriks invers:\n");
    printMatrix(inverse);

    return 0;
}