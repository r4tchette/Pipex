/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:27:44 by yeonkim           #+#    #+#             */
/*   Updated: 2021/03/10 21:10:57 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	int_len(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		n /= -10;
		len += 2;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*ptr;
	size_t	ptr_len;

	ptr_len = int_len(n);
	if (!(ptr = (char *)ft_calloc(ptr_len + 1, sizeof(char))))
		return (NULL);
	if (n == 0)
		ptr[0] = '0';
	if (n < 0)
	{
		ptr[0] = '-';
		ptr[--ptr_len] = -(n % 10) + '0';
		n /= -10;
	}
	while (n > 0)
	{
		ptr[--ptr_len] = n % 10 + '0';
		n /= 10;
	}
	return (ptr);
}

static size_t	ll_len(long long n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		n /= -10;
		len += 2;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_ltoa(long long n)
{
	char	*ptr;
	size_t	ptr_len;

	ptr_len = ll_len(n);
	if (!(ptr = (char *)ft_calloc(ptr_len + 1, sizeof(char))))
		return (NULL);
	if (n == 0)
		ptr[0] = '0';
	if (n < 0)
	{
		ptr[0] = '-';
		ptr[--ptr_len] = -(n % 10) + '0';
		n /= -10;
	}
	while (n > 0)
	{
		ptr[--ptr_len] = n % 10 + '0';
		n /= 10;
	}
	return (ptr);
}
