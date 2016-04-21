/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 17:50:32 by ibouchla          #+#    #+#             */
/*   Updated: 2016/04/20 17:50:34 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	verify_access(t_env *env, char **binary, char *cmd)
{
	struct stat	st;

	if ((determine_prefixe(env, binary)) != 1 || (access(*binary, X_OK)) != 0)
	{
		print_unknown_cmd(cmd);
		return (0);
	}
	if ((stat(*binary, &st)) != 0)
	{
		ft_strcolor_fd("stat call system has failed.", H_RED, 2, TRUE);
		return (-1);
	}
	if (!S_ISREG(st.st_mode))
	{
		print_unknown_cmd(cmd);
		return (0);
	}
	return (1);
}

int			exec_bin(t_shell *sh, char *cmd)
{
	pid_t	child;
	char	**tab_env;
	char	**arg;

	tab_env = list_to_tab(sh->env);
	if ((arg = ft_strsplit(cmd, ' ')) == NULL)
		ft_error_system();
	if (arg[0] == NULL)
		return (-1);
	if ((verify_access(sh->env, &arg[0], cmd)) != 1)
		return (1);
	if ((child = fork()) > 0)
	{
		sh->ret = waitpid(-1, &(sh->wait_status), WUNTRACED);
		if (WIFEXITED(sh->wait_status))
			sh->ret = WEXITSTATUS(sh->wait_status);
	}
	else if (child == 0)
		exit((execve(arg[0], arg, tab_env)));
	else
		ft_strcolor_fd("Fork call system has failed.", B_RED, 2, TRUE);
	ft_tabdel(tab_env);
	ft_tabdel(arg);
	return (sh->ret);
}
