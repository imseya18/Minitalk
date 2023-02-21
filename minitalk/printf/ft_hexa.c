/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:38:44 by mmorue            #+#    #+#             */
/*   Updated: 2022/11/22 16:26:15 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size_hexa(unsigned int new)
{
	int	size;

	size = 0;
	while (new >= 16)
	{
		new = new / 16;
		size++;
	}
	size++;
	return (size);
}

static char	*fill_tab_hexa(char *str, unsigned int new, unsigned int i)
{
	str[i--] = '\0';
	while (new != 0)
	{
		str[i] = "0123456789abcdef"[new % 16];
		new = new / 16;
		i--;
	}
	return (str);
}

char	*ft_itoa_hexa(unsigned int n)
{
	unsigned int	i;
	unsigned int	new;
	char			*str;

	new = n;
	i = get_size_hexa(new);
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (0);
	if (n == 0)
		str[0] = '0';
	return (fill_tab_hexa(str, new, i));
}
