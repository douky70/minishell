/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:26:20 by akeiflin          #+#    #+#             */
/*   Updated: 2019/04/22 17:29:20 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void		free_env(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
	{
		env[i] = ft_free(env[i]);
		++i;
	}
	if (env && env[i])
		env[i] = ft_free(env[i]);
	ft_free(env);
}

void		*free_in_tab(char **tab)
{
	while (*tab)
	{
		*tab = ft_free(*tab);
		++tab;
	}
	return (NULL);
}

void		free_tab(char **tab)
{
	if (tab && *tab)
	{
		free_in_tab(tab);
		ft_free(tab);
	}
}

void		*free_cmd(t_cmd *cmd)
{
	if (cmd)
	{
		if (cmd->fullpath)
			cmd->fullpath = ft_free(cmd->fullpath);
		if (cmd->args)
		{
			free_in_tab(cmd->args);
			cmd->args = ft_free(cmd->args);
		}
		ft_free(cmd);
	}
	return (NULL);
}
