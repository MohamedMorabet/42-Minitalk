/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:15:33 by mel-mora          #+#    #+#             */
/*   Updated: 2025/02/10 18:25:41 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_params(const char c, va_list args, int *resu)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), resu);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), resu);
	else if (c == 'd' || c == 'i')
		ft_putnbr_dec(va_arg(args, int), resu);
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), resu);
	else if (c == 'x' || c == 'X')
		ft_putnbr_hexa(va_arg(args, unsigned int), resu, c);
	else if (c == 'p')
	{
		ft_putstr ("0x", resu);
		ft_tohexa(va_arg(args, unsigned long), resu);
	}
	else
		ft_putchar(c, resu);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		resu;
	va_list	args;

	if (write(1, NULL, 0) == -1)
		return (-1);
	i = 0;
	resu = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			print_params (format[i + 1], args, &resu);
			i++;
		}
		else if (format[i] != '%')
			ft_putchar (format[i], &resu);
		i++;
	}
	va_end(args);
	return (resu);
}
