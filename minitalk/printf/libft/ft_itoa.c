/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:43:12 by mmorue            #+#    #+#             */
/*   Updated: 2022/11/08 15:11:10 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	get_size(unsigned int new)
{
	int	size;

	size = 0;
	while (new >= 10)
	{
		new = new / 10;
		size++;
	}
	size++;
	return (size);
}

static char	*fill_tab(char *str, unsigned int new, unsigned int i, int flag)
{
	str[i-- + flag] = '\0';
	while (new != 0)
	{
		str[i + flag] = (new % 10) + '0';
		new = new / 10;
		i--;
	}
	if (flag == 1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	unsigned int	i;
	int				flag;
	unsigned int	new;
	char			*str;

	flag = 0;
	if (n < 0)
	{
		flag = 1;
		new = -n;
	}
	else
		new = n;
	i = get_size(new);
	str = malloc((i + flag + 1) * sizeof(char));
	if (!str)
		return (0);
	if (n == 0)
		str[0] = '0';
	return (fill_tab(str, new, i, flag));
}
