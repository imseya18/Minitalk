/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:10:30 by mmorue            #+#    #+#             */
/*   Updated: 2022/11/07 14:36:56 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	k;
	unsigned int	i;

	i = 0;
	k = 0;
	while (src[k] != '\0')
	{
		k++;
	}
	if (size != 0)
	{
		while (src[i] != '\0' && (i < size -1))
		{
			dest[i] = src[i];
			i++;
		}
	dest[i] = '\0';
	}
	return (k);
}
