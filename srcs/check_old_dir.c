/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_old_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 18:32:42 by ibouchla          #+#    #+#             */
/*   Updated: 2016/04/21 18:32:57 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	check_old_dir(t_env *env, char **pattern)
{
	char	*tmp;
	char	*old_pwd;

	if ((search_env_element(env, "OLDPWD=")) == FALSE
	|| (tmp = get_value(env, "OLDPWD")) == NULL)
	{
		ft_strcolor_fd("cd:    Old directory was not found.", H_RED, 2, TRUE);
		return ;
	}
	if ((old_pwd = ft_strnew(ft_strlen(tmp) + ft_strlen(*pattern))) == NULL)
		ft_error_system();
	old_pwd = ft_strcpy(old_pwd, tmp);
	ft_strcat(old_pwd, (*pattern + 1));
	ft_strdel(pattern);
	*pattern = old_pwd;
}
