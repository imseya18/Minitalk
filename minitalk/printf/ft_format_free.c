/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:15:09 by mmorue            #+#    #+#             */
/*   Updated: 2022/11/22 16:26:17 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_di(int i, t_listpf **start, int *error)
{
	t_listpf	*new;
	char		*str;

	str = ft_itoa(i);
	if (str == NULL)
	{
		*error = 1;
		return (0);
	}
	new = ft_lstnew_pf(str);
	if (new == NULL)
	{
		free(str);
		*error = 1;
		return (0);
	}
	ft_lstadd_back_pf(start, new);
	new->size = ft_strlen(str);
	return (ft_strlen(str));
}

int	ft_p(void *p, t_listpf **start, int *error)
{
	t_listpf			*new;
	char				*str;
	unsigned long		i;

	i = (unsigned long)p;
	str = ft_itoa_address(i);
	if (str == NULL)
	{
		*error = 1;
		return (0);
	}
	new = ft_lstnew_pf(str);
	if (new == NULL)
	{
		free(str);
		*error = 1;
		return (0);
	}
	ft_lstadd_back_pf(start, new);
	new->size = ft_strlen(str);
	return (ft_strlen(str));
}
