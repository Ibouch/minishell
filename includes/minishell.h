/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 19:30:08 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/26 19:31:40 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <libft.h>
# include <get_next_line.h>
# include <limits.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>

typedef struct		s_env
{
	char			*str;
	struct s_env	*next;
}					t_env;

typedef struct		s_shell
{
	t_env			*env;
	char			**all_cmd;
	int				ret;
}					t_shell;

void				storage_env(t_shell *sh, char **environ);
void				run_shell(t_shell *sh);
void				env_addback(t_env **alst, char *new_elem);
t_bool				search_env_element(t_env *env, char *elem);
int					determine_builtins(t_shell *sh, char *cmd);
int					determine_prefixe(t_env *env, char **cmd);
void				storage_all_cmds(t_shell *sh, char *cmd);
void				storage_elem(char **str);
void				builtin_setenv(t_env **env, char *cmd);
void				builtin_get_or_unset(t_env **env, char *cmd, int len,
					void f_builtin(t_env **, char *));
void				remove_var_env(t_env **env, char *elem);
void				print_setenv_usage(void);
void				print_environment(t_env *env);
void				get_value_env(t_env **env, char *elem);
void				builtin_help(void);
/* a voir */void	update_var_environment(t_env **env);
/* a voir */void	create_update_cmd(t_env **env, char *var, char *value);
char				**list_to_tab(t_env *env);
int					execution_binary(t_env *env, char *cmd);
void				builtin_cd(t_env **env, char *cmd);
char				*get_value(t_env *env, char *elem);

#endif
