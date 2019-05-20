/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alias.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:40:43 by akeiflin          #+#    #+#             */
/*   Updated: 2019/04/06 14:11:28 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

/*
**	if get is set, return the value in the table
**	else if addkey is set, add a value in the table
**	and return NULL
*/

char	*all_alias(char *get, char *addkey, char *addvalue)
{
	static t_table	*talias = NULL;

	if (talias == NULL)
		talias = create_table(4);
	if (get)
		return (lookup(talias, get));
	if (addkey)
		insert(talias, addkey, ft_strdup(addvalue), ft_strlen(addvalue) + 1);
	return (NULL);
}

/*
**	Builtin alias:
**	set or replace an alias in my shell
*/

int		ft_alias(char **argv, char ***env)
{
	int		argc;

	(void)env;
	argc = count_arg(argv);
	if (argc == 1)
		all_alias(NULL, argv[1], NULL);
	else if (argc == 2)
		all_alias(NULL, argv[1], argv[2]);
	else
		ft_putendl("usage:\talias <alias>\n\talias <alias> <command>");
	return (0);
}
