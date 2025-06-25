#include "../utils.h"

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

int just_numbers(char *str)
{
    if (!str || *str == '\0')
        return 0;
    while (*str)
    {
        while (*str == ' ')
            str++;
        if (*str == '\0')
            break;
        if (*str == '-' || *str == '+')
            str++;
        if (!is_digit(*str))
            return 0;
        while (is_digit(*str))
            str++;
        if (*str != ' ' && *str != '\0')
            return 0;
    }
    return 1;
}

int is_valid_number(char *str)
{
    if (!str || *str == '\0')
            return 0;
    if (*str == '-' || *str == '+')
        str++;
    if (!is_digit(*str))
        return 0;
    while (is_digit(*str))
        str++;
    return (*str == '\0');
}















