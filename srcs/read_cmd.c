/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:53:57 by akeiflin          #+#    #+#             */
/*   Updated: 2019/05/20 15:00:53 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"
#include "libft.h"
#include "get_next_line.h"

/*
**	check if it's the final /n or not
*/

static int	is_end_cmd(char **buff, int n)
{
	char	*cmd;

	cmd = *buff;
	if (cmd)
	{
		while (*cmd)
		{
			if (*cmd == '"')
				(n == 0) ? n++ : n--;
			cmd++;
		}
		if (n)
		{
			*buff = ft_strljoin(*buff, "\n", FIRST);
			return (0);
		}
		return (1);
	}
	return (0);
}

/*
**	read my inputs
*/

void		read_cmd(char **full_cmd)
{
	char	*buff;
	int		waitline;
	int		i;

	i = 0;
	waitline = 0;
	while (!(waitline = is_end_cmd(full_cmd, waitline)))
	{
		if (!waitline && i != 0)
			ft_putstr(">");
		i = 1;
		if (get_next_line(0, &buff) != 1)
			exit(0);
		*full_cmd = ft_strljoin(*full_cmd, buff, BOTH);
	}
}
