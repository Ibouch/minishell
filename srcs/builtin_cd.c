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
	if ((access(dir, X_OK)) != 0)
	{
		ft_strcolor_fd("cd: ", H_RED, 2, FALSE);
		ft_strcolor_fd(dir, H_WHITE, 2, FALSE);
		ft_strcolor_fd(": Permission denied.", H_RED, 2, TRUE);
		return (-1);
	}
	if ((check_is_directory(dir)) == (-1))
		return (-1);
	return (0);
}

static char	*get_home_directory(t_env *env, char *dir)
{
	char	*tmp;
	char	*home;

	if ((search_env_element(env, "HOME=")) == FALSE
	|| (tmp = get_value(env, "HOME")) == NULL)
	{
		ft_strcolor_fd("cd: Home directory was not found.", H_RED, 2, TRUE);
		return (NULL);
	}
	if ((home = ft_strnew(ft_strlen(tmp) + ft_strlen(dir))) == NULL)
		ft_error_system();
	home = ft_strcpy(home, tmp);
	ft_strcat(home, (dir + 1));
	return (home);
}

static void	go_change_directory(t_env **env, char *path)
{
	if (path == NULL)
	{
		ft_strcolor_fd("cd: Can't change directory.", H_RED, 2, TRUE);
		return ;
	}
	if ((check_access_rights(path)) == 0)
	{
		if ((chdir(path)) != 0)
		{
			ft_strcolor_fd("cd: An error has occured.", H_RED, 2, TRUE);
			return ;
		}
		update_var_environment(env);
	}
}

void		builtin_cd(t_env **env, char *cmd)
{
	char	**arg;
	char	*home;

	if ((arg = ft_strsplit(cmd, ' ')) == NULL)
		ft_error_system();
	if ((ft_size_tab(arg)) != 2)
	{
		if ((ft_size_tab(arg)) == 1)
			go_change_directory(env, get_value(*env, "HOME"));
		else if ((ft_size_tab(arg)) > 2)
			ft_strcolor_fd("cd: Too many arguments.", H_RED, 2, TRUE);
		ft_tabdel(arg);
		return ;
	}
	if ((ft_strncmp(arg[1], "~", 1)) == 0)
	{
		if ((home = get_home_directory(*env, arg[1])) != NULL)
		{
			go_change_directory(env, home);
			ft_strdel(&home);
		}
	}
	else
		go_change_directory(env, arg[1]);
	ft_tabdel(arg);
}
