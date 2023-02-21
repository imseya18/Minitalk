/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:51:40 by mmorue            #+#    #+#             */
/*   Updated: 2022/11/10 16:03:41 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	compar(const char *haystack, const char *needle)
{
	size_t	i;

	i = 0;
	while (needle[i] != '\0')
	{
		if (haystack[i] != needle[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char	*haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (0);
	while (haystack[i] != '\0' && i + size <= len)
	{
		if (haystack[i] == needle[0])
		{
			if (compar(&haystack[i], needle) == 1)
				return ((char *)&haystack[i]);
		}
	i++;
	}
	return (0);
}

//int	main(void)
//{
//	const char	haystack[] = "MZIRIBMZE";
//	const char	needle[] = "MZIRIBMZE";
//	size_t		len = 0;
//	printf("%s\n", ft_strnstr(haystack, needle, len));
//	printf("%s", strnstr(haystack, needle, len));
//}