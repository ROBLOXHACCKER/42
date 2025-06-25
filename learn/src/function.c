#include "../include/header.h"

void reverse_count(int n)
{
    if(n <= 0)
        return;
    printf("> %d\n", n);
    reverse_count(n-1);
}


int sum_array(int *n, int size)
{
    if(size<=0)
        return(0);

    return (n[size-1] + sum_array(n, size-1)); 
}

int count_even_numbers(int *n, int size)
{
    if (size <= 0)
        return 0;

    int is_even = 0;
    if (n[size - 1] % 2 == 0)
        is_even = 1;

    return is_even + count_even_numbers(n, size - 1);
}

int fattoriale(int n)
{

    if(n == 1)
        return (1);
    
    int fatt = fatt * fattoriale(n-1);
    if(n == 0)
    {
        return fatt;
    }else
    {
        return n-1;
    }

}