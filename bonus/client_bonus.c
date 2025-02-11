/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:20:15 by mel-mora          #+#    #+#             */
/*   Updated: 2025/02/11 12:20:26 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_signa = BUSY;

static void	handle_signa(void)
{
	g_signa = READY;
}

void	end_hundler(void)
{
	ft_printf("📨 BOOM! Message delivered successfully! 🚀💌\n");
	exit(EXIT_SUCCESS);
}

void	send_char(pid_t server_pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (0x80 >> i))
			my_kill(server_pid, SIGUSR1);
		else
			my_kill(server_pid, SIGUSR2);
		i++;
		while (g_signa == BUSY)
			usleep(50);
		g_signa = BUSY;
	}
}

int	main(int ac, char **av)
{
	pid_t	server_pid;
	char	*msg;

	if (ac != 3)
	{
		ft_printf("⛔ Oops! Incorrect usage! 🤨\n");
		ft_printf("📌 Correct f  ormat: %s [server_pid] [message]\n", av[0]);
		return (EXIT_FAILURE);
	}
	server_pid = ft_atoi(av[1]);
	msg = av[2];
	setup_signal(SIGUSR1, handle_signa, false);
	setup_signal(SIGUSR2, end_hundler, false);
	while (*msg)
		send_char(server_pid, *msg++);
	send_char(server_pid, '\0');
}
