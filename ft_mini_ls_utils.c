/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 19:05:05 by jnakahod          #+#    #+#             */
/*   Updated: 2020/12/04 20:31:16 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

size_t				ft_strlen(const char *s)
{
	size_t			i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			i;

	if (!dst || !src)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char				*ft_strdup(const char *s1)
{
	char			*ptr;
	size_t			dstsize;

	dstsize = ((ft_strlen(s1) + 1) * sizeof(char));
	if (!(ptr = malloc(dstsize)))
		return (NULL);
	ft_strlcpy(ptr, s1, dstsize);
	return (ptr);
}

static	char		*make_ans(size_t len_s1, size_t len_s2,
					char const *s1, char const *s2)
{
	char			*ans;
	int				i;
	int				j;

	i = 0;
	if (!(ans = malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	j = 0;
	if (s1)
	{
		while (s1[j])
			ans[i++] = s1[j++];
	}
	j = 0;
	if (s2)
	{
		while (s2[j])
			ans[i++] = s2[j++];
	}
	ans[i] = '\0';
	return (ans);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	char			*ans;
	size_t			len_s1;
	size_t			len_s2;

	if (!s1 && !s2)
	{
		if (!(ans = malloc(1)))
			return (NULL);
		*ans = '\0';
		return (ans);
	}
	else if (!s1)
	{
		len_s2 = ft_strlen(s2);
		return (make_ans(0, len_s2, s1, s2));
	}
	else if (!s2)
	{
		len_s1 = ft_strlen(s1);
		return (make_ans(len_s1, 0, s1, s2));
	}
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	return (make_ans(len_s1, len_s2, s1, s2));
}
