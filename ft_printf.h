/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:09:30 by aboumata          #+#    #+#             */
/*   Updated: 2024/11/26 18:09:39 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int	ft_printf(char *format, ...);
int	ft_putchar(char c, int *count);
int	ft_putstr(char *str, int *count);
int	ft_putnbr_base(unsigned long int nbr, char *base, int base_len,
		int *count);
int	ft_putpointer(void *ptr, int *count);
int	ft_putnbr_signed(int nbr, int *count);

#endif
