/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:54:19 by aboumata          #+#    #+#             */
/*   Updated: 2024/11/26 21:54:25 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str, int *count)
{
	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		*count += 6;
		return (0);
	}
	while (*str)
	{
		if (ft_putchar(*str++, count) == -1)
			return (-1);
	}
	return (0);
}
