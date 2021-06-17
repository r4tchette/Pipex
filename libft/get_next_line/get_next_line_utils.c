/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 17:18:58 by yeonkim           #+#    #+#             */
/*   Updated: 2021/05/25 14:29:30 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		free_data(char **s, int ret)
{
	if (!*s)
		return (-2);
	free(*s);
	*s = NULL;
	return (ret);
}

int		find_newline(char *s1)
{
	int	i;

	i = -1;
	while (s1[++i])
		if (s1[i] == '\n')
			return (1);
	return (0);
}
