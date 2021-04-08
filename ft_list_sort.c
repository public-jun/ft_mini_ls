/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 19:38:59 by jnakahod          #+#    #+#             */
/*   Updated: 2020/12/08 10:23:43 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

static void			sort_list(t_info_list *list, int s, int t)
{
	t_info			*tmp;

	tmp = list->array[s];
	list->array[s] = list->array[t];
	list->array[t] = tmp;
}

static int			ft_strcmp(char *s, char *t)
{
	int				i;

	i = 0;
	while (s[i] != '\0' || t[i] != '\0')
	{
		if (s[i] != t[i])
			return (s[i] - t[i]);
		i++;
	}
	return (s[i] - t[i]);
}

static void			if_conditions(t_info_list *list, int s, int t)
{
	if (list->array[s]->stat.st_mtimespec.tv_sec <
			list->array[t]->stat.st_mtimespec.tv_sec)
		sort_list(list, s, t);
	else if ((list->array[s]->stat.st_mtimespec.tv_sec ==
				list->array[t]->stat.st_mtimespec.tv_sec) &&
			(list->array[s]->stat.st_mtimespec.tv_nsec <
				list->array[t]->stat.st_mtimespec.tv_nsec))
		sort_list(list, s, t);
	else if ((list->array[s]->stat.st_mtimespec.tv_sec ==
				list->array[t]->stat.st_mtimespec.tv_sec) &&
			(list->array[s]->stat.st_mtimespec.tv_nsec ==
				list->array[t]->stat.st_mtimespec.tv_nsec) &&
			(ft_strcmp(list->array[s]->name, list->array[t]->name) > 0))
		sort_list(list, s, t);
}

void				compare_list(t_info_list *list)
{
	int				s;
	int				t;

	s = 0;
	while (s < (list->size) - 1)
	{
		t = s + 1;
		while (t < list->size)
		{
			if_conditions(list, s, t);
			t++;
		}
		s++;
	}
}
