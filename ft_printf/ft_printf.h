/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:15:22 by ftroise           #+#    #+#             */
/*   Updated: 2024/02/25 13:09:29 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_ptr(unsigned long long n);
int	ft_putnbr(int num);
int	ft_printf(const char *s, ...);
int	ft_meetperc(char c, va_list list_arg);
int	ft_unsigned_putnbr(unsigned int nb);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_hex_putnbr(unsigned long nb, char *s);

int	ft_fill_str(char c, va_list list_arg);

#endif
