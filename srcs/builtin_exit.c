/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 21:19:11 by ibouchla          #+#    #+#             */
/*   Updated: 2016/04/20 21:27:24 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	check_argument(char **arg)
{
	int	i;

	i = (-1);
	if ((ft_size_tab(arg)) > 1)
	{
		ft_strcolor_fd("exit: Too many arguments.", H_RED, 2, TRUE);
		return (-1);
	}
	while (arg[0][++i] != '\0')
		if ((ft_isdigit(arg[0][i])) == 0)
		{
			ft_strcolor_fd("exit: Bad expression.", H_RED, 2, TRUE);
			return (-1);
		}
	return (0);
}

int			builtin_exit(t_shell *sh, char *cmd)
{
	char	*tmp;
	char	**arg;

	(cmd[4] == '\0') ? exit(EXIT_SUCCESS) : (0);
	if ((ft_isspace(cmd[4])) == 0)
		return (255);
	if ((tmp = ft_strsub(cmd, 4, (ft_strlen(cmd) - 4))) == NULL)
		ft_error_system();
	((arg = ft_strsplit(tmp, ' ')) == NULL) ? ft_error_system() : (0);
	ft_strdel(&tmp);
	if ((check_argument(arg)) == (-1))
	{
		ft_tabdel(arg);
		return (-1);
	}
	sh->ret = ft_atoi(arg[0]);
	ft_tabdel(arg);
	exit(sh->ret);
}
