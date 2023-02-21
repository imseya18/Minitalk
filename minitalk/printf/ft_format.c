/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:08:09 by mmorue            #+#    #+#             */
/*   Updated: 2022/11/22 16:26:18 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(char c, t_listpf **start, int *error)
{
	t_listpf	*new;
	char		str[2];
	char		*strn;

	str[0] = c;
	str[1] = '\0';
	strn = ft_strdup(str);
	if (strn == NULL)
	{
		*error = 1;
		return (0);
	}
	new = ft_lstnew_pf(strn);
	if (new == NULL)
	{
		free(strn);
		*error = 1;
		return (0);
	}
	new->size = 1;
	ft_lstadd_back_pf(start, new);
	return (1);
}

int	ft_string(char *str, t_listpf **start, int *error)
{
	t_listpf	*new;
	char		*strn;

	if (str == NULL)
		strn = ft_strdup("(null)");
	else
		strn = ft_strdup(str);
	if (strn == NULL)
	{
		*error = 1;
		return (0);
	}
	new = ft_lstnew_pf(strn);
	if (new == NULL)
	{
		free(strn);
		*error = 1;
		return (0);
	}
	ft_lstadd_back_pf(start, new);
	new->size = ft_strlen(strn);
	return (ft_strlen(strn));
}

int	ft_x_maj(unsigned int i, t_listpf **start, int *error)
{
	t_listpf	*new;
	char		*str;

	str = ft_itoa_hexa_maj(i);
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

int	ft_x(unsigned int i, t_listpf **start, int *error)
{
	t_listpf	*new;
	char		*str;

	str = ft_itoa_hexa(i);
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

int	ft_u(unsigned int i, t_listpf **start, int *error)
{
	t_listpf	*new;
	char		*str;

	str = ft_itoa_u(i);
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
