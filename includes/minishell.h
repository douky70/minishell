/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:32:17 by akeiflin          #+#    #+#             */
/*   Updated: 2019/04/15 16:53:44 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef MAXPATHLEN
#  define MAXPATHLEN 4080
# endif

# ifndef BUFF_SIZE
#  define BUFF_SIZE 1024
# endif
# define ERR_CMD_NOT_FOUND -10
# define ERR_NO_FILE -20
# define ERR_PATH_ACCES -21
# define ERR_IS_FOLDER -22
# define ERR_UNKNOW -42
# define ERR_CD_OLDPWD -101

typedef int	(*t_builtin)(char **, char ***);

typedef struct	s_cmd
{
	char	*cmd;
	char	*fullpath;
	char	**args;
}				t_cmd;

int				err_minishell(char *buff, int error);
int				err_acces(char *buff, int error);

int				ft_exit(char **argv, char ***env);
int				ft_env(char **argv, char ***env);
int				ft_setenv(char **argv, char ***env);
int				ft_unsetenv(char **argv, char ***env);
int				ft_cd(char **argv, char ***env);
int				ft_echo(char **argv, char ***env);
int				ft_addpath(char **argv, char ***env);
int				ft_alias(char **argv, char ***env);
int				ft_take(char **argv, char ***env);
int				ft_builtin(char **argv, char ***env);

char			*all_alias(char *get, char *addkey, char *addvalue);
t_builtin		get_builtin_func(char *cmd);

void			free_env(char **env);
char			**clone_env(char **env);
int				ft_edit_env(char **env, char *looking, char *value);
char			**add_env(char **env, char *var, char *value);
char			**del_var(char **env, char *var);
char			*get_env(char **env, char *looking);

t_cmd			*parse_cmd(char **buff, char **env);
void			read_cmd(char **full_cmd);

int				exec_cmd(t_cmd *cmd, char ***env, char ***altenv);
int				run_cmd(t_cmd *cmd, char **env);

void			replace_for_parse(char *buff);
void			replace_after_parse(char **args);

void			free_tab(char **tab);
void			*free_in_tab(char **tab);
void			*free_cmd(t_cmd *cmd);
int				count_arg(char **argv);
int				is_path(char *buff);
char			**get_env_path(char **env);
#endif
