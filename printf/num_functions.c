/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:35:44 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/28 18:20:59 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_dec(int num, int *resu)
{
	if (num == -2147483648)
		ft_putstr("-2147483648", resu);
	else if (num < 0)
	{
		ft_putchar ('-', resu);
		num *= -1;
		ft_putnbr_dec (num, resu);
	}
	else if (num <= 9)
	{
		ft_putchar (num + 48, resu);
	}
	else
	{
		ft_putnbr_dec (num / 10, resu);
		ft_putchar (num % 10 + 48, resu);
	}
}

void	ft_putnbr_unsigned(unsigned int num, int *resu)
{
	if (num <= 9)
	{
		ft_putchar (num + 48, resu);
	}
	else
	{
		ft_putnbr_unsigned (num / 10, resu);
		ft_putchar (num % 10 + 48, resu);
	}
}

void	ft_putnbr_hexa(unsigned int num, int *resu, const char c)
{
	char	*tab;

	if (c == 'x')
		tab = "0123456789abcdef";
	else if (c == 'X')
		tab = "0123456789ABCDEF";
	if (num < 16)
		ft_putchar(tab[num], resu);
	else
	{
		ft_putnbr_hexa (num / 16, resu, c);
		ft_putchar(tab[num % 16], resu);
	}
}
