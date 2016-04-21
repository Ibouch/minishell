/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_env_element.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 16:53:25 by ibouchla          #+#    #+#             */
/*   Updated: 2016/04/20 16:53:28 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_bool	search_env_element(t_env *env, char *elem)
{
	while (env != NULL)
	{
		if ((ft_strncmp(env->str, elem, ft_strlen(elem))) == 0)
			return (TRUE);
		env = env->next;
	}
	return (FALSE);
}
