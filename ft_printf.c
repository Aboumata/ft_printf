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

static int	ft_process_format(char spec, va_list args, int *count)
{
	if (spec == 'c')
		return (ft_putchar(va_arg(args, int), count));
	else if (spec == 's')
		return (ft_putstr(va_arg(args, const char *), count));
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

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			if (ft_process_format(*(++format), args, &count) == -1)
			{
				va_end(args);
				return (-1);
			}
		}
		else if (ft_putchar(*format, &count) == -1)
		{
			va_end(args);
			return (-1);
		}
		format++;
	}
	va_end(args);
	return (count);
}
/*
int	main(void)
{
	ft_printf("Character: %c\n", 'A');
	ft_printf("String: %s\n", "Hello, world!");
	ft_printf("%p\n", NULL);
	ft_printf("%p %p\n", (void *)LONG_MIN, (void *)LONG_MAX);
	ft_printf("%p\n", (void *)ULONG_MAX);
	ft_printf("%p\n", (void *)(-ULONG_MAX));
	ft_printf("Decimal: %d\n", -42);
	ft_printf("Integer: %i\n", 123);
	ft_printf("Unsigned: %u\n", 3000000000U);
	ft_printf("Hexadecimal (lowercase): %x\n", 255);
	ft_printf("Hexadecimal (uppercase): %X\n", 255);
	ft_printf("Percent: %%\n");
	return (0);
}
*/