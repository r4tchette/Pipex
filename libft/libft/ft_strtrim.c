/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:28:31 by yeonkim           #+#    #+#             */
/*   Updated: 2020/10/12 14:28:31 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && isset(s1[i], set))
		i++;
	while (j >= i && isset(s1[j], set))
		j--;
	if (i >= j)
		return (ft_strdup(""));
	if (!(ptr = (char *)ft_calloc(j - i + 2, sizeof(char))))
		return (NULL);
	ft_strlcpy(ptr, &s1[i], j - i + 2);
	return (ptr);
}
