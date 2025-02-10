/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:43:39 by mel-mora          #+#    #+#             */
/*   Updated: 2025/02/10 18:35:59 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_str = NULL;

void	expand_buffer(int new_size)
{
	char	*new_str;

	new_str = (char *)malloc(new_size);
	if (!new_str)
	{
		write(2, "Memory allocation error\n", 24);
		exit(1);
	}
	if (g_str)
	{
		ft_memcpy(new_str, g_str, new_size - INIT_SIZE);
		free(g_str);
	}
	g_str = new_str;
}

void	reset_message(pid_t *pid, int *len, int *buf_size, int new_pid)
{
	*pid = new_pid;
	*len = 0;
	*buf_size = INIT_SIZE;
	free(g_str);
	g_str = allocate_buffer (INIT_SIZE);
}

void	process_byte(char *c, int *len, int *buffer_size, pid_t *pid)
{
	if (*c == 0)
	{
		if (*len > 0)
		{
			write(1, g_str, *len);
			write(1, "\n", 1);
		}
		*len = 0;
		my_kill(*pid, SIGUSR2);
		return ;
	}
	g_str[(*len)++] = *c;
	if (*len >= *buffer_size - 1)
	{
		*buffer_size += INIT_SIZE;
		expand_buffer(*buffer_size);
	}
	*c = 0;
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char		c = 0;
	static int		i = 0;
	static int		len = 0;
	static int		buffer_size = INIT_SIZE;
	static pid_t	pid = 0;

	(void)context;
	if (!g_str)
		g_str = allocate_buffer(INIT_SIZE);
	if (info->si_pid && info->si_pid != pid)
	{
		i = 0;
		reset_message(&pid, &len, &buffer_size, info->si_pid);
	}
	if (sig == SIGUSR1)
		c |= (0b10000000 >> i);
	i++;
	if (i == 8)
	{
		i = 0;
		process_byte(&c, &len, &buffer_size, &pid);
	}
	my_kill(pid, SIGUSR1);
}

int	main(int ac, char **av)
{
	if (ac != 1)
	{
		ft_printf("Usage: %s\n", av[0]);
		return (EXIT_FAILURE);
	}
	ft_printf("🛠️ MiniTalk Server is LIVE! 🔥 PID: %d 🏹\n", getpid());
	setup_signal(SIGUSR1, handle_signal, true);
	setup_signal(SIGUSR2, handle_signal, true);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
