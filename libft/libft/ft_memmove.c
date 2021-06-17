/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:28:07 by yeonkim           #+#    #+#             */
/*   Updated: 2020/10/12 14:28:07 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ptr1;
	const unsigned char	*ptr2;
	size_t				i;

	ptr1 = dst;
	ptr2 = src;
	if (ptr1 > ptr2)
	{
		i = len - 1;
		while ((int)i >= 0)
		{
			ptr1[i] = ptr2[i];
			i--;
		}
	}
	else if (ptr1 < ptr2)
	{
		i = 0;
		while (i < len)
		{
			ptr1[i] = ptr2[i];
			i++;
		}
	}
	return (dst);
}
