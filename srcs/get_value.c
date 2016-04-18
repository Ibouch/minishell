/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 20:31:37 by ibouchla          #+#    #+#             */
/*   Updated: 2016/04/18 20:31:40 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_value(t_env *env, char *elem)
{
	size_t	i;
	char	*value;

	i = 0;
	while (env != NULL)
	{
		if ((ft_strncmp(env->str, elem, ft_strlen(elem))) == 0)
		{
			value = env->str;
			while (value[i] != '=' && value[i] != '\0')
				++i;
			if (ft_strlen(value) > (i + 1))
				return ((value + (++i)));
			else
				ft_strcolor_fd("An error has occured.", B_RED, 2, TRUE);
		}
		env = env->next;
	}
	return ((char *)NULL);
}
