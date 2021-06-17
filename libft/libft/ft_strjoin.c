/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:28:21 by yeonkim           #+#    #+#             */
/*   Updated: 2021/03/10 21:10:55 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	ptr_size;

	if (!s1 || !s2)
	{
		if (s1)
			return (ft_strdup(s1));
		if (s2)
			return (ft_strdup(s2));
		return (NULL);
	}
	ptr_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(ptr = (char *)ft_calloc(ptr_size, sizeof(char))))
		return (NULL);
	ft_strlcpy(ptr, s1, ptr_size);
	ft_strlcat(ptr, s2, ptr_size);
	return (ptr);
}
