/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 20:09:24 by yeonkim           #+#    #+#             */
/*   Updated: 2021/03/10 21:09:31 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pad_char(char **res, char c, int len, int dir)
{
	char	*tmp;
	char	*pad;
	int		i;

	if (!(*res))
		return (0);
	if (!(pad = ft_calloc(len + 1, sizeof(char))))
		return (0);
	i = 0;
	while (i < len)
		pad[i++] = c;
	if (dir == -1)
		tmp = ft_strjoin(*res, pad);
	else if (dir == 1)
		tmp = ft_strjoin(pad, *res);
	else
	{
		free(pad);
		return (-1);
	}
	free(*res);
	*res = tmp;
	return (1);
}
