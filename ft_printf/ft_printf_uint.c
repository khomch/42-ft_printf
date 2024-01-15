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

static int	ft_intlen(long num)
{
	int		len;

	len = 0;
	if (num == 0)
		len = 1;
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

static void	ft_num_to_str(char *res, int is_negative, long num, int len)
{
	int	i;

	i = 0;
	while (len--)
	{
		if (is_negative && len == 0)
		{
			res[len] = '-';
			i++;
			break ;
		}
		res[len] = num % 10 + '0';
		num = num / 10;
		i++;
	}
	res[i] = '\0';
}


static char	*ft_uitoa(unsigned int n)
{
	char	*res;
	int		len;
	long	num;
	int		is_negative;

	len = 0;
	num = n;
	is_negative = 0;
	len += ft_intlen(num);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	ft_num_to_str(res, is_negative, num, len);
	return (res);
}


void ft_putunbr_pf(unsigned int num, int *counter)
{
	int 	i;
	char	*num_str;

	num_str = ft_uitoa(num);
	i = 0;
	while (num_str[i])
	{
		ft_putchar_pf(num_str[i], counter);
		i++;
	}
	free(num_str);
}

