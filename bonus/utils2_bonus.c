/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:05:53 by mel-mora          #+#    #+#             */
/*   Updated: 2025/02/11 14:37:12 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == src)
		return (dest);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char	*allocate_buffer(int size)
{
	char	*new_str;

	new_str = (char *)malloc(size);
	if (!new_str)
	{
		write(2, "Memory allocation error\n", 24);
		exit(1);
	}
	return (new_str);
}

void	my_kill(pid_t pid, int signum)
{
	if (kill(pid, signum) < 0)
	{
		ft_printf("❌ kill failed, Invalid pid\n");
		exit(EXIT_FAILURE);
	}
}
