/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:24:35 by mel-mora          #+#    #+#             */
/*   Updated: 2025/02/10 18:25:50 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putstr(char *s, int *resu);
void	ft_putchar(char c, int *resu);
void	ft_putnbr_dec(int num, int *resu);
void	ft_putnbr_unsigned(unsigned int num, int *resu);
void	ft_putnbr_hexa(unsigned int num, int *resu, const char c);
void	ft_tohexa(unsigned long num, int *resu);

#endif