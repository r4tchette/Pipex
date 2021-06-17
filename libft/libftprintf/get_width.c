/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 20:09:24 by yeonkim           #+#    #+#             */
/*   Updated: 2021/03/10 21:49:23 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	get_width(t_format *format, int *idx, char *str, va_list *ap)
{
	int	width;
	int	i;

	width = 0;
	i = (*idx);
	if (str[i] == '*')
	{
		width = (int)va_arg(*ap, int);
		if (width < 0)
		{
			width *= -1;
			format->flag['-'] = 1;
		}
		i++;
	}
	else if (is_num(str[i]))
		while (is_num(str[i]))
			width = 10 * width + (str[i++] - '0');
	else
		return (0);
	format->width = width;
	*idx = i;
	return (1);
}
