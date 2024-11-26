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

static void	ft_putchar(char c, int *count)
{
	*count += write(1, &c, 1);
}

static void	ft_putstr(const char *str, int *count)
{
	if (str == NULL)
	{
		*count += write(1, "(null)", 6);
		return ;
	}
	while (*str)
		ft_putchar(*str++, count);
}

static void	ft_putnbr_base(long long nbr, const char *base, int base_len,
		int *count)
{
	if (nbr < 0)
	{
		ft_putchar('-', count);
		nbr = -nbr;
	}
	if (nbr >= base_len)
		ft_putnbr_base(nbr / base_len, base, base_len, count);
	ft_putchar(base[nbr % base_len], count);
}

static void	ft_putpointer(void *ptr, int *count)
{
	uintptr_t	addr;

	addr = (uintptr_t)ptr;
	*count += write(1, "0x", 2);
	ft_putnbr_base(addr, "0123456789abcdef", 16, count);
}

static void	ft_process_format(char spec, va_list args, int *count)
{
	if (spec == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (spec == 's')
		ft_putstr(va_arg(args, const char *), count);
	else if (spec == 'p')
		ft_putpointer(va_arg(args, void *), count);
	else if (spec == 'd' || spec == 'i')
		ft_putnbr_base(va_arg(args, int), "0123456789", 10, count);
	else if (spec == 'u')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789", 10, count);
	else if (spec == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef", 16,
			count);
	else if (spec == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", 16,
			count);
	else if (spec == '%')
		ft_putchar('%', count);
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
			ft_process_format(*(++format), args, &count);
		else
			ft_putchar(*format, &count);
		format++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	ft_printf("Character: %c\n", 'A');
	ft_printf("String: %s\n", "Hello, world!");
	ft_printf("Pointer: %p\n", (void *)0x7ffeefbff5c8);
	ft_printf("Decimal: %d\n", -42);
	ft_printf("Integer: %i\n", 123);
	ft_printf("Unsigned: %u\n", 3000000000U);
	ft_printf("Hexadecimal (lowercase): %x\n", 255);
	ft_printf("Hexadecimal (uppercase): %X\n", 255);
	ft_printf("Percent: %%\n");
	return (0);
}
