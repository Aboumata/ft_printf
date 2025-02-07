/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:48:52 by aboumata          #+#    #+#             */
/*   Updated: 2024/11/26 13:49:07 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_process_format(char spec, va_list args, int *count)
{
	if (spec == 'c')
		return (ft_putchar(va_arg(args, int), count));
	else if (spec == 's')
		return (ft_putstr(va_arg(args, char *), count));
	else if (spec == 'p')
		return (ft_putpointer(va_arg(args, void *), count));
	else if (spec == 'd' || spec == 'i')
		return (ft_putnbr_signed(va_arg(args, int), count));
	else if (spec == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789", 10,
				count));
	else if (spec == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef",
				16, count));
	else if (spec == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF",
				16, count));
	else if (spec == '%')
		return (ft_putchar('%', count));
	return (0);
}

static int	handle_percent(char **f, va_list a, int *c)
{
	char	*s;

	s = "cspdiuxX%";
	while (*s && *s != **f)
		s++;
	if (*s)
		return (ft_process_format(**f, a, c));
	if (ft_putchar('%', c) != -1 && ft_putchar(**f, c) != -1)
		return (0);
	return (-1);
}

int	ft_printf(char *f, ...)
{
	va_list	a;
	int		c;

	c = 0;
	va_start(a, f);
	if (!f)
		return (va_end(a), 0);
	while (*f)
	{
		if (*f == '%' && ++f)
		{
			if (!*f)
				break ;
			if (handle_percent(&f, a, &c) == -1)
				return (va_end(a), -1);
			f++;
		}
		else if (ft_putchar(*f++, &c) == -1)
			return (va_end(a), -1);
	}
	return (va_end(a), c);
}
