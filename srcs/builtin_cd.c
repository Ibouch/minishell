/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:14:15 by ibouchla          #+#    #+#             */
/*   Updated: 2016/04/18 19:14:17 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <dirent.h>

static int	check_is_directory(char *dir)
{
	DIR	*directory;

	if ((directory = opendir(dir)) == NULL)
	{
		ft_strcolor_fd("cd: ", H_RED, 2, FALSE);
		ft_strcolor_fd(dir, H_WHITE, 2, FALSE);
		ft_strcolor_fd(": Not a directory.", H_RED, 2, TRUE);
		return (-1);
	}
	if ((closedir(directory)) == (-1))
	{
		ft_strcolor_fd("cd: Can't close directory.", H_RED, 2, TRUE);
		return (-1);
	}
	return (0);
}

static int	check_access_rights(char *dir)
{
	if ((access(dir, F_OK)) != 0)
	{
		ft_strcolor_fd("cd: ", H_RED, 2, FALSE);
		ft_strcolor_fd(dir, H_WHITE, 2, FALSE);
		ft_strcolor_fd(": No such file or directory.", H_RED, 2, TRUE);
		return (-1);
	}
	if ((check_is_directory(dir)) == (-1))
		return (-1);
	if ((access(dir, X_OK)) != 0)
	{
		ft_strcolor_fd("cd: ", H_RED, 2, FALSE);
		ft_strcolor_fd(dir, H_WHITE, 2, FALSE);
		ft_strcolor_fd(": Permission denied.", H_RED, 2, TRUE);
		return (-1);
	}
	return (0);
}

static int	go_change_dir(t_shell *sh, char *path)
{
	if (path == NULL)
	{
		ft_strcolor_fd("cd: Can't change directory.", H_RED, 2, TRUE);
		return (-1);
	}
	if ((check_access_rights(path)) == 0)
	{
		if ((chdir(path)) != 0)
		{
			ft_strcolor_fd("cd: An error has occured.", H_RED, 2, TRUE);
			return (-1);
		}
		sh->ret = update_var_environment(sh);
		return (sh->ret);
	}
	else
		return (-1);
}

static int	check_home_dir(t_shell *sh, char *dir)
{
	int		ret;
	char	*home;

	ret = 0;
	if ((home = get_home_directory(sh->env, dir)) != NULL)
	{
		ret = go_change_dir(sh, home);
		ft_strdel(&home);
	}
	else
		ret = (-1);
	return (ret);
}

int			builtin_cd(t_shell *sh, char *cmd)
{
	char	**arg;
	int		i;

	i = 2;
	while ((ft_isspace(cmd[i])) == 1 && cmd[i] != '\0')
		++i;
	if ((arg = ft_strsplit((cmd + i), ' ')) == NULL)
		ft_error_system();
	sh->ret = (-1);
	if ((ft_size_tab(arg)) != 1)
	{
		if ((ft_size_tab(arg)) == 0)
			sh->ret = go_change_dir(sh, get_value(sh->env, "HOME"));
		else if ((ft_size_tab(arg)) > 1)
			ft_strcolor_fd("cd: Too many arguments.", H_RED, 2, TRUE);
		ft_tabdel(arg);
		return (sh->ret);
	}
	if ((ft_strncmp(arg[0], "-", 1)) == 0)
		check_old_dir(sh->env, &(arg[0]));
	sh->ret = ((ft_strncmp(arg[0], "~", 1)) == 0) ?
	check_home_dir(sh, arg[0]) : go_change_dir(sh, arg[0]);
	ft_tabdel(arg);
	return (sh->ret);
}
