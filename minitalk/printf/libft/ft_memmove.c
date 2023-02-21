/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:20:26 by mmorue            #+#    #+#             */
/*   Updated: 2022/11/07 14:37:09 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dest;
	char		*sorc;

	dest = (char *)dst;
	sorc = (char *)src;
	i = -1;
	if (dst == 0 & src == 0)
		return (dst);
	if (dest > sorc)
	{
		while (len-- > 0)
			dest[len] = sorc[len];
	}
	else
	{
		while (++i < len)
			dest[i] = sorc[i];
	}
	return (dst);
}
