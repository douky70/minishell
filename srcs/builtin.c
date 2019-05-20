/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:34:02 by akeiflin          #+#    #+#             */
/*   Updated: 2019/04/12 09:40:43 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "libft.h"

int			ft_exit(char **argv, char ***env)
{
	(void)argv;
	(void)env;
	exit(1);
	return (1);
}

/*
**	Create a static hastable with all my bultin address
**	return the required builtin address
*/

t_builtin	get_builtin_func(char *cmd)
{
	static t_table	*t = NULL;

	if (t == NULL)
	{
		t = create_table(2);
		insert(t, "env", *ft_env, sizeof(ft_env));
		insert(t, "setenv", *ft_setenv, sizeof(ft_setenv));
		insert(t, "cd", *ft_cd, sizeof(ft_cd));
		insert(t, "exit", *ft_exit, sizeof(ft_exit));
		insert(t, "echo", *ft_echo, sizeof(ft_echo));
		insert(t, "unsetenv", *ft_unsetenv, sizeof(ft_unsetenv));
		insert(t, "addpath", *ft_addpath, sizeof(ft_addpath));
		insert(t, "alias", *ft_alias, sizeof(ft_alias));
		insert(t, "take", *ft_take, sizeof(ft_take));
		insert(t, "builtin", *ft_builtin, sizeof(ft_builtin));
	}
	return (lookup(t, cmd));
}
