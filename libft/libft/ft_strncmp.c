/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:28:26 by yeonkim           #+#    #+#             */
/*   Updated: 2020/10/12 14:28:26 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	size_t				i;

	if (n == 0)
		return (0);
	ptr1 = (const unsigned char	*)s1;
	ptr2 = (const unsigned char	*)s2;
	i = 0;
	while (i < n)
	{
		if (!ptr1[i] || !ptr2[i])
			break ;
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (ptr1[i] - ptr2[i]);
}
