/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niverdie <niverdie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:00:43 by niverdie          #+#    #+#             */
/*   Updated: 2025/11/30 17:13:24 by niverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbrhex(int *count, unsigned int hex, char *base)
{
	unsigned int	baselen;

	baselen = ft_strlen((char *)base);
	if (hex >= baselen)
		ft_putnbrhex(count, hex / baselen, base);
	ft_putchar(count, base[hex % baselen]);
}
