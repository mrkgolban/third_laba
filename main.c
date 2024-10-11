#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

bool seddle(int* a, int row, int column, int* seddle, int* maximum, int* minimum)
{
    int x;
    for (int i = 0; i < row * column; i++)
    {
        scanf("%d", &x);
        a[i] = x;
        *maximum = x > *maximum ? x : *maximum;
        *minimum = x < *minimum ? x : *minimum;
    }
    int deltax1, deltax2, deltay1, deltay2, elem;
    for (int i = 1; i < row - 1; i++)
    {
        for (int j = 1; j < column - 1; j++)
        {
            elem = a[i * row + j];
            deltax1 = a[i * row + j + 1] - elem;
            deltax2 = a[i * row + j - 1] - elem;
            deltay1 = a[row * (i - 1) + j] - elem;
            deltay2 = a[row * (i + 1) + j] - elem;
            if ((deltax1 > 0 && deltax2 > 0 && deltay1 < 0 && deltay2 < 0) || (deltax1 < 0 && deltax2 < 0 && deltay1 > 0 && deltay2 > 0))
            {
                *seddle = elem;
                return true;
            }
        }
    }


    return false;


}

int main()
{
    int m = 3;
    int n = 3;
    int* max = (int* )malloc(4);
    int* min = (int* )malloc(4);
    *max = -pow(10, 9);
    *min = pow(10, 9);
    int matrix[m * n];
    int* seddle_point = (int*)malloc(sizeof(int));
    if (seddle(matrix, m, n, seddle_point, max, min))
    {
        printf("The seddle point is: %d\n", *seddle_point);    
    }
    else
    {
        printf("No seddle point found :(\n");
    }
    printf("The maximum in array is: %d\n", *max);
    printf("The minimum in array is: %d\n", *min);

}

/*
With seddle point
0 9 16 21 24 25 24 21 16 9 

-9 0 7 12 15 16 15 12 7 0 

-16 -7 0 5 8 9 8 5 0 -7 

-21 -12 -5 0 3 4 3 0 -5 -12 

-24 -15 -8 -3 0 1 0 -3 -8 -15 

-25 -16 -9 -4 -1 0 -1 -4 -9 -16 

-24 -15 -8 -3 0 1 0 -3 -8 -15 

-21 -12 -5 0 3 4 3 0 -5 -12 

-16 -7 0 5 8 9 8 5 0 -7 

-9 0 7 12 15 16 15 12 7 0 

Without seddle point

1 2 3  
4 5 6
7 8 9

*/