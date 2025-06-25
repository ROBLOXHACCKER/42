
#include "../include/header.h"


int main(void)
{
    int n[] = {1,2,3,4,5};
    int size  = sizeof(n) / sizeof(n[0]);

    int count_even = count_even_numbers(n, size);
    
    printf("somma = %d", count_even);
    
    return (0);
}