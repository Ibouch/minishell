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

typedef struct		s_env
{
	char			*str;
	struct s_env	*next;
}					t_env;

typedef struct		s_shell
{
	t_env			*env;
	char			**all_cmd;
	char			**opt;
}					t_shell;

void				storage_env(t_shell *sh, char **environ);
void				run_shell(t_shell *sh);
void				env_addback(t_env **alst, char *new_elem);
t_bool				search_env_element(t_env *env, char *elem);
int					determine_builtins(t_shell *sh, char *cmd);
void				determine_prefixe(char	**cmd);
void				storage_all_cmds(t_shell *sh, char *cmd);
void				storage_elem(char **str);
void				builtin_env(t_env *env);
void				builtin_setenv(t_env **env, char *cmd);
void				builtin_get_or_unset(t_env **env, char *cmd, int len,
					void f_builtin(t_env **, char *));
void				remove_var_env(t_env **env, char *elem);
void				print_setenv_usage(void);
void				get_value_env(t_env **env, char *elem);
void				builtin_help(void);
void				update_var_environment(t_env **env);
void				create_update_cmd(t_env **env, char *var, char *value);

#endif
