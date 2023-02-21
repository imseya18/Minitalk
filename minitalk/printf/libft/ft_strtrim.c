/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:40:53 by mmorue            #+#    #+#             */
/*   Updated: 2022/11/09 17:29:39 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	compar(char c, char const *set)
{	
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	get_size_end(char const *s1, char const *set, int len)
{
	while (len >= 0 && compar(s1[len], set) == 1)
		len--;
	return (len + 1);
}

static int	get_size_start(char const *s1, char const *set, int len)
{
	int	size;

	size = 0;
	while (s1[len] != '\0' && compar(s1[len], set) == 1)
	{
		size++;
		len++;
	}
	return (size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*str;

	i = 0;
	if (s1 == 0 || set == 0)
		return (0);
	start = get_size_start(s1, set, 0);
	end = get_size_end(s1, set, ft_strlen(s1) - 1);
	if (end - start <= 0)
		return (ft_strdup(""));
	str = malloc((end - start + 1) * sizeof(char));
	if (!str)
		return (0);
	while (start < end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

//int main()
//{
//	char s1[] = "aaaabaasalutaaaba";
//	char set[] = "ab";
//
//	//printf()
//	printf("%s\n",ft_strtrim(s1, set));
//
//}//