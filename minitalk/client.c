/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:07:32 by mmorue            #+#    #+#             */
/*   Updated: 2023/02/21 18:45:02 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "./printf/ft_printf.h"

void	ft_ascii_to_binary(int pid, char c)
{
	int	bit[8];
	int	i;

	i = 7;
	while (i >= 0)
	{
		bit[i] = c % 2;
		c = c / 2;
		i--;
	}
	i = 0;
	while (i < 8)
	{
		if (bit[i] == 0)
			kill(pid, SIGUSR1);
		else if (bit[i] == 1)
			kill(pid, SIGUSR2);
		usleep(80);
		i++;
	}	
}

void	client(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_ascii_to_binary(pid, str[i]);
		i++;
	}
	ft_ascii_to_binary(pid, '\n');
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	else
	{
		if (kill(atoi(argv[1]), 0) == -1)
		{
			ft_printf("error this process doesn't exist");
			return (0);
		}
		client(ft_atoi(argv[1]), argv[2]);
	}
	return (0);
}
