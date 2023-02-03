/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:59:26 by ipresno-          #+#    #+#             */
/*   Updated: 2023/01/13 12:16:08 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_formats(va_list args, const char format, int len)
{
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_putunbr(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_puthex(va_arg(args, unsigned int), format);
	else if (format == 'p')
		len += ft_putstr("0x") + ft_puthex(va_arg(args, size_t), format);
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len = ft_formats(args, *str, len);
		}
		else
			len += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (len);
}
