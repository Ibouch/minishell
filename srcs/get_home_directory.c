/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_home_directory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 17:03:53 by ibouchla          #+#    #+#             */
/*   Updated: 2016/04/20 17:04:19 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_home_directory(t_env *env, char *dir)
{
	char	*tmp;
	char	*home;

	if ((search_env_element(env, "HOME=")) == FALSE
	|| (tmp = get_value(env, "HOME")) == NULL)
	{
		ft_strcolor_fd("cd: Home directory was not found.", H_RED, 2, TRUE);
		return (NULL);
	}
	if ((home = ft_strnew(ft_strlen(tmp) + ft_strlen(dir))) == NULL)
		ft_error_system();
	home = ft_strcpy(home, tmp);
	ft_strcat(home, (dir + 1));
	return (home);
}
