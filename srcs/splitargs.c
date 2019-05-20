/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:50:27 by akeiflin          #+#    #+#             */
/*   Updated: 2019/03/14 17:31:46 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	replace_after_parse(char **args)
{
	char	*buff;

	while (*args)
	{
		buff = *args;
		while (*buff)
		{
			if (*buff == 7)
				*buff = ' ';
			++buff;
		}
		++args;
	}
}

void	replace_for_parse(char *buff)
{
	int		open;

	open = 0;
	while (*buff)
	{
		if (*buff == ' ' && open)
			*buff = 7;
		if (*buff == '"')
		{
			(open == 0) ? ++open : --open;
			*buff = ' ';
		}
		++buff;
	}
}
