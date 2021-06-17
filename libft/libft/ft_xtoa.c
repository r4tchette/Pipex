/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:27:44 by yeonkim           #+#    #+#             */
/*   Updated: 2021/03/10 21:10:50 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	x_len(unsigned int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static char		convert_to_hex(unsigned int n, char c)
{
	if (n < 10)
		return (n + '0');
	if (c == 'x')
		return (n - 10 + 'a');
	return (n - 10 + 'A');
}

char			*ft_xtoa(unsigned int n, char c)
{
	char	*ptr;
	size_t	ptr_len;

	ptr_len = x_len(n);
	if (!(ptr = (char *)ft_calloc(ptr_len + 1, sizeof(char))))
		return (NULL);
	if (n == 0)
		ptr[0] = '0';
	while (n > 0)
	{
		ptr[--ptr_len] = convert_to_hex(n % 16, c);
		n /= 16;
	}
	return (ptr);
}
