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

int	check_if_double(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = 1;
		while (base[i + j])
		{
			if (base[i] == base[i + j])
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_print_nbr(int n, int base_value, char *symbols, int *counter)
{
	long	nl;

	nl = n;
	if (nl < 0)
	{
		nl = -nl;
		ft_putchar_pf('-', counter);
	}
	if (nl >= base_value)
	{
		ft_print_nbr(nl / base_value, base_value, symbols, counter);
	}
	ft_putchar_pf(symbols[nl % base_value], counter);
}

void	ft_putnbr_base(int nbr, char *base, int *counter)
{
	int	base_value;

	base_value = 0;
	while (base[base_value])
	{	
		if (base[base_value] == '-' || base[base_value] == '+')
		{
			return ;
		}
		base_value++;
	}
	if (base_value < 2)
		return ;
	if (check_if_double(base))
		return ;
	ft_print_nbr(nbr, base_value, base, counter);
}
