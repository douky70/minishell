/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:48:42 by akeiflin          #+#    #+#             */
/*   Updated: 2019/05/20 14:58:53 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

/*
**	replace the env value on my buffer
*/

static char		*replaceenv(char *buff, char **env)
{
	char	*src;
	int		i;
	char	*torep;
	char	*head;

	head = NULL;
	src = buff;
	while (*src)
	{
		if (*src == '$')
		{
			i = 0;
			while (src[i] && src[i] != ' ' && src[i] != '"' && src[i] != '=')
				++i;
			if (i > 1)
			{
				torep = ft_strduplen(src, i);
				src = ft_strreplace(buff, torep, get_env(env, torep + 1));
				head = src;
				ft_free(torep);
			}
		}
		++src;
	}
	return ((head) ? head : ft_strdup(buff));
}

/*
**	replace the usless tab on my buffer
*/

static void		replace_tab(char *buff)
{
	int		escaped;

	escaped = 0;
	while (*buff)
	{
		if (*buff == '"')
			(escaped == 0) ? ++escaped : --escaped;
		if (!escaped && *buff == '\t')
			*buff = ' ';
		++buff;
	}
}

/*
**	return the malloced first word on my buffer
*/

static char		*first_word(char *buff)
{
	int		i;

	i = 0;
	while (*buff && *buff == ' ')
		++buff;
	while (buff[i] && buff[i] != ' ')
		++i;
	return (ft_strduplen(buff, i));
}

/*
**	replase an alias on the buffer
*/

static void		change_alias(char **buff)
{
	char	*tmp;
	char	*firstword;

	firstword = first_word(*buff);
	if ((tmp = all_alias(firstword, NULL, NULL)))
	{
		tmp = ft_strlreplace(*buff, firstword, tmp, 1);
		*buff = ft_free(*buff);
		*buff = tmp;
	}
	ft_free(firstword);
}

/*
**	parse my buffer
**	return a t_cmd
*/

t_cmd			*parse_cmd(char **buff, char **env)
{
	t_cmd	*cmd;
	char	**splitted;
	char	*strcmd;
	char	*homepath;
	char	*tmp;

	homepath = get_env(env, "HOME");
	replace_tab(*buff);
	change_alias(buff);
	strcmd = replaceenv(*buff, env);
	tmp = strcmd;
	strcmd = ft_strreplace(strcmd, "~", homepath);
	tmp = ft_free(tmp);
	replace_for_parse(strcmd);
	cmd = ft_malloc(sizeof(t_cmd));
	splitted = ft_strsplit(strcmd, ' ');
	replace_after_parse(splitted);
	cmd->cmd = splitted[0];
	cmd->args = splitted;
	cmd->fullpath = NULL;
	ft_free(strcmd);
	return (cmd);
}
