/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ax <ax@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:50:28 by ax                #+#    #+#             */
/*   Updated: 2024/01/07 20:24:33 by ax               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_putstr(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}


int ft_printf(const char *str, ...) 
{
	va_list	args;
	int		i;
	int		count;
	char	*current;

	va_start(args, str);
	i = 0;
	while(str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 's')
			{
				current = va_arg(args, char *);
				count += ft_putstr(current);
				i += 2;
			}
		}
		ft_putchar(str[i]);
		i++;
		count++;
	}

	va_end(args);
	return (count);
}

int main(void)
{
	ft_printf("Hello %s %s World \n", "ABC", "DEF", 'C');
	// printf("Hello World\n");
	// printf("Len: %zu\n", ft_strlen("Hello World!!!"));
	// printf("Sum function: %d\n", sum(4, 1, 2, 3, 4));
	return (0);
}

int sum(int count, ...)
{
	va_list args;
	va_start(args, count);
	int i;
	int s = 0;
	for (i = 0; i < count; i++)
	{
		int x = va_arg(args, int);
		printf("I: %d, Count: %d, X: %d\n", i, count, x);
		s += x;
	}
	va_end(args);
	return (s);
}
