#include <stdio.h>

int const kCountOfGames = 10;

void print_triangular_array(int * number_of_goals, size_t size_x_max);

int main(void)
{
    int number_of_goals[kCountOfGames] =
    {
        2,
        1, 3,
        3, 2, 2,
        1, 0, 5, 2,
    };
    print_triangular_array(number_of_goals, 4);

    return 0;
}

void print_triangular_array(int * number_of_goals, size_t size_x_max)
{
    int count = 0;
    for (int i = 0; i < size_x_max; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", *(number_of_goals + count));
            count++;
        } 
        putchar('\n');
    }
}

