/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niverdie <niverdie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:59:38 by niverdie          #+#    #+#             */
/*   Updated: 2025/11/30 17:13:47 by niverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int		ft_strlen(char *str);
int		is_valid_format(char c);
int		ft_printf(const char *str, ...) __attribute__((format(printf, 1, 2)));
void	ft_putnbr(int *count, long long int nbr);
int		process_arg(char c, int *count, va_list args);
void	ft_putchar(int *count, char c);
void	ft_putstr(int *count, char *str);
void	ft_putnbr_U(int *count, unsigned int nbr);
void	ft_putnbrp(int *count, unsigned long int pointer, const char *base);
void	ft_putnbrhex(int *count, unsigned int hex, char *base);
#endif