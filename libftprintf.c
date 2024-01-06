/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ax <ax@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:50:28 by ax                #+#    #+#             */
/*   Updated: 2024/01/06 21:09:38 by ax               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

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

int	ft_printf(const char *str, ...)
{
	va_list args;
	va_start(args, str);
	int	i;

	printf("%s\n", str);
	printf("COMPARE STRINGS: %s\n", ft_strnstr(str, "%d", 8));

	i = 0;
	while (i < 2)
	{
		int x = va_arg(args, int);
		printf("I: %d, X: %d\n", i, x);
		i++;
	}
	va_end(args);
	printf("String: %s\n", str);
	printf("Sum function: %d\n", sum(4, 1, 2, 3, 4));
	return (42);
}

int	main(void)
{
	ft_printf("Hello %d World", 88, 42);
	printf("Hello World\n");
	printf("Len: %zu\n", ft_strlen("Hello World!!!"));
	return (0);
}