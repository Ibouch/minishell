/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 22:09:34 by ibouchla          #+#    #+#             */
/*   Updated: 2016/04/14 22:09:46 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	size_of_list(t_env *env)
{
	int		i;
	t_env	*begin;

	i = 0;
	begin = env;
	while (env != NULL)
	{
		env = env->next;
		++i;
	}
	env = begin;
	return (i);
}

char		**list_to_tab(t_env *env)
{
	int		len;
	int		i;
	char	**result;
	t_env	*begin;

	len = size_of_list(env);
	i = (-1);
	if ((result = (char **)malloc(sizeof(char *) * (len + 1))) == NULL)
		ft_error_system();
	begin = env;
	while (++i < len && env != NULL)
	{
		if ((result[i] = ft_strdup(env->str)) == NULL)
			ft_error_system();
		env = env->next;
	}
	result[i] = NULL;
	env = begin;
	return (result);
}