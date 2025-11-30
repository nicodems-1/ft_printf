/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niverdie <niverdie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 09:36:25 by niverdie          #+#    #+#             */
/*   Updated: 2025/11/30 17:47:42 by niverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	args;

	i = 0;
	count = 0;
	if (str == NULL)
		return (0);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && is_valid_format(str[i + 1]))
			process_arg(str[++i], &count, args);
		else
        {
            if (str[i] == '%' && str[i + 1] == '\0')
                return (-1);
			ft_putchar(&count, str[i]);
        }
		i++;
	}
	return (count);
}
