#include "pipex.h"
#include <stdio.h>
#include <string.h>

// infile -> buffer -> [cmd] -> buffer -> outfile

char	*get_path(char *envp[])
{
	char	*path;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!strncmp(envp[i], "PATH=", 5))
		{
			path = strdup(envp[i] + 5);
		}
		i++;
	}
	return (path);
}

int	execution(int argc, char *argv[], char *envp[])
{
	int	i;
	int	fd;

	i = 1;
	while (i < argc - 2)
	{
		i++;
	}
	return (i);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		i;
	int		fd[2];
	int		pd[2];
	char	*path;

	path = get_path(envp);
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT);
	// argv[1] :		infile
	// argv[argc - 1] :	outfile

	//pipe(pd);
	//fork();
	//close(pd[0]);
	//dup2(fd[0], 0);
	//close(pd[1]);
	//dup2(fd[1], 1);
	//execve("/bin/", &argv[2], envp);
	execve("/usr/bin/ls", &argv[2], envp);

	close(fd[0]);
	close(fd[1]);
	free(path);
	return (0);
}
