/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annexes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:34:59 by mmorue            #+#    #+#             */
/*   Updated: 2022/11/22 16:26:13 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static char	*fill_tab(char *str, unsigned int new, unsigned int i)
{
	str[i--] = '\0';
	while (new != 0)
	{
		str[i] = (new % 10) + '0';
		new = new / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa_u(unsigned int n)
{
	unsigned int	i;
	unsigned int	new;
	char			*str;

	new = n;
	i = get_size(new);
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (0);
	if (n == 0)
		str[0] = '0';
	return (fill_tab(str, new, i));
}
