/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 20:09:24 by yeonkim           #+#    #+#             */
/*   Updated: 2021/03/11 11:10:52 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct	s_format
{
	char	flag[128];
	int		width;
	int		precision;
	char	length;
	char	type;
}				t_format;

int				is_num(char c);
int				is_flag(char c);
int				is_type(char c);
int				get_precision(t_format *format, int *idx, char *str, \
								va_list *ap);
int				get_width(t_format *format, int *idx, char *str, va_list *ap);
int				pad_char(char **res, char c, int len, int dir);
int				print_buf(char **buf);
int				print_char_with_zero(char **buf, t_format format);
int				a_to_str(t_format format);
int				c_to_str(t_format format, va_list *ap);
int				d_to_str(t_format format, va_list *ap);
int				f_to_str(t_format format, va_list *ap);
int				n_to_str(va_list *ap, int len);
int				p_to_str(t_format format, va_list *ap);
int				s_to_str(t_format format, va_list *ap);
int				u_to_str(t_format format, va_list *ap);
int				x_to_str(t_format format, va_list *ap);
int				ft_printf(char *str, ...);

#endif
