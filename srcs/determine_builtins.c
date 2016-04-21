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
	{"cd", builtin_cd},
	{"env", exec_bin},
	{"getenv", builtin_getenv},
	{"setenv", builtin_setenv},
	{"unsetenv", builtin_unsetenv},
	{"exit", builtin_exit}
};

int	determine_builtins(t_shell *sh, char *cmd)
{
	int		i;
	size_t	len;

	if ((ft_strcmp(cmd, "help")) == 0 || (ft_strcmp(cmd, "--help")) == 0)
	{
		builtin_help();
		return (0);
	}
	if ((ft_strcmp(cmd, "env")) == 0)
	{
		print_environment(sh->env);
		return (0);
	}
	i = 0;
	while (i < 6)
	{
		len = ft_strlen(g_exec_builtin[i].name);
		if ((ft_strncmp(cmd, g_exec_builtin[i].name, len)) == 0)
			return (g_exec_builtin[i].f_built(sh, cmd));
		++i;
	}
	return (255);
}
