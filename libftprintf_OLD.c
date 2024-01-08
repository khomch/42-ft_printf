
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

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int is_in_charset(char c, char *charset)
{
	int i;
	char s1[2];
	char s2[2];

	s1[0] = '%';
	s2[0] = '%';
	s2[1] = c;
	i = 0;
	while (charset[i])
	{
		s1[1] = charset[i];
		if (ft_strncmp(s1, s2, sizeof(s1)) == 0)
			return (1);
		i++;
	}
	return (0);
}

int count_args(const char *str, char *charset)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (is_in_charset(str[i], charset))
			count++;
		i++;
	}
	return (count);
}

char *create_part_of_str(const char *str, char c, int start, char *charset)
{
	int count;
	int i;
	int y;
	char *res;

	count = 0;
	i = 0;
	y = start;
	while (str[start] && !is_in_charset(str[start], charset))
	{
		count++;
		start++;
	}
	count--;
	start++;
	res = (char *)malloc(sizeof(char) * count);
	while (i < count)
	{
		res[i] = str[y + i];
		i++;
	}
	res[i++] = c;
	i = '\0';
	return (res);
}

int ft_printf(const char *str, ...)
{
	va_list args;
	va_start(args, str);
	int i;
	int ptr;
	int argsQty;
	char *res;
	char *temp_str;
	char *temp_res;

	argsQty = count_args(str, "c");
	ptr = 0;
	temp_str = ft_strdup("");
	res = ft_strdup("");
	i = 0;
	while (i < argsQty)
	{
		char arg = va_arg(args, int);
		temp_str = create_part_of_str(str, arg, ptr, "c");
		while (str[ptr] && !is_in_charset(str[ptr], "c"))
		{
			ptr++;
		}
		ptr++;
		temp_res = ft_strdup(res);
		res = ft_strjoin(temp_res, temp_str);
		printf("TEMP STR %s\n", temp_str);
		free(temp_res);
		free(temp_str);
		printf("\ni: %d, arg: %c\n", i, arg);
		i++;
	}
	i = 0;
	int end;
	end = ptr;
	while (str[end])
		end++;
	while (str[ptr])
	{
		temp_str = ft_strdup("");
		temp_str = (char *)malloc(sizeof(char) * end - ptr + 1);
		temp_str[i] = str[ptr];
		i++;
		ptr++;
	}
	temp_str[i] = '\0';
	temp_res = ft_strdup(res);
	printf("TEMP STR 1 %s\n", temp_str);
	res = ft_strjoin(temp_res, temp_str);
	free(temp_res);
	free(temp_str);
	va_end(args);
	ft_putstr(res);
	free(res);
	return (42);
}

int main(void)
{
	ft_printf("Hello %c %c World \n", 'A', 'B', 'C');
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
