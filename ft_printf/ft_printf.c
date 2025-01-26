/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:24:33 by francescotr       #+#    #+#             */
/*   Updated: 2024/02/25 13:09:07 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_meetperc(char c, va_list list_arg)
{
	if (c == 'c')
		return (ft_putchar(va_arg(list_arg, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(list_arg, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(list_arg, int)));
	else if (c == 'u')
		return (ft_unsigned_putnbr(va_arg(list_arg, unsigned int)));
	else if (c == 'p')
		return ((ft_putstr ("0x")) + (ft_hex_putnbr(va_arg
					(list_arg, unsigned long), "0123456789abcdef")));
	else if (c == 'x')
		return (ft_hex_putnbr(va_arg(list_arg, unsigned int),
				"0123456789abcdef" ));
	else if (c == 'X')
		return (ft_hex_putnbr(va_arg(list_arg, unsigned int),
				"0123456789ABCDEF" ));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar(c));
}

int	ft_printf(const char *s, ...)
{
	int		c;
	va_list	listarg;
	int		i;

	i = 0;
	c = 0;
	va_start(listarg, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			c = c + ft_meetperc(s[i + 1], listarg);
			i++;
		}
		else
			c = c + ft_putchar(s[i]);
		i++;
	}
	va_end(listarg);
	return (c);
}
