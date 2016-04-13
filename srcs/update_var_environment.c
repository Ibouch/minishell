/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_var_environment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 21:30:54 by ibouchla          #+#    #+#             */
/*   Updated: 2016/04/13 21:30:58 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error_getcwd(void)
{
	ft_strcolor_fd("Error : getcwd call system has failed.", B_RED, 2, TRUE);
}

void	update_var_environment(t_env **env)
{
	char	*cwd;
	char	buff[PATH_MAX + 1];

	if ((cwd = getcwd(buff, PATH_MAX + 1)) == NULL)
		print_error_getcwd();
	else
		create_update_cmd(env, "PWD=", cwd);
}