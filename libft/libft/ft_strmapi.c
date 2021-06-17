/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:28:25 by yeonkim           #+#    #+#             */
/*   Updated: 2020/10/12 14:28:25 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(ptr = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = f((unsigned int)i, s[i]);
		i++;
	}
	return (ptr);
}
