#include <stdio.h>

int main()
{
    int a[3][3], b[3][3], mult[3][3], i, j, k;

    printf("\nEnter elements 3x3 of matrix 1:\n");
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            printf("Enter element a%d,%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }


    printf("\nEnter elements 3x3 of matrix 2:\n");
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            printf("Enter element b%d,%d: ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }


    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            mult[i][j] = 0;
        }
    }


    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            for (k = 0; k < 3; ++k)
            {
                mult[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    
    printf("\nOutput Matrix:\n");
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            printf("%d ", mult[i][j]);
        }
        printf("\n");
    }

    return 0;
}
