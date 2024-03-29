/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_update_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 21:30:32 by ibouchla          #+#    #+#             */
/*   Updated: 2016/04/13 21:30:36 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	create_update_cmd(t_shell *sh, char *var, char *value)
{
	size_t	var_len;
	char	*cmd;

	var_len = ft_strlen(var);
	if ((cmd = ft_strnew(7 + (var_len + ft_strlen(value)))) == NULL)
		ft_error_system();
	cmd = ft_strcpy(cmd, "setenv ");
	ft_strcpy((cmd + 7), var);
	ft_strcpy((cmd + (7 + var_len)), value);
	sh->ret = builtin_setenv(sh, cmd);
	ft_strdel(&cmd);
	return (sh->ret);
}
