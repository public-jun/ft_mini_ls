/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:38:10 by jnakahod          #+#    #+#             */
/*   Updated: 2020/12/04 20:40:28 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

static	t_info		*new_info(const char *file_path, const char *name)
{
	t_info			*info;

	info = malloc(sizeof(t_info));
	if (info == NULL)
		return (NULL);
	info->name = ft_strdup(name);
	if (lstat(file_path, &info->stat) != 0)
	{
		perror("lstat in new_info\n");
		free(info->name);
		free(info);
		return (NULL);
	}
	return (info);
}

void				make_file_path(const char *base_path, struct dirent *dent,
									char **file_path)
{
	char			*file_path_tmp;

	file_path_tmp = NULL;
	file_path_tmp = ft_strjoin(base_path, dent->d_name);
	free_set(file_path, file_path_tmp);
}

static	void		add_info(t_info_list *list, t_info *info)
{
	list->array[list->used] = info;
	list->used++;
	if (list->used == list->size)
		list->array[list->used] = NULL;
}

void				ls_print(t_info_list *list, int size)
{
	int				i;

	i = 1;
	while (i <= size)
	{
		if (list->array[size - i]->name[0] != '.')
		{
			write(1, list->array[size - i]->name,
					sizeof(char) * ft_strlen(list->array[size - i]->name));
			write(1, "\n", 1);
		}
		i++;
	}
}

int					list_dir(const char *base_path, t_info_list *info_list,
							int size)
{
	DIR				*dir;
	struct dirent	*dent;
	char			*file_path;
	t_info			*info;

	dir = opendir(base_path);
	if (dir == NULL)
	{
		perror(base_path);
		return (1);
	}
	file_path = ft_strjoin(NULL, NULL);
	while ((dent = readdir(dir)) != NULL)
	{
		make_file_path(base_path, dent, &file_path);
		info = new_info(file_path, dent->d_name);
		add_info(info_list, info);
	}
	compare_list(info_list);
	ls_print(info_list, size);
	closedir(dir);
	free_info_list(info_list, &file_path);
	return (0);
}
