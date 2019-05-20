/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 10:38:14 by akeiflin          #+#    #+#             */
/*   Updated: 2019/04/06 14:18:06 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minishell.h"

int		count_arg(char **argv)
{
	int	i;

	i = -1;
	while (*argv)
	{
		++i;
		++argv;
	}
	return (i);
}

int		is_path(char *buff)
{
	if (ft_strchr(buff, '/') != NULL)
		return (1);
	return (0);
}

/*
**	return a char** filled with all path null terminated
*/

char	**get_env_path(char **env)
{
	char	*path;
	char	**paths;

	path = get_env(env, "PATH");
	if (path)
	{
		paths = ft_strsplit(path, ':');
		return (paths);
	}
	else
		return (NULL);
}
