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
# include <signal.h>
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
	int				rd;
	char			**all_cmd;
	char			*elem;
	t_bool			has_update;
	int				wait_status;
	int				ret;
}					t_shell;

typedef int			(*t_exec_builtin) (t_shell *, char *);
typedef void		(*t_sig_t) (int);

typedef struct		s_built
{
	char			*name;
	t_exec_builtin	f_built;
}					t_built;

void				builtin_help(void);
int					builtin_cd(t_shell *sh, char *cmd);
int					builtin_setenv(t_shell *sh, char *cmd);
int					builtin_unsetenv(t_shell *sh, char *cmd);
int					builtin_getenv(t_shell *sh, char *cmd);
int					builtin_exit(t_shell *sh, char *cmd);
int					exec_bin(t_shell *sh, char *cmd);
void				storage_env(t_shell *sh, char **environ);
void				auto_shlvl(t_shell *sh, char **environ);
void				run_shell(t_shell *sh);
void				env_addback(t_env **alst, char *new_elem);
t_bool				search_env_element(t_env *env, char *elem);
int					determine_builtins(t_shell *sh, char *cmd);
int					determine_prefixe(t_env *env, char **cmd);
void				storage_all_cmds(t_shell *sh, char *cmd);
void				storage_elem(char **str);
void				remove_var_env(t_env **env, char *elem);
void				print_setenv_usage(void);
int					print_environment(t_env *env);
int					update_var_environment(t_shell *sh);
int					create_update_cmd(t_shell *sh, char *var, char *value);
char				**list_to_tab(t_env *env);
char				*get_value(t_env *env, char *elem);
void				print_unknown_cmd(char *cmd);
char				*get_home_directory(t_env *env, char *dir);
void				check_old_dir(t_env *env, char **pattern);

#endif
