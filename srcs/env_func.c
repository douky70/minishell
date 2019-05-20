/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 16:55:42 by akeiflin          #+#    #+#             */
/*   Updated: 2019/04/06 14:07:27 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "libft.h"

/*
**	return a clonned env
*/

char		**clone_env(char **env)
{
	int		len;
	int		i;
	char	**head;
	char	**c_env;

	i = -1;
	len = 0;
	while (env[++i])
		if (ft_strcmp(env[i], "") != 0)
			++len;
	head = ft_calloc(sizeof(char *) * (len + 1));
	c_env = head;
	while (*env)
	{
		if (ft_strcmp(*env, "") != 0)
		{
			*c_env = ft_strdup(*env);
			++c_env;
			++env;
		}
		else
			++env;
	}
	return (head);
}

/*
**	edit an entry in env
**	return 1 or 0 if the value exist or not
*/

int			ft_edit_env(char **env, char *looking, char *value)
{
	char	*new_env;
	int		i;

	i = 0;
	while (env && *env)
	{
		if (ft_strcmp(*env, looking) == '=')
		{
			new_env = ft_vjoin(3, looking, "=", value);
			*env = ft_free(*env);
			*env = new_env;
			return (1);
		}
		++env;
	}
	return (0);
}

/*
**	add a new entry in the env
**	return new env
*/

char		**add_env(char **env, char *var, char *value)
{
	size_t		i;
	size_t		j;
	char		**new_env;
	char		*new_var;

	j = 0;
	i = 0;
	while (env && env[i])
		++i;
	i += 2;
	new_env = ft_calloc(sizeof(char *) * i);
	while (j < i - 2)
	{
		new_env[j] = env[j];
		j++;
	}
	env = ft_free(env);
	new_var = ft_vjoin(3, var, "=", value);
	new_env[j] = new_var;
	return (new_env);
}

/*
**	remove the value, clone and free the old env
**	return a new env
*/

char		**del_var(char **env, char *var)
{
	int		i;
	char	**new_env;

	i = 0;
	while (env[i])
	{
		if (ft_strcmp(env[i], var) == '=')
		{
			env[i] = ft_free(env[i]);
			env[i] = ft_strdup("");
			new_env = clone_env(env);
			free_env(env);
			return (new_env);
		}
		++i;
	}
	return (env);
}

/*
**	return the env value address
*/

char		*get_env(char **env, char *looking)
{
	char	*res;
	int		i;

	i = 0;
	res = NULL;
	while (env && *env)
	{
		if (ft_strcmp(*env, looking) == '=')
			break ;
		env++;
	}
	if (env && *env)
		return ((*env) + ft_strlen(looking) + 1);
	return (NULL);
}
