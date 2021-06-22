#include "pipex.h"
#include <stdio.h>

typedef struct	s_program
{
	char	**pathname;
	char	**argv;
}				t_program;

int			path_size(char **path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	return (i);
}

t_program	*parse_program(char *argv, char **path)
{
	t_program	*prgm;
	int			i;

	prgm = malloc(sizeof(t_program));
	if (!prgm)
		return (NULL);
	prgm->argv = ft_split(argv, ' ');
	prgm->pathname = malloc(sizeof(char) * path_size(path));
	i = -1;
	while (path[++i])
		prgm->pathname[i] = ft_strjoin(ft_strjoin(path[i], "/"), prgm->argv[0]);
	return (prgm);
}

char	**get_path(char *envp[])
{
	char	*path;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			path = ft_strdup(envp[i] + 5);
		}
		i++;
	}
	return (ft_split(path, ':'));
}

int		free_program(t_program *prgm)
{
	int	i;

	if (!prgm)
		return (0);
	if (prgm->pathname)
	{
		i = -1;
		while (prgm->pathname[++i])
			free(prgm->pathname[i]);
		free(prgm->pathname);
	}
	if (prgm->argv)
	{
		i = -1;
		while (prgm->argv[++i])
			free(prgm->argv[i]);
		free(prgm->argv);
	}
	free(prgm);
	return (0);
}

int		execute_program(char *arg, char **envp)
{
	int			i;
	t_program	*prgm;
	char		**path;

	i = -1;
	path = get_path(envp);
	prgm = parse_program(arg, path);
	while (prgm->pathname[++i])
		execve(prgm->pathname[i], prgm->argv, envp);
	perror("execve");
	return (0);
}

int		loop_pipe(int fd[2], char **argv, char **envp)
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

int		main(int argc, char *argv[], char *envp[])
{
	int	fd[2];

	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd[0] < 0)
	{
		perror(argv[1]);
		return (-1);
	}
	if (fd[1] < 0)
	{
		perror(argv[argc - 1]);
		return (-1);
	}
	loop_pipe(fd, argv + 1, envp);
	close(fd[0]);
	return (0);
}
