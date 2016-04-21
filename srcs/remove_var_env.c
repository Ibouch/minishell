/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_var_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 22:16:25 by ibouchla          #+#    #+#             */
/*   Updated: 2016/04/12 22:16:28 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static t_bool	check_first_var(t_env **env, char *elem)
{
	t_env	*tmp;

	if (*env != NULL)
	{
		if ((ft_strncmp((*env)->str, elem, ft_strlen(elem))) == 0)
		{
			tmp = (*env)->next;
			ft_strdel(&((*env)->str));
			(*env)->next = NULL;
			ft_memdel((void **)&(*env));
			*env = tmp;
			return (TRUE);
		}
	}
	return (FALSE);
}

static void		delete_data(t_env **env, t_env **previous)
{
	t_env	*tmp;

	tmp = (*env)->next;
	ft_strdel(&((*env)->str));
	(*env)->next = NULL;
	ft_memdel((void **)&(*env));
	(*previous)->next = tmp;
	*env = tmp;
}

void			remove_var_env(t_env **env, char *elem)
{
	t_env	*begin;
	t_env	*previous;

	if ((check_first_var(env, elem)) == FALSE)
	{
		begin = *env;
		while (*env != NULL)
		{
			if ((ft_strncmp((*env)->str, elem, ft_strlen(elem))) == 0)
				delete_data(env, &previous);
			else
			{
				previous = *env;
				*env = (*env)->next;
			}
		}
		*env = begin;
	}
}
