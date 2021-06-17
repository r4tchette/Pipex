/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_to_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:20:11 by yeonkim           #+#    #+#             */
/*   Updated: 2021/03/10 21:50:00 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ptr_len(long long ptr)
{
	int	len;

	len = 0;
	while (ptr > 0)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}

int			p_to_str(t_format format, va_list *ap)
{
	long long	ptr;
	char		*res;
	char		pad;
	int			dir;

	ptr = va_arg(*ap, long long);
	format.precision = (format.precision < ptr_len(ptr)) \
						? ptr_len(ptr) : format.precision;
	if (!format.flag['.'] && !ptr)
		format.precision = 1;
	res = ft_ptoa(ptr, format.precision);
	if (format.flag['.'] && format.precision <= 0)
		res[2] = 0;
	if (format.width > (int)ft_strlen(res))
	{
		pad = (format.flag['0'] && !format.flag['-'] ? '0' : ' ');
		dir = (format.flag['-'] ? -1 : 1);
		pad_char(&res, pad, format.width - ft_strlen(res), dir);
	}
	return (print_buf(&res));
}
