/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 17:18:58 by yeonkim           #+#    #+#             */
/*   Updated: 2020/11/16 14:50:09 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	init_buffer(int fd, char **line, char **buf, char **new_line)
{
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!*buf)
	{
		if (!(*buf = malloc((BUFFER_SIZE + 1) * sizeof(char))))
			return (-1);
		*buf[0] = '\0';
	}
	if (!(*new_line = ft_strdup(*buf)))
		return (free_data(buf, -1));
	return (0);
}

static char	*join_string(char **new_line, char *s2, size_t s2_len)
{
	char	*s1;
	char	*new_str;
	size_t	s1_len;
	size_t	i;

	s1 = *new_line;
	s1_len = ft_strlen(s1);
	if (!(new_str = malloc((s1_len + s2_len + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	while (++i < s1_len)
		new_str[i] = s1[i];
	i = -1;
	while (s2[++i])
		new_str[i + s1_len] = s2[i];
	new_str[i + s1_len] = '\0';
	free_data(new_line, 0);
	return (new_str);
}

static int	split_string(char **new_line, char **line, char **buf)
{
	char	*str;
	char	*s1;
	char	*s2;
	size_t	mid;
	size_t	i;

	str = *new_line;
	mid = 0;
	while (str[mid] && str[mid] != '\n')
		mid++;
	if (!(s1 = malloc((mid + 1) * sizeof(char))))
		return (-1);
	i = -1;
	while (++i < mid)
		s1[i] = str[i];
	s1[i] = '\0';
	*line = s1;
	if (!str[mid])
		return (free_data(buf, free_data(new_line, 0)));
	s2 = *buf;
	i = -1;
	while (str[++i + mid + 1])
		s2[i] = str[i + mid + 1];
	s2[i] = '\0';
	return (free_data(new_line, 1));
}

int			get_next_line(int fd, char **line)
{
	static char	*buf[OPEN_MAX];
	char		*new_line;
	int			rd_size;

	if (-1 == init_buffer(fd, line, &buf[fd], &new_line))
		return (-1);
	if (find_newline(new_line))
		return (split_string(&new_line, line, &buf[fd]));
	while (0 < (rd_size = read(fd, buf[fd], BUFFER_SIZE)))
	{
		buf[fd][rd_size] = '\0';
		if (!(new_line = join_string(&new_line, buf[fd], rd_size)))
			return (-1);
		if (find_newline(new_line))
			return (split_string(&new_line, line, &buf[fd]));
	}
	if (0 > rd_size)
		return (free_data(&buf[fd], free_data(&new_line, -1)));
	return (split_string(&new_line, line, &buf[fd]));
}
