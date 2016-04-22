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

static int	print_error_getcwd(void)
{
	ft_strcolor_fd("Error : getcwd call system has failed.", B_RED, 2, TRUE);
	return (-1);
}

int			update_var_environment(t_shell *sh)
{
	char	*old_pwd;
	char	*cwd;
	char	buff[PATH_MAX + 1];

	sh->ret = (-1);
	if ((search_env_element(sh->env, "PWD=")) == TRUE)
		if ((old_pwd = get_value(sh->env, "PWD")) != NULL)
			sh->ret = create_update_cmd(sh, "OLDPWD ", old_pwd);
	if ((cwd = getcwd(buff, PATH_MAX + 1)) == NULL)
		sh->ret = print_error_getcwd();
	else
		sh->ret = create_update_cmd(sh, "PWD ", cwd);
	return (sh->ret);
}
