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

#include "ft_printf.h"

static void	ft_hexlen(unsigned int input_number,int *counter)
{
	while (input_number != 0)
	{
		input_number = input_number / 16;
		(*counter)++;
	}
}

static void	ft_print_hexadecimal(unsigned int input_number, const char format)
{
	if (input_number >= 16)
	{
		ft_print_hexadecimal(input_number / 16, format);
		ft_print_hexadecimal(input_number % 16, format);
	}
	else
	{
		if (input_number <= 9)
			ft_putchar_fd((input_number + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((input_number - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((input_number - 10 + 'A'), 1);
		}
	}
}

void	ft_puthexadecimal(unsigned int input_number,
				const char format, int *counter)
{
	if (input_number == 0)
		(*counter) += write(1, "0", 1);
	else
		ft_print_hexadecimal(input_number, format);
	ft_hexlen(input_number, counter);
}