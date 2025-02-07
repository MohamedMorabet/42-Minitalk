/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:01:48 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/28 18:21:03 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *resu)
{
	write (1, &c, 1);
	*resu += 1;
}

void	ft_putstr(char *s, int *resu)
{
	int	j;

	if (!s)
	{
		ft_putstr ("(null)", resu);
		return ;
	}
	j = 0;
	while (s[j])
	{
		ft_putchar (s[j], resu);
		j++;
	}
}

void	ft_tohexa(unsigned long num, int *resu)
{
	char	*tab;

	tab = "0123456789abcdef";
	if (num < 16)
		ft_putchar (tab[num], resu);
	else
	{
		ft_tohexa (num / 16, resu);
		ft_putchar (tab[num % 16], resu);
	}
}
