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

#include "../libft_printf.h"


void	ft_putchar_pf(char c, int *counter)
{
	(*counter) += write(1, &c, 1);
}

void ft_putstr_pf(const char *str, int *counter)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar_pf(str[i], counter);
		i++;
	}
}

void ft_putnbr_pf(int num, int *counter)
{
	int 	i;
	char	*num_str;

	num_str = ft_itoa(num);
	i = 0;
	while (num_str[i])
	{
		ft_putchar_pf(num_str[i], counter);
		i++;
	}
	free(num_str);
}