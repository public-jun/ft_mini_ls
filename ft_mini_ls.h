/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:38:29 by jnakahod          #+#    #+#             */
/*   Updated: 2020/12/04 20:39:44 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_LS_H
# define FT_MINI_LS_H

# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdio.h>
# include <string.h>

typedef struct		s_info
{
	char			*name;
	struct stat		stat;
}					t_info;

typedef struct		s_info_list
{
	t_info			**array;
	int				size;
	int				used;
}					t_info_list;

size_t				ft_strlen(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s1);
void				compare_list(t_info_list *list);
void				free_set(char **dst, char *src);
void				free_info_list(t_info_list *list, char **path);
int					list_dir(const char *base_path, t_info_list *info_list,
							int size);

#endif
