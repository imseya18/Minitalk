/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:09:23 by mmorue            #+#    #+#             */
/*   Updated: 2022/12/08 13:04:36 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_tab_f(t_listpf *start, char *tab)
{	
	int		i;
	int		j;
	char	*temp;

	j = 0;
	while (start->next != NULL)
	{
		i = 0;
		temp = start->content;
		while (i < start->size)
			tab[j++] = temp[i++];
		start = start->next;
	}
	temp = start->content;
	i = 0;
	while (i < start->size)
		tab[j++] = temp[i++];
	tab[j] = '\0';
}

int	ft_tab(t_listpf *start, int size)
{
	char	*tab;
	int		sz;

	tab = malloc((size + 1 * sizeof(char)));
	if (!tab)
		return (-1);
	ft_fill_tab_f(start, tab);
	sz = write(1, tab, size);
	free(tab);
	if (sz == -1)
		return (sz);
	return (0);
}

int	ft_pars(char ftm, t_listpf **start, va_list arg, int *error)
{	
	int	size;

	size = 0;
	if (ftm == 'c')
		size = ft_char(va_arg(arg, int), start, error);
	else if (ftm == 's')
		size = ft_string(va_arg(arg, char *), start, error);
	else if (ftm == 'p')
		size = ft_p(va_arg(arg, void *), start, error);
	else if (ftm == 'd')
		size = ft_di(va_arg(arg, int), start, error);
	else if (ftm == 'i')
		size = ft_di(va_arg(arg, int), start, error);
	else if (ftm == 'u')
		size = ft_u(va_arg(arg, unsigned int), start, error);
	else if (ftm == 'x')
		size = ft_x(va_arg(arg, unsigned int), start, error);
	else if (ftm == 'X')
		size = ft_x_maj(va_arg(arg, unsigned int), start, error);
	else if (ftm == '%')
		size = ft_char(ftm, start, error);
	return (size);
}

int	ft_test(const char *ftm, t_listpf **start, va_list arg, int *error)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (ftm[i] && *error == 0)
	{
		if (ftm[i] == '%')
		{
			size = size + ft_pars(ftm[i + 1], start, arg, error);
			i++;
		}
		else
			size = size + ft_char(ftm[i], start, error);
		i++;
	}
	return (size);
}

int	ft_printf(const char *fmt, ...)
{
	t_listpf	*start;
	va_list		arg;
	int			size;
	int			error;
	int			check;

	error = 0;
	start = 0;
	check = 0;
	if (fmt[0] == '\0')
		return (0);
	va_start(arg, fmt);
	size = ft_test(fmt, &start, arg, &error);
	if (error == 1)
		size = -1;
	else
		check = ft_tab(start, size);
	if (check == -1)
		size = -1;
	va_end(arg);
	ft_lstclear_pf(&start);
	return (size);
}
