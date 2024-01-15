/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ax <ax@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:48:27 by ax                #+#    #+#             */
/*   Updated: 2024/01/07 18:34:07 by ax               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	    ft_printf(const char *format, ...);
int	    check_if_double(char *base);
void    ft_putchar_pf(char c, int *counter);
void    ft_putstr_pf(const char *str, int *counter);
void    ft_putnbr_pf(int num, int *counter);
void    ft_putunbr_pf(unsigned int num, int *counter);
void    ft_print_nbr(int n, int base_value, char *symbols, int *counter);
void	ft_puthexadecimal(unsigned int input_number,
				const char format, int *counter);
void    ft_putpointer(unsigned long long address, int *counter);

#endif
