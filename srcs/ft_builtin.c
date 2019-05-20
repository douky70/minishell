/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 09:41:32 by akeiflin          #+#    #+#             */
/*   Updated: 2019/04/22 17:31:48 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

int		ft_builtin(char **argv, char ***env)
{
	(void)argv;
	(void)env;
	ft_putendl("exit, env, setenv, unsetenv, cd, echo, addpath, alias, take, "
					"builtin");
	return (0);
}
