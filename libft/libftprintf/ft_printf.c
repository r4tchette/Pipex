/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 13:44:30 by yeonkim           #+#    #+#             */
/*   Updated: 2021/03/11 11:10:44 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	init_format(t_format *format)
{
	format->flag['-'] = 0;
	format->flag['+'] = 0;
	format->flag[' '] = 0;
	format->flag['0'] = 0;
	format->flag['#'] = 0;
	format->flag['.'] = 0;
	format->flag['l'] = 0;
	format->flag['L'] = 0;
	format->flag['h'] = 0;
	format->flag['H'] = 0;
	format->width = 0;
	format->precision = 0;
	format->type = 0;
}

static int	to_str(t_format format, va_list *ap, int len)
{
	if (format.type == '%')
		return (a_to_str(format));
	else if (format.type == 'c')
		return (c_to_str(format, ap));
	else if (format.type == 's')
		return (s_to_str(format, ap));
	else if (format.type == 'p')
		return (p_to_str(format, ap));
	else if (format.type == 'd' || format.type == 'i')
		return (d_to_str(format, ap));
	else if (format.type == 'u')
		return (u_to_str(format, ap));
	else if (format.type == 'x' || format.type == 'X')
		return (x_to_str(format, ap));
	else if (format.type == 'f')
		return (f_to_str(format, ap));
	else if (format.type == 'n')
		return (n_to_str(ap, len));
	return (-1);
}

static int	print_format(char *str, va_list *ap, int len)
{
	t_format	format;
	int			i;

	init_format(&format);
	i = 0;
	while (str[i])
	{
		if (is_type(str[i]))
		{
			format.type = str[i];
			return (to_str(format, ap, len));
		}
		else if (is_flag(str[i]) && !format.flag['.'])
			format.flag[(int)str[i++]] += 1;
		else if (is_num(str[i]) || str[i] == '*')
		{
			if (format.flag['.'] == 0)
				get_width(&format, &i, str, ap);
			else
				get_precision(&format, &i, str, ap);
		}
		else
			return (0);
	}
	return (0);
}

int			ft_printf(char *str, ...)
{
	va_list	ap;
	int		i;
	int		len;
	int		ret;

	va_start(ap, str);
	len = 0;
	i = -1;
	while (str[++i])
		if (str[i] == '%')
		{
			ret = print_format(&str[i + 1], &ap, len);
			if (ret < 0)
				return (-1);
			len += ret;
			while (!is_type(str[i + 1]))
				i++;
			i++;
		}
		else
		{
			write(1, str + i, 1);
			len++;
		}
	return (len);
}
