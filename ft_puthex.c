/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:02:49 by ipresno-          #+#    #+#             */
/*   Updated: 2022/10/03 12:28:48 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(size_t adr, char c)
{
	char	*low;
	char	*upper;
	int		len;

	low = "0123456789abcdef";
	upper = "0123456789ABCDEF";
	len = 0;
	if (c == 'x' || c == 'p')
	{
		if (adr >= 16)
			len += ft_puthex(adr / 16, c);
		len += ft_putchar(low[adr % 16]);
		return (len);
	}
	else if (c == 'X')
	{
		if (adr >= 16)
			len += ft_puthex(adr / 16, c);
		len += ft_putchar(upper[adr % 16]);
		return (len);
	}
	return (0);
}
