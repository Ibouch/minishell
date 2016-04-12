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

void	determine_prefixe(char	**cmd)
{
	char	**a_path;
	char	*tmp;

	if (cmd != NULL)
	{
		a_path = ft_strsplit()
		if ((ft_strncmp(*cmd, "/bin/", 5)) != 0)
		{
			if ((tmp = ft_strnew(ft_strlen(*cmd))) == NULL)
				ft_error_system();
			tmp = ft_strcpy(tmp, *cmd);
			ft_strdel(&(*cmd));
			*cmd = ft_strjoin("/bin/", tmp);
			ft_strdel(&(tmp));
		}
	}
}
