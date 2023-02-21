/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:16:46 by mmorue            #+#    #+#             */
/*   Updated: 2023/02/21 18:41:43 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_listpf
{
	void			*content;
	int				size;
	struct s_listpf	*next;
}	t_listpf;

t_listpf	*ft_lstnew_pf(void *content);
void		ft_lstadd_back_pf(t_listpf **lst, t_listpf *new);
t_listpf	*ft_lstlast_pf(t_listpf *lst);
int			ft_lstsize_pf(t_listpf *lst);
char		*ft_itoa_hexa_maj(unsigned int n);
char		*ft_itoa_hexa(unsigned int n);
char		*ft_itoa_u(unsigned int n);
int			ft_printf(const char *fmt, ...);
int			ft_test(const char *ftm, t_listpf **start, va_list arg, int *error);
int			ft_pars(char ftm, t_listpf **start, va_list arg, int *error);
int			ft_char(char c, t_listpf **start, int *error);
int			ft_string(char *str, t_listpf **start, int *error);
int			ft_x_maj(unsigned int i, t_listpf **start, int *error);
int			ft_x(unsigned int i, t_listpf **start, int *error);
int			ft_u(unsigned int i, t_listpf **start, int *error);
int			ft_di(int i, t_listpf **start, int *error);
int			ft_p(void *p, t_listpf **start, int *error);
void		ft_lstdelone_pf(t_listpf *lst);
void		ft_lstclear_pf(t_listpf **lst);
char		*ft_itoa_address(unsigned long n);
#endif