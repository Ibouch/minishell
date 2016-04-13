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

void	create_update_cmd(t_env **env, char *var, char *value)
{
	/*
	.	LOGNAME
	.	HOME
	.	USER
	.	SHELL
	.	PWD
	.	SHLVL
	*/
	size_t	var_len;
	char	*cmd;

	var_len = ft_strlen(var);
	if ((cmd = ft_strnew(7 + (var_len + ft_strlen(value)))) == NULL)
		ft_error_system();
	cmd = ft_strcpy(cmd, "setenv ");
	ft_strcpy((cmd + 7), var);
	ft_strcpy((cmd + (7 + var_len)), value);
//	ft_strcolor_fd(cmd, H_GREEN, 1, 1);
	builtin_setenv(env, cmd);
}
