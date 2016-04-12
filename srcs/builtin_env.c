/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:31:06 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/29 15:31:08 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	builtin_env(t_env *env)
{
	while (env != NULL)
	{
		if (env->str != NULL)
			ft_putendl(env->str);
		env = env->next;
	}
}
