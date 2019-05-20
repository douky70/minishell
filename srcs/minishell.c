/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:23:19 by akeiflin          #+#    #+#             */
/*   Updated: 2019/05/20 15:05:21 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "minishell.h"

/*
**	Fork and exec my cmd
**	Return the cmd return value
*/

int		run_cmd(t_cmd *cmd, char **env)
{
	pid_t	process_id;
	int		returnval;

	process_id = fork();
	if (process_id > 0)
	{
		wait(&returnval);
		return (returnval);
	}
	else if (process_id == 0)
		exit(execve(cmd->fullpath, cmd->args, env));
	else
		return (-2);
}

int		main(int ac, char **av, char **env)
{
	t_cmd	*cmd;
	char	**c_env;
	char	*full_cmd;

	(void)ac;
	(void)av;
	c_env = clone_env(env);
	while (1)
	{
		full_cmd = NULL;
		if (isatty(0))
			ft_putstr("minishell$ ");
		read_cmd(&full_cmd);
		cmd = parse_cmd(&full_cmd, c_env);
		if (cmd->cmd)
			exec_cmd(cmd, &c_env, NULL);
		cmd = free_cmd(cmd);
		full_cmd = ft_free(full_cmd);
	}
	return (0);
}
