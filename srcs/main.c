/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:11:15 by yeonkim           #+#    #+#             */
/*   Updated: 2021/06/26 20:06:08 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];

	if (argc < 4)
	{
		ft_printf("usage: pipex file1 cmd1 cmd2 cmd3 ... cmdn file2");
		return (-1);
	}
	if (open_fd(argc, argv, fd) == -1)
		return (-1);
	loop(fd, argv + 1 + (!(ft_strncmp(argv[1], "here_doc", 8)) ? 1 : 0), envp);
	close(fd[0]);
	close(fd[1]);
	remove_tempfile(argv, envp);
	return (0);
}
