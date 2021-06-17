/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_to_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:19:34 by yeonkim           #+#    #+#             */
/*   Updated: 2021/03/10 21:19:35 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	n_to_str(va_list *ap, int len)
{
	int	*ptr;

	ptr = va_arg(*ap, int *);
	if (ptr)
		*ptr = len;
	return (0);
}
