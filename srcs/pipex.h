/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:11:22 by yeonkim           #+#    #+#             */
/*   Updated: 2021/06/26 19:12:40 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <limits.h>
# include "libft.h"

typedef struct	s_program
{
	char		**pathname;
	char		**argv;
}				t_program;

int				path_size(char **path);
t_program		*parse_program(char *argv, char **path);
int				free_program(t_program *prgm);
char			**get_path(char *envp[]);
int				free_path(char **path);

#endif
