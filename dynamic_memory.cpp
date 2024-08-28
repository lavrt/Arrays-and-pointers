#include <stdio.h>
#include <stdlib.h>

#define FREE(ptr_) \
    do { free(ptr_); ptr_ = NULL; } while (0) 

int main(void)
{
    int number_of_rows = 0;
    int sum = 0;

    printf("Enter how many rows will be in your array: ");
    scanf("%d", &number_of_rows);

    int * addr = (int *)calloc(number_of_rows + 1, sizeof(int));
    if (!addr)
    {
        fprintf(stderr, "No memory\n");
        return 0;
    } 

    for (int i = 1; i < number_of_rows + 1; i++)
    {
        printf("Enter the size of the %d row: ", i);
        scanf("%d", &addr[i]);
        sum += addr[i];
        addr[i] = sum;
    }

    int * data = (int *)calloc(sum, sizeof(int));
    if (!data)
    {
        fprintf(stderr, "No memory\n");
        return 0;
    } 
    
    for (int y = 1; y < number_of_rows + 1; y++)
    {
        for (int x = 0; x < addr[y] - addr[y-1]; x++)
        {
            printf("Enter the element [%d][%d]: ", y-1, x);
            scanf("%d", &data[(addr[y-1]+x)]);
        }
    }
    
    for (int y = 1; y < number_of_rows + 1; y++)
    {
        for (int x = 0; x < addr[y] - addr[y-1]; x++)
        {
            printf("[%d][%d]: %-5d", y-1, x, data[(addr[y-1]+x)]);
        }
        putchar('\n');
    }
    
    FREE(addr);
    FREE(data);
    
    return 0;
}