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

static int	ft_putarg(va_list args, char identifier, int *counter)
{
	if (identifier == 'c')
		ft_putchar_pf(va_arg(args, int), counter);
	else if (identifier == 's')
		ft_putstr_pf(va_arg(args, char *), counter);
	else if (identifier == 'i' || identifier == 'd')
		ft_putnbr_pf(va_arg(args, int), counter);
	else if (identifier == '%')
		ft_putchar_pf('%', counter);
	return (0);
}

static int	ft_putformat(va_list args, const char *format)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while(format[i])
	{
		if (format[i] == '%')
			ft_putarg(args, format[++i], &counter);
		else 
			ft_putchar_pf(format[i], &counter);
		i++;
	}
	return (counter);
}


int ft_printf(const char *format, ...) 
{
	va_list	args;

	int		count;

	va_start(args, format);
	count = ft_putformat(args, format);
	va_end(args);
	return (count);
}

int main(void)
{
	// ft_printf("Hello %s %s %d %% World \n", "ABC", "DEF", 42);
	printf("COUNT M: %d\n\n", ft_printf("Hello %s %s %c %d %% World \n", "ABC", "DEF", 'X', 42));
	printf("COUNT O: %d\n", printf("Hello %s %s %c %d %% World \n", "ABC", "DEF", 'X', 42));
	return (0);
}