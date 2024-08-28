#include <stdio.h>
#include <assert.h>

#include "2array.cpp"

void res_matrix_multiplication(int * matrix_1,   int matrix_1_y,   int matrix_1_x,
                               int * matrix_2,   int matrix_2_y,   int matrix_2_x,
                               int * matrix_res);

int main(void)
{
    int matrix_1[3][3] = 
    {
        {1, 0, 2},
        {-1, 3, 0},
        {2, 1, 3},
    };

    int matrix_2[3][3] = 
    {
        {3, -1, 2},
        {-4, 0, 2},
        {1, 1, 2},
    };

    int matrix_res[3][3] = {};

    res_matrix_multiplication((int *)matrix_1, 3, 3,
                              (int *)matrix_2, 3, 3,
                              (int *)matrix_res);

    print_matrix((int *)matrix_res, 3, 3);

    int matrix_3[2][3] = 
    {
        {1, 2, 3},
        {4, 5, 6},
    };

    int matrix_4[3][2] = 
    {
        {1, 2},
        {3, 4},
        {5, 6},
    };

    int matrix_res2[2][2] = {};

    res_matrix_multiplication((int *)matrix_3, 2, 3,
                              (int *)matrix_4, 3, 2,
                              (int *)matrix_res2);

    print_matrix((int *)matrix_res2, 2, 2);    

    return 0;
}

void res_matrix_multiplication(int * matrix_1,   int matrix_1_y,   int matrix_1_x,
                               int * matrix_2,   int matrix_2_y,   int matrix_2_x,
                               int * matrix_res)
{ 
    assert(matrix_1 != NULL);
    assert(matrix_2 != NULL);
    assert(matrix_1_x == matrix_2_y);
   
   for (int slow_cycle = 0; slow_cycle < matrix_1_y; slow_cycle++)
   {
        for (int average_cycle = 0; average_cycle < matrix_2_x; average_cycle++)
        {
            int sum = 0;
            for (int fast_cycle = 0; fast_cycle < matrix_1_x; fast_cycle++)
            {
               sum += matrix_1[fast_cycle+ slow_cycle * matrix_1_x] * matrix_2[fast_cycle * matrix_2_x + average_cycle];
            }
            matrix_res[slow_cycle * matrix_2_x + average_cycle] = sum;
        }
    }
}