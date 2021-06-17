/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 21:53:28 by yeonkim           #+#    #+#             */
/*   Updated: 2021/03/10 21:18:51 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	convert_to_hex(unsigned int n)
{
	if (n < 10)
		return (n + '0');
	return (n - 10 + 'a');
}

char	*ft_ptoa(long long ptr, int precision)
{
	char	*res;
	int		i;

	res = ft_calloc(precision + 3, sizeof(char));
	ft_strlcpy(res, "0x", 3);
	i = precision + 1;
	while (i > 1)
	{
		res[i--] = convert_to_hex(ptr % 16);
		ptr /= 16;
	}
	return (res);
}
