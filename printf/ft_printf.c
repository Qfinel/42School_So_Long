/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:52:03 by jtsizik           #+#    #+#             */
/*   Updated: 2022/10/30 17:00:16 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_get_var(va_list argp, int c)
{
	size_t	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(argp, int));
	if (c == 's')
		i += ft_putstr(va_arg(argp, char *));
	if (c == 'p')
		i += ft_print_mem(va_arg(argp, unsigned long long));
	if (c == 'd' || c == 'i')
		i += ft_putnbr(va_arg(argp, int));
	if (c == 'u')
		i += ft_putuint(va_arg(argp, unsigned int));
	if (c == 'x' || c == 'X')
		i += ft_hex(va_arg(argp, unsigned int), c);
	if (c == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *s, ...)
{
	size_t	i;
	int		count;
	va_list	argp;

	va_start(argp, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			write(1, &s[i], 1);
			count++;
		}
		if (s[i] == '%')
		{
			i++;
			if (s[i] == 'c' || s[i] == 's' || s[i] == 'p'
				|| s[i] == 'd' || s[i] == 'i' || s[i] == 'u'
				|| s[i] == 'x' || s[i] == 'X' || s[i] == '%')
				count += ft_get_var(argp, s[i]);
		}
		i++;
	}
	return (va_end(argp), count);
}
