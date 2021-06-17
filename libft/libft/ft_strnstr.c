/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:28:27 by yeonkim           #+#    #+#             */
/*   Updated: 2020/10/12 14:28:27 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr;
	size_t	needle_len;

	if (*needle == 0)
		return ((char *)haystack);
	ptr = (char *)haystack;
	needle_len = ft_strlen(needle);
	while (*ptr && len-- >= needle_len)
	{
		if (*ptr == needle[0])
			if (!ft_strncmp(ptr, needle, needle_len))
				return (ptr);
		ptr++;
	}
	return (NULL);
}
