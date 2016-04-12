/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 18:31:39 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/28 18:31:58 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	create_my_environment(t_shell *sh)
{
	env_addback(&(sh->env), "PATH=/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin:\
/usr/local/munki");
	env_addback(&(sh->env), "LOGNAME=");
	env_addback(&(sh->env), "HOME=");
	env_addback(&(sh->env), "USER=");
	env_addback(&(sh->env), "SHELL=");
	env_addback(&(sh->env), "PWD=");
	env_addback(&(sh->env), "SHLVL=1");
}

void		storage_env(t_shell *sh, char **environ)
{
	int	i;

	if (*environ == NULL)
		create_my_environment(sh);
	else
	{
		i = (-1);
		while (environ[++i] != NULL)
			env_addback(&(sh->env), environ[i]);
	}
}
