/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_shlvl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 18:05:35 by ibouchla          #+#    #+#             */
/*   Updated: 2016/04/21 18:05:38 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	convert_shlvl(t_shell *sh, char *sh_lvl)
{
	int	i;

	i = 0;
	while ((ft_isdigit(sh_lvl[i])) == 1 && sh_lvl[i] != '\0')
		++i;
	if (sh_lvl[i] != '\0')
		create_update_cmd(sh, "SHLVL=", "1");
	else
	{
		i = ((ft_atoi(sh_lvl)) + 1);
		sh_lvl = ft_itoa(i);
		(sh_lvl != NULL) ? create_update_cmd(sh, "SHLVL=", sh_lvl) : (0);
	}
}

void		auto_shlvl(t_shell *sh, char **environ)
{
	int		i;
	char	*sh_lvl;

	i = (-1);
	sh_lvl = NULL;
	while (environ[++i] != NULL)
	{
		if ((ft_strncmp(environ[i], "SHLVL=", 6)) == 0)
		{
			sh_lvl = (environ[i] + 6);
			break ;
		}
	}
	(sh_lvl == NULL) ? env_addback(&(sh->env), "SHLVL=1") :
	convert_shlvl(sh, sh_lvl);
}
