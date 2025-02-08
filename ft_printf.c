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

static int	handle_percent(char **format, va_list a, int *count)
{
	char	*str;

	str = "cspdiuxX%";
	while (*str && *str != **format)
		str++;
	if (*str)
		return (ft_process_format(**format, a, count));
	if (ft_putchar('%', count) != -1 && ft_putchar(**format, count) != -1)
		return (0);
	return (-1);
}

int	ft_printf(char *format, ...)
{
	va_list	arg;
	int		count;

	count = 0;
	va_start(arg, format);
	if (!format)
		return (va_end(arg), 0);
	while (*format)
	{
		if (*format == '%' && ++format)
		{
			if (!*format)
				break ;
			if (handle_percent(&format, arg, &count) == -1)
				return (va_end(arg), -1);
			format++;
		}
		else if (ft_putchar(*format++, &count) == -1)
			return (va_end(arg), -1);
	}
	return (va_end(arg), count);
}
