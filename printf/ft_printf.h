/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:04:30 by jtsizik           #+#    #+#             */
/*   Updated: 2022/10/29 16:47:04 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);
size_t	ft_putchar(int c);
size_t	ft_putstr(char *s);
size_t	ft_putnbr(int n);
size_t	ft_putuint(unsigned int n);
size_t	ft_print_mem(unsigned long long p);
size_t	ft_find_hex_len(unsigned long long p);
size_t	ft_hex(unsigned int x, int c);
int		ft_print_hex(unsigned long long x, char c);
size_t	ft_find_nbr_len(unsigned int n);
#endif