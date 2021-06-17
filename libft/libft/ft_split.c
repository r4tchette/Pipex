/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:28:18 by yeonkim           #+#    #+#             */
/*   Updated: 2020/10/16 19:11:29 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**free_words(char **ret)
{
	size_t	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		ret[i] = NULL;
		i++;
	}
	free(ret);
	ret = NULL;
	return (NULL);
}

static char		*duplicate_word(const char *s, char c)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	len = 0;
	while (s[len] != 0 && s[len] != c)
		len++;
	if (!(ptr = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	return (ptr);
}

static char		**split_words(char **ret, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			if (!(ret[j++] = duplicate_word(&s[i], c)))
				return (free_words(ret));
		while (s[i] != c && s[i])
			i++;
	}
	return (ret);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			cnt++;
		while (s[i] != c && s[i])
			i++;
	}
	return (cnt);
}

char			**ft_split(char const *s, char c)
{
	char	**ret;

	if (!s)
		return (NULL);
	if (!(ret = ft_calloc(count_words(s, c) + 1, sizeof(char *))))
		return (NULL);
	if (!(ret = split_words(ret, s, c)))
		return (NULL);
	return (ret);
}
