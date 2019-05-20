/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:06:58 by akeiflin          #+#    #+#             */
/*   Updated: 2019/04/10 19:29:36 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <unistd.h>
#include "libft.h"
#include "minishell.h"

/*
**	builtin take:
**	create and cd in a folder
*/

int			ft_take(char **argv, char ***env)
{
	int		argc;

	argc = count_arg(argv);
	if (argc == 1)
	{
		if (access(argv[1], F_OK) != 0)
		{
			if (mkdir(argv[1], 0755) == -1)
				return (err_minishell(argv[1], 0));
		}
		ft_cd(argv, env);
	}
	else
		ft_putendl("usage: take <filename>");
	return (0);
}
