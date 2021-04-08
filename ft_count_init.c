/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 19:18:28 by jnakahod          #+#    #+#             */
/*   Updated: 2020/12/04 19:29:48 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

int					count_file(char *path)
{
	int				n;
	struct dirent	*dent;
	struct stat		st;
	DIR				*dir;

	n = 0;
	dir = opendir(path);
	while ((dent = readdir(dir)) != NULL)
	{
		if (lstat(dent->d_name, &st) == 0)
			n++;
	}
	closedir(dir);
	return (n);
}

void				init_info_list(t_info_list *list, int size)
{
	list->array = malloc(sizeof(t_info*) * (size + 1));
	if (list->array == NULL)
	{
		perror("error in init_info_list\n");
	}
	list->size = size;
	list->used = 0;
}
