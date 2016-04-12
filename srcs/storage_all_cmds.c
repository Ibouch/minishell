/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage_all_cmds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 22:16:21 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/28 22:16:36 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	clean_all_cmd(char **all_cmd)
{
	int		i;
	char	*tmp;

	i = (-1);
	while (all_cmd[++i] != NULL)
		if ((tmp = ft_strtrim(all_cmd[i])) != NULL)
		{
			ft_strdel(&(all_cmd[i]));
			if ((all_cmd[i] = ft_strdup(tmp)) == NULL)
				ft_error_system();
			ft_strdel(&tmp);
		}
}

void		storage_all_cmds(t_shell *sh, char *cmd)
{
	if ((sh->all_cmd = ft_strsplit(cmd, ';')) == NULL)
		ft_error_system();
	ft_strdel(&cmd);
	clean_all_cmd(sh->all_cmd);
}
