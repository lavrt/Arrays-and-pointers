#include <stdio.h>
#include <assert.h>

#include "2array.cpp"

void res_matrix_multiplication(int * A,   int Ay,   int Ax,
                               int * B,   int By,   int Bx,
                               int * C);

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
/*
void res_matrix_multiplication(int * matrix_1,   int matrix_1_y,   int matrix_1_x,
                               int * matrix_2,   int matrix_2_y,   int matrix_2_x,
                               int * matrix_res, int matrix_res_y, int matrix_res_x)
{
    assert(matrix_1 != NULL);
    assert(matrix_2 != NULL);
    assert(matrix_1_x == matrix_2_y);
    assert(matrix_res_y == matrix_1_y);
    assert(matrix_res_x == matrix_2_x);

    int internal_size = matrix_1_x;

    for (int row_matrix_res = 0; row_matrix_res < matrix_res_y; ++row_matrix_res)
    {
        for (int column_matrix_res = 0; column_matrix_res < matrix_res_x; ++column_matrix_res)
        { // *(matrix_res + matrix_res_x * row_matrix_res + column_matrix_res) = 
            int * value_matrix_res = (matrix_res + matrix_res_x * row_matrix_res + column_matrix_res);

            for (int index = 0; index < internal_size; ++index)
            {
                int value_matrix_1 = matrix_1[matrix_1_x * row_matrix_res + index];
                int value_matrix_2 = matrix_2[matrix_2_x + column_matrix_res * index];
                
                *value_matrix_res += value_matrix_1 * value_matrix_2;
            }
        }
    }
}
*/
void res_matrix_multiplication(int * A, int Ay, int Ax,
                               int * B, int By, int Bx,
                               int * C)
{ 
    assert(A != NULL);
    assert(B != NULL);
    assert(Ax == By);
   
   for (int i = 0; i < Ay; i++)
   {
        for (int j = 0; j < Bx; j++)
        {
            int sum = 0;
            for (int k = 0; k < Ax; k++)
            {
               sum += A[k+i*Ax] * B[k*Bx+j];
            }
            C[i*Bx+j] = sum;
        }
    }
}