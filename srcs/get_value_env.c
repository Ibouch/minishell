/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 21:54:18 by ibouchla          #+#    #+#             */
/*   Updated: 2016/04/12 21:54:33 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	get_value_env(t_env **env, char *elem)
{
	size_t	i;
	t_env	*begin;
	char	*value;

	i = 0;
	begin = *env;
	while (*env != NULL)
	{
		if ((ft_strncmp((*env)->str, elem, ft_strlen(elem))) == 0)
		{
			value = (*env)->str;
			while (value[i] != '=' && value[i] != '\0')
				++i;
			if (ft_strlen(value) > (i + 1))
				ft_putendl((value + (++i)));
			else
				ft_strcolor_fd("Error :\tThe value is empty.", B_RED, 2, TRUE);
		}
		*env = (*env)->next;
	}
	*env = begin;
}
