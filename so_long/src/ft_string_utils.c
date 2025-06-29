#include "../include/utils.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

char	*ft_strdup(const char *s)
{
	char	*dup;
	int	len;
	int	i;

	len = 0;
	while (s[len])
		len++;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

static void	ft_putstr(const char *s)
{
	while (*s)
		write(1, s++, 1);
}

static void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 's')
				ft_putstr(va_arg(args, char *));
			else if (format[i] == 'd')
				ft_putnbr(va_arg(args, int));
			else
				write(1, &format[i], 1);
		}
		else
			write(1, &format[i], 1);
		count++;
		i++;
	}
	va_end(args);
	return (count);
} 