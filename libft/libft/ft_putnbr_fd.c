/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:28:12 by yeonkim           #+#    #+#             */
/*   Updated: 2020/10/12 14:28:12 by yeonkim          ###   ########.fr       */
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

void			ft_putnbr_fd(int n, int fd)
{
	char	ptr[11];
	size_t	ptr_len;
	size_t	idx;

	ptr_len = int_len(n);
	idx = ptr_len;
	if (n == 0)
		ptr[0] = '0';
	if (n < 0)
	{
		ptr[0] = '-';
		ptr[--idx] = -(n % 10) + '0';
		n /= -10;
	}
	while (n > 0)
	{
		ptr[--idx] = n % 10 + '0';
		n /= 10;
	}
	write(fd, ptr, ptr_len);
}
