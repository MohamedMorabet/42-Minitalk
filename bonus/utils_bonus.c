/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:27:04 by mel-mora          #+#    #+#             */
/*   Updated: 2025/02/11 14:45:56 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	check_overflow(unsigned long result, int nb, int sign)
{
	if (sign == 1)
	{
		if ((result >= 922337203685477580 && nb > 7) 
			|| result >= 922337203685477581)
			return (-1);
	}
	if (sign == -1)
	{
		if ((result >= 922337203685477580 && nb > 8) 
			|| result > 922337203685477581)
			return (0);
	}
	return (1);
}

static void	check_sign(int *i, int *sign, const char *str)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	result;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	check_sign(&i, &sign, str);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (check_overflow(result, str[i] - '0', sign) != 1)
				return (check_overflow(result, str[i] - '0', sign));
			result = result * 10 + (str[i++] - '0');
		}
		else
		{
			ft_printf("❌ Invalid PID\n");
			exit(1);
		}
	}
	return (result * sign);
}

int	get_pid(char *str)
{
	int	server_pid;

	server_pid = ft_atoi(str);
	if (server_pid <= 0)
	{
		ft_printf("❌ Invalid PID\n");
		exit(1);
	}
	return (server_pid);
}

void	setup_signal(int signum, void *handler, bool use_sigaction)
{
	struct sigaction	sa;

	if (use_sigaction)
	{
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = handler;
	}
	else
		sa.sa_handler = handler;
	if (sigaction(signum, &sa, NULL) < 0)
	{
		ft_printf("❌ sigaction failed\n");
		exit(EXIT_FAILURE);
	}
}
