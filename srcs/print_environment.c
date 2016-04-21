/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_environment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 21:53:26 by ibouchla          #+#    #+#             */
/*   Updated: 2016/04/14 21:53:28 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	print_environment(t_env *env)
{
	while (env != NULL)
	{
		if (env->str != NULL)
			ft_putendl(env->str);
		env = env->next;
	}
	return (0);
}
