/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:43:39 by mel-mora          #+#    #+#             */
/*   Updated: 2025/02/07 19:16:59 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char		c = 0;
	static int		i = 0;
	static pid_t	pid = 0;

	if (info->si_pid)
		pid = info->si_pid;
	(void)context;
	if (sig == SIGUSR1)
		c |= (0b10000000 >> i);
	i++;
	if (i == 8)
	{
		i = 0;
		if (c == 0)
		{
			write(1, "\n", 1);
			kill(pid, SIGUSR2);
			c = 0;
			return ;
		}
		write(1, &c, 1);
		c = 0;
	}
	kill(pid, SIGUSR1);
}

int main(int ac, char **av)
{
	if (ac != 1)
	{
		ft_printf("Usage: %s\n", av[0]);
		return (EXIT_FAILURE);
	}
	ft_printf("🛠️ MiniTalk Server is LIVE! 🔥 PID: %d 🏹\n", getpid());
	Signal(SIGUSR1, handle_signal, true);
	Signal(SIGUSR2, handle_signal, true);
	while (1)
		pause();
	return EXIT_SUCCESS;
}