/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_old_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 17:03:57 by ibouchla          #+#    #+#             */
/*   Updated: 2016/04/21 17:04:14 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_old_pwd(t_env *env, char *dir)
{
	char	*tmp;
	char	*home;

	if ((search_env_element(env, "OLDPWD=")) == FALSE
	|| (tmp = get_value(env, "OLDPWD")) == NULL)
	{
		ft_strcolor_fd("cd: Old directory was not found.", H_RED, 2, TRUE);
		return (NULL);
	}
	if ((home = ft_strnew(ft_strlen(tmp) + ft_strlen(dir))) == NULL)
		ft_error_system();
	home = ft_strcpy(home, tmp);
	ft_strcat(home, (dir + 1));
	return (home);
}
