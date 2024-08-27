#include <stdio.h>
#include <assert.h>

void print_matrix(int * data, size_t size_x, size_t size_y);
void sum_matrix(int * matrix_res, int * matrix_1, int * matrix_2, size_t size_x, size_t size_y);
/*
int main(void)
{
    int data1[1][1] = 
    {
        {1},
    };
    print_matrix((int *)data1, 1, 1);

    int data4[2][2] = 
    {
        {1, 2},
        {3, 4},
    };
    print_matrix((int *)data4, 2, 2); 

    int data9[3][3] = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    print_matrix((int *)data9, 3, 3);

    int data[3][3] = 
    {
        {11, 12, 13},
        {14, 15, 16},
        {17, 18, 19},
    };
    print_matrix((int *)data, 3, 3);

    int matrix_sum[3][3] = {};
    sum_matrix((int *)matrix_sum, (int *)data, (int *)data9, 3, 3);
    print_matrix((int *)matrix_sum, 3, 3);

    return 0;
}
*/
void print_matrix(int * data, size_t size_x, size_t size_y)
{
    for (size_t row = 0; row < size_y; row++)
    {
        for (size_t column = 0; column < size_x; column++)
        {
            assert(0 <= column && column < size_x);
            assert(0 <= row    &&    row < size_y);
            
            printf("data[%ld][%ld] = %d     ", row, column, *(int *)((size_t)data
                                                                     + (row * size_x + column) * sizeof(int)));
        }                                          // or    *(data + row * size_x + column)
        putchar('\n');                            
    }
    putchar('\n');
}

void sum_matrix(int * matrix_res, int * matrix_1, int * matrix_2, size_t size_x, size_t size_y)
{
    for (size_t row = 0; row < size_y; row++) 
    {
        for (size_t column = 0; column < size_x; column++)
        {
            assert(0 <= column && column < size_x);
            assert(0 <= row    &&    row < size_y);
            
            *((int *)matrix_res + size_x * row + column) = *((int *)matrix_1 + size_x * row + column)
                                                         + *((int *)matrix_2 + size_x * row + column);
        }
    }
}