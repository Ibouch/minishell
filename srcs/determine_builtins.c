/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_builtins.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:15:48 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/29 15:16:32 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static t_built const	g_exec_builtin[6] =
{
	{"cd", builtin_cd, FALSE},
	{"env", exec_bin, FALSE},
	{"getenv", builtin_getenv, TRUE},
	{"setenv", builtin_setenv, TRUE},
	{"unsetenv", builtin_unsetenv, TRUE},
	{"exit", builtin_exit, FALSE}
};

int	determine_builtins(t_shell *sh, char *cmd)
{
	int		i;
	size_t	len;
	char	c;

	if ((ft_strcmp(cmd, "help")) == 0 || (ft_strcmp(cmd, "--help")) == 0)
		return (builtin_help());
	if ((ft_strcmp(cmd, "env")) == 0)
		return (print_environment(sh->env));
	i = 0;
	while (i < 6)
	{
		len = ft_strlen(g_exec_builtin[i].name);
		if ((ft_strncmp(cmd, g_exec_builtin[i].name, len)) == 0)
		{
			c = cmd[len];
			if (c == '\0' && g_exec_builtin[i].print_env == TRUE)
				return (print_environment(sh->env));
			if ((ft_isspace(c)) == 0 && g_exec_builtin[i].print_env == TRUE)
				return (255);
			return (g_exec_builtin[i].f_built(sh, cmd));
		}
		++i;
	}
	return (255);
}
