/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 12:03:22 by akeiflin          #+#    #+#             */
/*   Updated: 2019/04/06 14:08:30 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

int	err_minishell(char *buff, int error)
{
	if (error == ERR_CMD_NOT_FOUND)
		ft_vprint(3, "minishell: command not found: ", buff, "\n");
	else if (error == ERR_NO_FILE)
		ft_vprint(3, "minishell: no such file or directory: ", buff, "\n");
	else if (error == ERR_PATH_ACCES)
		ft_vprint(3, "minishell: permission denied: ", buff, "\n");
	else if (error == ERR_IS_FOLDER)
		ft_vprint(3, "minishell: is a directory: ", buff, "\n");
	else
		ft_vprint(3, "minishell: UNKNOW ERROR: ", buff, "\n");
	return (error);
}

int	err_acces(char *buff, int error)
{
	if (error == ERR_PATH_ACCES)
		ft_vprint(3, "cd: permission denied: ", buff, "\n");
	else if (error == ERR_NO_FILE)
		ft_vprint(3, "cd: no such file or directory: ", buff, "\n");
	else if (error == ERR_CD_OLDPWD)
		ft_putendl("cd: no such old path");
	return (error);
}
