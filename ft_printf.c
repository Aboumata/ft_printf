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

int	ft_printf(char *format, ...)
{
	va_list	args;
	int		count;
	char	*s;

	count = 0;
	va_start(args, format);
	if (!format)
		return (0);
	while (*format)
	{
		if (*format == '%' && (++format))
		{
			if (!*format)
				break ;
			s = "cspdiuxX%";
			while (*s && *s != *format)
				s++;
			if ((*s && ft_process_format(*format, args, &count) == -1) || (!*s
					&& (ft_putchar('%', &count) == -1 || ft_putchar(*format,
							&count) == -1)))
				return (va_end(args), -1);
			format++;
		}
		else if (ft_putchar(*format++, &count) == -1)
			return (va_end(args), -1);
	}
	return (va_end(args), count);
}

// int	main(void)
// {
// 	printf(NULL);
// 	putchar('\n');
// 	ft_printf("k");
//
// 	return (0);
// }
