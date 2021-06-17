/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:27:44 by yeonkim           #+#    #+#             */
/*   Updated: 2021/03/10 21:10:48 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	u_len(unsigned int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_utoa(unsigned int n)
{
	char	*ptr;
	size_t	ptr_len;

	ptr_len = u_len(n);
	if (!(ptr = (char *)ft_calloc(ptr_len + 1, sizeof(char))))
		return (NULL);
	if (n == 0)
		ptr[0] = '0';
	while (n > 0)
	{
		ptr[--ptr_len] = n % 10 + '0';
		n /= 10;
	}
	return (ptr);
}
