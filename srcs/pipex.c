/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:11:15 by yeonkim           #+#    #+#             */
/*   Updated: 2021/06/26 20:10:45 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	execute_program(char *arg, char **envp)
{
	int			i;
	char		**path;
	t_program	*prgm;

	if (!(path = get_path(envp)))
		return (-1);
	if (!(prgm = parse_program(arg, path)))
	{
		free_path(path);
		return (-1);
	}
	free_path(path);
	i = -1;
	while (prgm->pathname[++i])
		execve(prgm->pathname[i], prgm->argv, envp);
	perror("execve");
	return (0);
}

int	loop(int fd[2], char **argv, char **envp)
{
	int		p[2];
	pid_t	pid;

	while (*(++argv + 1) != NULL)
	{
		pipe(p);
		p[1] = (*(argv + 2) == NULL) ? fd[1] : p[1];
		if ((pid = fork()) == -1)
			exit(EXIT_FAILURE);
		else if (pid == 0)
		{
			dup2(fd[0], 0);
			(*(argv + 1) != NULL) ? dup2(p[1], 1) : 0;
			close(p[0]);
			execute_program(*argv, envp);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
			close(p[1]);
			fd[0] = p[0];
		}
	}
	return (0);
}

int	heredoc(const char *tempfile, const char *limiter)
{
	int		fd;
	char	*buf;

	if (0 > (fd = open(tempfile, O_CREAT | O_RDWR | O_TRUNC, 0644)))
	{
		perror(tempfile);
		return (-1);
	}
	ft_printf("> ");
	while (get_next_line(0, &buf) != 0)
	{
		if (ft_strncmp(buf, limiter, ft_strlen(limiter)) == 0)
			break ;
		ft_printf("> ");
		write(fd, buf, ft_strlen(buf));
		write(fd, "\n", 1);
		free(buf);
	}
	free(buf);
	close(fd);
	return (1);
}

int	remove_tempfile(char *argv[], char *envp[])
{
	pid_t	pid;

	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		if ((pid = fork()) == -1)
			exit(EXIT_FAILURE);
		else if (pid == 0)
			execute_program("rm -f ./temp", envp);
		else
			wait(NULL);
	}
	return (0);
}

int	open_fd(int argc, char *argv[], int *fd)
{
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		heredoc("./temp", argv[2]);
		fd[0] = open("./temp", O_RDONLY);
		fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		if ((fd[0] = open(argv[1], O_RDONLY)) < 0)
		{
			perror(argv[1]);
		}
		fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (fd[0] == -1 || fd[1] == -1)
	{
		return (-1);
	}
	return (1);
}
