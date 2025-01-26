/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 01:23:10 by francescotr       #+#    #+#             */
/*   Updated: 2024/02/25 13:08:36 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int num)
{
	int		i;
	long	nb;

	nb = num;
	i = 0;
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		i += ft_putnbr(nb / 10);
	i += ft_putchar(nb % 10 + 48);
	return (i);
}

int	ft_hex_putnbr(unsigned long nb, char *s)
{
	int	i;

	i = 0;
	if (nb >= 16)
		i += ft_hex_putnbr(nb / 16, s);
	i += ft_putchar(s[nb % 16]);
	return (i);
}

int	ft_unsigned_putnbr(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb > 9)
		i += ft_putnbr(nb / 10);
	i += ft_putchar(nb % 10 + 48);
	return (i);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}
