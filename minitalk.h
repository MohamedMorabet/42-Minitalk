/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:21:18 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/31 16:30:37 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include "printf/ft_printf.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

enum {
    READY,
    BUSY //change it later
};

int	ft_atoi(const char *str);
int	ft_printf(const char *format, ...);
int	get_pid(char *str);
void    Signal(int, void *, bool);
void    Kill(pid_t, int);

#endif