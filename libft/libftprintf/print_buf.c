/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_buf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 20:09:24 by yeonkim           #+#    #+#             */
/*   Updated: 2021/03/10 21:09:30 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_buf(char **buf)
{
	int	len;

	len = ft_strlen(*buf);
	write(1, *buf, len);
	free(*buf);
	return (len);
}

int	print_char_with_zero(char **buf, t_format format)
{
	int	len;

	len = ft_strlen(*buf);
	if (format.flag['-'])
	{
		write(1, "\0", 1);
		write(1, *buf, len);
	}
	else
	{
		write(1, *buf, len);
		write(1, "\0", 1);
	}
	free(*buf);
	return (len + 1);
}
