/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:17:39 by jtsizik           #+#    #+#             */
/*   Updated: 2022/11/11 15:45:28 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

size_t	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		i = ft_putstr("(null)");
		return (i);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

size_t	ft_putnbr(int n)
{
	char	*s;
	size_t	i;

	i = 0;
	s = ft_itoa(n);
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	free(s);
	return (i);
}

size_t	ft_print_mem(unsigned long long p)
{
	size_t	i;

	i = 2;
	write(1, "0x", 2);
	i += ft_find_hex_len(p);
	ft_print_hex(p, 0);
	return (i);
}
