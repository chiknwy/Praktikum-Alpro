#include "stdio.h"

int main()
{
  // Declare matrices and result matrix
  int matrix1[2][3];
  int matrix2[3][2];
  int result_matrix[2][2] = {{0, 0}, {0, 0}};

  printf("Masukan Matrix Pertama : \n");

  // Input values for matrix1
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("Element [%d][%d] : ", i+1, j+1);
      scanf("%d", &matrix1[i][j]);
    }
  }

  printf("Masukan Matrix Kedua : \n");

  // Input values for matrix2
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      printf("Element [%d][%d] : ", i+1, j+1);
      scanf("%d", &matrix2[i][j]);
    }
  }

  // Perform matrix multiplication
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        result_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }

  // Print the result matrix
  printf("Matrix Result \n");
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      printf("%d ", result_matrix[i][j]);
    }
    printf("\n");
  }
}
