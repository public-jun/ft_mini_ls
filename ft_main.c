/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:24:56 by jnakahod          #+#    #+#             */
/*   Updated: 2020/12/09 10:32:34 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

static	int			count_file(char *path)
{
	int				n;
	struct dirent	*dent;
	struct stat		st;
	DIR				*dir;

	n = 0;
	dir = opendir(path);
	if (dir == NULL)
	{
		perror(path);
		return (-1);
	}
	while ((dent = readdir(dir)) != NULL)
	{
		if (lstat(dent->d_name, &st) == 0)
			n++;
	}
	closedir(dir);
	return (n);
}

static	void		init_info_list(t_info_list *list, int size)
{
	list->array = malloc(sizeof(t_info*) * (size + 1));
	if (list->array == NULL)
	{
		perror("error in init_info_list\n");
	}
	list->size = size;
	list->used = 0;
}

int					main(int argc, char **argv)
{
	char			*path;
	int				file_size;
	t_info_list		info_list;

	if (argc > 1)
	{
		write(1, "error\n", 6);
		return (1);
	}
	argv = NULL;
	path = "./";
	file_size = count_file(path);
	if (file_size < 0)
		return (1);
	init_info_list(&info_list, file_size);
	return (list_dir(path, &info_list, file_size));
}
