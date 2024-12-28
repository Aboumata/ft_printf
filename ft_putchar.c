/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:52:20 by aboumata          #+#    #+#             */
/*   Updated: 2024/11/26 21:52:35 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int *count)
{
	ssize_t	written;

	written = write(1, &c, 1);
	if (written == -1)
		return (-1);
	*count += written;
	return (0);
}
