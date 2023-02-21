/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:40:01 by mmorue            #+#    #+#             */
/*   Updated: 2023/02/21 18:45:03 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "./printf/ft_printf.h"

void	server(void)
{
	int	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_binary_to_ascii(int bit, int index)
{
	int	i;

	i = 0;
	while (i < 7 - index)
	{
		bit = bit * 2;
		i++;
	}
	return (bit);
}

void	display(int signum)
{
	static int	bit;
	static int	i;
	int			binary_check;

	binary_check = 2;
	if (signum == SIGUSR1)
		binary_check = 0;
	if (signum == SIGUSR2)
		binary_check = 1;
	if (binary_check == 2)
	{
		return ;
	}
	bit += ft_binary_to_ascii(binary_check, i);
	i++;
	if (i == 8)
	{
		ft_putchar(bit);
		i = 0;
		bit = 0;
		return ;
	}
}

int	main(void)
{
	server();
	while (1)
	{
		signal(SIGUSR1, display);
		signal(SIGUSR2, display);
		pause();
	}
}
