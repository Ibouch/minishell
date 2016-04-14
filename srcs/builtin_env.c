/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:31:06 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/29 15:31:08 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
/*
static int	analyse_cmd(char *cmd)
{
	int		i;
	char	*tmp;

	i = 3;
	while ((ft_isspace(cmd[i])) == 1 && cmd[i] != '\0')
		++i;
	if ((tmp = ft_strsub(cmd, i, (ft_strlen(cmd) - 3))) == NULL)
		ft_error_system();
	if (tmp[0] == '=')
	{
		print_setenv_usage();
		ft_strdel(&tmp);
		return (-1);
	}
	ft_strdel(&cmd);
	check_opt(tmp);
	return (0);
}
*/

void		builtin_env(t_env *env, char *cmd)
{
	char	**tab_env;
	char	**option;

	if ((option = ft_strsplit(cmd, ' ')) == NULL)
		ft_error_system();
	tab_env = list_to_tab(env);
	if ((execve("/usr/bin/env", option, tab_env)) == (-1))
		
	ft_tabdel(tab_env);
}