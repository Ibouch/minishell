/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_prefixe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 22:38:41 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/28 22:38:54 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	check_access_right(char *path, char **cmd)
{
	char	*tmp;

	if ((tmp = ft_strnew(ft_strlen(path) + ft_strlen(*cmd) + 1)) == NULL)
		ft_error_system();
	tmp = ft_strcpy(tmp, path);
	ft_strcat(tmp, "/");
	ft_strcat(tmp, *cmd);
	if ((access(tmp, F_OK)) == 0)
	{
		ft_strdel(cmd);
		*cmd = ft_strdup(tmp);
		ft_strdel(&tmp);
		return (1);
	}
	ft_strdel(&tmp);
	return (0);
}

int			determine_prefixe(t_env *env, char **cmd)
{
	char	**all_path;
	char	*value;
	int		i;

	if ((access(*cmd, F_OK)) == 0)
		return (1);
	if ((search_env_element(env, "PATH=")) == FALSE || cmd == NULL)
		return (-1);
	value = get_value(env, "PATH");
	if ((all_path = ft_strsplit(value, ':')) == NULL)
		ft_error_system();
	i = (-1);
	while (all_path[++i] != NULL)
	{
		if ((ft_strncmp(*cmd, all_path[i], ft_strlen(all_path[i]))) != 0)
		{
			if ((check_access_right(all_path[i], cmd)) == 1)
			{
				ft_tabdel(all_path);
				return (1);
			}
		}
	}
	ft_tabdel(all_path);
	return (0);
}
