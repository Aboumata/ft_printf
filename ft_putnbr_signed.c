/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_signed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:18:26 by aboumata          #+#    #+#             */
/*   Updated: 2024/11/26 22:18:32 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_signed(int nbr, int *count)
{
	if (nbr == -2147483648)
	{
		if (ft_putstr("-2147483648", count) == -1)
			return (-1);
		return (0);
	}
	if (nbr < 0)
	{
		if (ft_putchar('-', count) == -1)
			return (-1);
		nbr = -nbr;
	}
	return (ft_putnbr_base((unsigned long int)nbr, "0123456789", 10, count));
}
