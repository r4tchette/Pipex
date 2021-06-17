/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 20:09:24 by yeonkim           #+#    #+#             */
/*   Updated: 2021/03/10 21:50:46 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	get_precision(t_format *format, int *idx, char *str, va_list *ap)
{
	int	precision;
	int	i;

	precision = 0;
	i = *idx;
	if (str[i] == '*')
	{
		precision = (int)va_arg(*ap, int);
		i++;
	}
	else if (is_num(str[i]))
		while (is_num(str[i]) && str[i])
		{
			precision *= 10;
			precision += str[i] - '0';
			i++;
		}
	else
		return (0);
	format->precision = precision;
	*idx = i;
	return (1);
}
