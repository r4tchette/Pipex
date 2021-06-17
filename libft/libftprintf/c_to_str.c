/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_to_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:08:48 by yeonkim           #+#    #+#             */
/*   Updated: 2021/03/10 21:09:38 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	c_to_str(t_format format, va_list *ap)
{
	char	*res;
	char	pad;
	int		dir;
	int		is_zero;

	if (!(res = ft_calloc(2, sizeof(char))))
		return (0);
	res[0] = (char)va_arg(*ap, int);
	is_zero = (res[0] == 0) ? 1 : 0;
	if (format.width < 0)
	{
		format.flag['-'] = 1;
		format.width *= -1;
	}
	if (format.width > 1)
	{
		pad = format.flag['0'] ? '0' : ' ';
		dir = format.flag['-'] ? -1 : 1;
		pad_char(&res, pad, format.width - 1, dir);
	}
	if (is_zero)
		return (print_char_with_zero(&res, format));
	return (print_buf(&res));
}
