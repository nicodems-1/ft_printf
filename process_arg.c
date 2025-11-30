/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niverdie <niverdie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:54:33 by niverdie          #+#    #+#             */
/*   Updated: 2025/11/30 17:13:01 by niverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	process_arg(char c, int *count, va_list args)
{
	unsigned long int	temp;

	if (c == 'c')
		ft_putchar(count, va_arg(args, int));
	else if (c == 's')
		ft_putstr(count, va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		ft_putnbr(count, va_arg(args, int));
	else if (c == 'u')
		ft_putnbr(count, va_arg(args, unsigned int));
	else if (c == 'p')
	{
		temp = va_arg(args, unsigned long int);
		if (temp != 0)
			ft_putstr(count, "0x");
		ft_putnbrp(count, temp, "0123456789abcdef");
	}
	else if (c == 'x')
		ft_putnbrhex(count, va_arg(args, int), "0123456789abcdef");
	else if (c == 'X')
		ft_putnbrhex(count, va_arg(args, int), "0123456789ABCDEF");
	else if (c == '%')
		ft_putchar(count, '%');
	return (0);
}
