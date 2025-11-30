/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niverdie <niverdie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:01:06 by niverdie          #+#    #+#             */
/*   Updated: 2025/11/30 17:09:17 by niverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(int *count, char c)
{
	write(1, &c, 1);
	*count += 1;
}

void	ft_putstr(int *count, char *str)
{
	if (!str)
	{
		write(1, "(null)", 6);
		*count += 6;
		return ;
	}
	write(1, str, ft_strlen(str));
	*count += ft_strlen(str);
}

void	ft_putnbr(int *count, long long int nbr)
{
	if (nbr < 0)
	{
		ft_putchar(count, '-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr(count, nbr / 10);
	ft_putchar(count, nbr % 10 + 48);
}

void	ft_putnbrp(int *count, unsigned long int pointer, const char *base)
{
	unsigned int	baselen;

	if (pointer == 0)
	{
		ft_putstr(count, "(nil)");
		return ;
	}
	baselen = ft_strlen((char *)base);
	if (pointer >= baselen)
		ft_putnbrp(count, pointer / baselen, base);
	ft_putchar(count, base[pointer % baselen]);
}
