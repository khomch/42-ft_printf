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

static void	ft_pointerlen(uintptr_t pointer, int *counter)
{
	while (pointer != 0)
	{
		pointer = pointer / 16;
		(*counter)++;
	}
}

void	ft_printpointer(uintptr_t pointer)
{
	if (pointer >= 16)
	{
		ft_printpointer(pointer / 16);
		ft_printpointer(pointer % 16);
	}
	else
	{
		if (pointer < 10)
			ft_putchar_fd((pointer + '0'), 1);
		else
			ft_putchar_fd((pointer - 10 + 'a'), 1);
	}
}

void	ft_putpointer(unsigned long long address, int *counter)
{
	if (address == 0)
		(*counter) += write(1, "(nil)", 5);
	else
	{
		(*counter) += write(1, "0x", 2);
		ft_printpointer(address);
		ft_pointerlen(address, counter);
	}
}