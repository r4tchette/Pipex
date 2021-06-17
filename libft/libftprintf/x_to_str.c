/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_to_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:09:26 by yeonkim           #+#    #+#             */
/*   Updated: 2021/03/10 21:52:06 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	x_to_str(t_format format, va_list *ap)
{
	unsigned int	num;
	char			*res;
	char			pad;
	int				dir;

	num = va_arg(*ap, unsigned int);
	if (format.precision < 0)
	{
		format.flag['.'] = 0;
		format.precision = 0;
	}
	res = (!num && format.flag['.']) \
			? ft_calloc(1, sizeof(char)) : ft_xtoa(num, format.type);
	if (format.precision > (int)ft_strlen(res))
		pad_char(&res, '0', format.precision - ft_strlen(res), 1);
	if (format.width > (int)ft_strlen(res))
	{
		pad = (format.flag['0'] && !format.flag['-'] && !format.flag['.'] \
				? '0' : ' ');
		dir = (format.flag['-'] ? -1 : 1);
		pad_char(&res, pad, format.width - ft_strlen(res), dir);
	}
	if (format.flag[' '] == 1 && is_num(res[0]))
		pad_char(&res, ' ', 1, 1);
	return (print_buf(&res));
}
