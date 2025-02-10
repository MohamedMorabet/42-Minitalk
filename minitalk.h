/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:21:18 by mel-mora          #+#    #+#             */
/*   Updated: 2025/02/10 18:34:22 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "printf/ft_printf.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

enum {
	READY,
	BUSY
};

# define INIT_SIZE 100

int		ft_atoi(const char *str);
int		ft_printf(const char *format, ...);
int		get_pid(char *str);
void	setup_signal(int signum, void *handler, bool use_sigaction);
void	my_kill(pid_t pid, int signum);
char	*allocate_buffer(int size);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif