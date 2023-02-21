/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:39:15 by mmorue            #+#    #+#             */
/*   Updated: 2022/11/22 16:26:12 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_listpf	*ft_lstnew_pf(void *content)
{
	t_listpf	*new;

	new = malloc(sizeof(t_listpf));
	if (!new)
		return (0);
	new->content = content;
	new->next = NULL;
	new->size = 0;
	return (new);
}

void	ft_lstadd_back_pf(t_listpf **lst, t_listpf *new)
{
	t_listpf	*temp;

	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast_pf(*lst);
	temp->next = new;
}

t_listpf	*ft_lstlast_pf(t_listpf *lst)
{
	int		i;
	int		size;

	i = 0;
	size = ft_lstsize_pf(lst);
	while (i < size - 1)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}

int	ft_lstsize_pf(t_listpf *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}	
	return (i);
}

void	ft_lstdelone_pf(t_listpf *lst)
{
	if (lst == 0)
		return ;
	if (lst->content != 0)
		free(lst->content);
	free(lst);
}
