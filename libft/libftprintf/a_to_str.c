/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:08:45 by yeonkim           #+#    #+#             */
/*   Updated: 2021/03/10 21:09:38 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	a_to_str(t_format format)
{
	char	*res;
	char	pad;
	int		dir;

	if (!(res = ft_strdup("%")))
		return (0);
	if (format.width < 0)
	{
		format.flag['-'] = 1;
		format.width *= -1;
	}
	if (format.width > 1)
	{
		pad = (format.flag['0'] && !format.flag['-']) ? '0' : ' ';
		dir = format.flag['-'] ? -1 : 1;
		pad_char(&res, pad, format.width - 1, dir);
	}
	return (print_buf(&res));
}
