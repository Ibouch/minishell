/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage_new_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 19:53:50 by ibouchla          #+#    #+#             */
/*   Updated: 2016/04/22 19:53:55 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	storage_new_env(t_shell *sh, char *name, char *new)
{
	t_env	*begin;

	begin = sh->env;
	if ((search_env_element(sh->env, name)) == TRUE)
	{
		while (sh->env != NULL)
		{
			if ((ft_strncmp(sh->env->str, name, ft_strlen(name))) == 0)
			{
				ft_strdel(&(sh->env->str));
				sh->env->str = new;
				break ;
			}
			sh->env = sh->env->next;
		}
	}
	else
		env_addback(&(sh->env), new);
	if (begin != NULL)
		sh->env = begin;
}
