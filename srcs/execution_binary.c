/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_binary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 20:22:08 by ibouchla          #+#    #+#             */
/*   Updated: 2016/04/15 20:22:28 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	print_unknown_cmd(char *cmd)
{
	ft_strcolor_fd("Ib_Shell : ", B_RED, 2, FALSE);
	ft_strcolor_fd(cmd, B_WHITE, 2, FALSE);
	ft_strcolor_fd(" ✖ command unknown or not found.", B_RED, 2, TRUE);
}

static int	verify_access(t_env *env, char **binary, char *cmd)
{
	struct stat	st;

	if ((determine_prefixe(env, binary)) != 1)
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
	if ((access(*binary, X_OK)) != 0)
	{
		ft_strcolor_fd("Execution of binary is forbidden.", H_RED, 2, TRUE);
		return (-1);
	}
	return (1);
}

int			execution_binary(t_env *env, char *cmd)
{
	pid_t	child;
	char	**tab_env;
	char	**arg;
	int		status;
	int		ret;

	tab_env = list_to_tab(env);
	if ((arg = ft_strsplit(cmd, ' ')) == NULL)
		ft_error_system();
	if (arg[0] == NULL)
		return (-1);
	if ((verify_access(env, &arg[0], cmd)) != 1)
		return (-1);
	ret = 0;
	if ((child = fork()) > 0)
	{
		waitpid(-1, &status, WUNTRACED);
		if (WIFEXITED(status))
			ret = WEXITSTATUS(status);
	}
	else if (child == 0)
		exit((execve(arg[0], arg, tab_env)));
	else
		ft_strcolor_fd("Fork call system has failed.", B_RED, 2, TRUE);
	ft_tabdel(tab_env);
	ft_tabdel(arg);
	return (ret);
	//return ((WIFEXITED(status)) ? WEXITSTATUS(status) : (-1));
}
//waitpid(child, &status, WIFEXITED | WUNTRACED);
