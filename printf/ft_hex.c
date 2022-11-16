/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:37:18 by jtsizik           #+#    #+#             */
/*   Updated: 2022/10/29 15:38:46 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long long x, char c)
{
	if (x == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (x >= 16)
	{
		ft_print_hex(x / 16, c);
		ft_print_hex(x % 16, c);
	}
	else
	{
		if (x <= 9)
			ft_putchar(x + '0');
		if (x > 9 && c == 'X')
			ft_putchar(x - 10 + 'A');
		if (x > 9 && c != 'X')
			ft_putchar(x - 10 + 'a');
	}
	return (0);
}

size_t	ft_find_hex_len(unsigned long long p)
{
	size_t	len;

	len = 0;
	if (p == 0)
		return (1);
	while (p != 0)
	{
		p /= 16;
		len++;
	}
	return (len);
}

size_t	ft_hex(unsigned int x, int c)
{
	size_t	len;

	len = ft_find_hex_len(x);
	ft_print_hex(x, c);
	return (len);
}
