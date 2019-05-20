/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 10:58:39 by akeiflin          #+#    #+#             */
/*   Updated: 2019/04/06 14:10:20 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

/*
**	Builtin: addpath
**	append the first argument on the PATH env entry
*/

int		ft_addpath(char **argv, char ***env)
{
	char	*path;
	char	*new_path;
	char	**new_arg;

	if (argv[1])
	{
		path = get_env(*env, "PATH");
		new_path = ft_vjoin(3, path, ":", argv[1]);
		new_arg = ft_malloc(sizeof(char *) * 4);
		new_arg[0] = ft_strdup("setenv");
		new_arg[1] = ft_strdup("PATH");
		new_arg[2] = new_path;
		new_arg[3] = NULL;
		ft_setenv(new_arg, env);
		free_tab(new_arg);
	}
	else
		ft_putendl("addpath: Too few arguments");
	return (0);
}
