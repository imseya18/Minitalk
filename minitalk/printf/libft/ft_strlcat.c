/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:34:56 by mmorue            #+#    #+#             */
/*   Updated: 2022/11/09 17:59:23 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;
	size_t	j;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	k = ft_strlen(dst);
	j = k;
	if (dstsize <= j)
		return (dstsize + ft_strlen(src));
	while (src[i] != '\0' && (dstsize - k - 1) > i)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (k + ft_strlen(src));
}
