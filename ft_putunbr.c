/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:49:46 by ipresno-          #+#    #+#             */
/*   Updated: 2022/10/03 12:27:33 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int unbr)
{
	int	len;

	len = 0;
	if (unbr > 9)
		len += ft_putunbr(unbr / 10);
	len += ft_putchar((unbr % 10) + '0');
	return (len);
}
