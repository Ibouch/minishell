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

int	determine_builtins(t_shell *sh, char *cmd)
{
	if ((ft_strcmp(cmd, "help")) == 0 || (ft_strcmp(cmd, "--help")) == 0)
	{
		builtin_help();
		return (1);
	}
	else if ((ft_strncmp(cmd, "env", 3)) == 0)
	{
		if (cmd[3] == ' ')
			execution_binary(sh->env, cmd);
		else if (cmd[3] == '\0')
			print_environment(sh->env);
		else
			return (0);
		return (1);
	}
	else if ((ft_strncmp(cmd, "getenv", 6)) == 0)
	{
		if (cmd[6] == ' ')
			builtin_get_or_unset(&(sh->env), cmd, 6, &get_value_env);
		else if (cmd[6] == '\0')
			print_environment(sh->env);
		else
			return (0);
		return(1);
	}
	else if ((ft_strncmp(cmd, "setenv", 6)) == 0)
	{
		if (cmd[6] == ' ')
			builtin_setenv(&(sh->env), cmd);
		else if (cmd[6] == '\0')
			print_environment(sh->env);
		else
			return (0);
		return (1);
	}
	else if ((ft_strncmp(cmd, "unsetenv", 8)) == 0)
	{
		if (cmd[8] == ' ')
			builtin_get_or_unset(&(sh->env), cmd, 8, &remove_var_env);
		else if (cmd[8] == '\0')
			print_environment(sh->env);
		else
			return (0);
		return (1);
	}
	else if ((ft_strncmp(cmd, "exit", 4)) == 0)
	{
		if (cmd[4] == ' ')
			;//builtin_exit(cmd);
		else
			exit(EXIT_SUCCESS);
		return (1);
	}
	else
		return (0);
}
