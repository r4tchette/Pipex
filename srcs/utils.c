#include "pipex.h"

int			path_size(char **path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	return (i);
}

char    	**get_path(char *envp[])
{
	char	*path;
	int		i;

	i = -1;
	while (envp[++i])
		if (!ft_strncmp(envp[i], "PATH=", 5))
			path = ft_strdup(envp[i] + 5);
	return (ft_split(path, ':'));
}

int         free_path(char **path)
{
    int i;

    if (!path)
        return (-1);
    i = -1;
    if (path[++i])
        free(path[i]);
    free(path);
    return (0);
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

int	    	free_program(t_program *prgm)
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