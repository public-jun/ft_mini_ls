/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 19:43:10 by jnakahod          #+#    #+#             */
/*   Updated: 2020/12/04 20:21:34 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

void			free_set(char **dst, char *src)
{
	free(*dst);
	*dst = src;
}

void			free_info_list(t_info_list *list, char **path)
{
	int			i;

	free_set(path, NULL);
	i = 0;
	while (i < list->used)
	{
		free(list->array[i]->name);
		free(list->array[i]);
		i++;
	}
	free(list->array);
}
