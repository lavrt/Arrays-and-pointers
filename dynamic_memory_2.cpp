#include <stdio.h>
#include <stdlib.h>

#define FREE(ptr_) \
    do { free(ptr_); ptr_ = NULL; } while (0) 

int main(void)
{
    int number_of_rows = 0;

    printf("Enter how many rows will be in your array: ");
    scanf("%d", &number_of_rows);

    int ** addr = (int **)calloc(number_of_rows + 1, sizeof(int*));
    if (!addr)
    {
        fprintf(stderr, "No memory\n");
        return 0;
    }

    int * data = (int *)calloc(100, sizeof(int));
    if (!data)
    {
        fprintf(stderr, "No memory\n");
        return 0;
    } 
    int * ptr = data;
    addr[0]=data;

    for (int i = 0; i < number_of_rows; i++)
    {
        int temp = 0;
        printf("Enter the size of the %d row: ", i+1);
        scanf("%d", &temp);
        for (int j = 0; j < temp; j++)
        {
            printf("Enter the element [%d][%d]: ", i, j);
            scanf("%d", ptr+j);   
        }
        ptr += temp;
        addr[i+1] = ptr;
    }

    for (int y = 0; y < number_of_rows; y++)
    {
        for (int x = 0; x < addr[y+1]-addr[y]; x++)
        {
                printf("[%d][%d]: %-5d", y, x, data[addr[y] - data +x]);
        }
        putchar('\n');
    }
    
    FREE(addr);
    FREE(data);
    
    return 0;
}