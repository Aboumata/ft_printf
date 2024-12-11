/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:56:16 by aboumata          #+#    #+#             */
/*   Updated: 2024/11/26 21:56:21 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long long nbr, const char *base, const int base_len,
		int *count)
{
	if (nbr >= (unsigned long long)base_len)
	{
		if (ft_putnbr_base(nbr / base_len, base, base_len, count) == -1)
			return (-1);
	}
	if (ft_putchar(base[nbr % base_len], count) == -1)
		return (-1);
	return (0);
}
