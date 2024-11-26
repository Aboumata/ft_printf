/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:58:13 by aboumata          #+#    #+#             */
/*   Updated: 2024/11/26 21:58:21 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(void *ptr, int *count)
{
	uintptr_t	addr;

	addr = (uintptr_t)ptr;
	if (write(1, "0x", 2) == -1)
		return (-1);
	*count += 2;
	if (addr == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		*count += 1;
		return (0);
	}
	return (ft_putnbr_base(addr, "0123456789abcdef", 16, count));
}
