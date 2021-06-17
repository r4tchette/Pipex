/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:28:30 by yeonkim           #+#    #+#             */
/*   Updated: 2020/10/12 14:28:30 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	ptr_size;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	ptr_size = ft_strlen(s) - start;
	if (ptr_size > len)
		ptr_size = len;
	if (!(ptr = (char *)ft_calloc(ptr_size + 1, sizeof(char))))
		return (NULL);
	i = 0;
	while (i < ptr_size)
	{
		ptr[i] = s[start + i];
		i++;
	}
	return (ptr);
}
