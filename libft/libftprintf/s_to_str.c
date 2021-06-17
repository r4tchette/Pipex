/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_to_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:20:18 by yeonkim           #+#    #+#             */
/*   Updated: 2021/03/10 21:20:18 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	s_to_str(t_format format, va_list *ap)
{
	char	*str;
	char	*res;
	int		dir;
	char	pad;

	str = va_arg(*ap, char *);
	res = !str ? ft_strdup("(null)") : ft_strdup(str);
	pad = ' ';
	if (format.precision < 0)
		format.flag['.'] = 0;
	if (format.flag['.'] && format.precision < (int)ft_strlen(res))
		res[format.precision] = 0;
	if (format.width > (int)ft_strlen(res))
	{
		dir = (format.flag['-'] ? -1 : 1);
		pad = (format.flag['0'] && !format.flag['-'] ? '0' : pad);
		pad_char(&res, pad, format.width - ft_strlen(res), dir);
	}
	return (print_buf(&res));
}
