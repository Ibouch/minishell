/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_getenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 00:20:00 by ibouchla          #+#    #+#             */
/*   Updated: 2016/04/21 00:20:13 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void		print_getenv_error(char *error, t_bool update)
{
	char	*tmp;
	int		i;

	if (update == TRUE)
	{
		i = (-1);
		if ((tmp = ft_strnew(ft_strlen(error))) == NULL)
			ft_error_system();
		while (error[++i] != '=' && error[i] != '\0')
			tmp[i] = error[i];
	}
	ft_strcolor_fd("\nIb_Shell: ", B_RED, 2, FALSE);
	ft_strcolor_fd(((update == FALSE) ? error : tmp), B_WHITE, 2, FALSE);
	ft_strcolor_fd(" unknown name or pattern.", B_RED, 2, TRUE);
	ft_strcolor_fd("Usage : ", B_BLUE, 2, FALSE);
	ft_strcolor_fd("  $ getenv <NAME> || <PATTERN>.", B_WHITE, 2, TRUE);
	if (update == TRUE)
		ft_strdel(&tmp);
}

static int		check_value_env(t_shell *sh)
{
	char	*value;

	sh->ret = 0;
	if ((search_env_element(sh->env, sh->elem)) == TRUE)
	{
		if ((value = get_value(sh->env, sh->elem)) == NULL)
		{
			ft_strcolor_fd("getenv: The value is maybe empty.", H_RED, 2, TRUE);
			sh->ret = (-1);
		}
		else
			ft_putendl(value);
	}
	else
	{
		print_getenv_error(sh->elem, sh->has_update);
		sh->ret = (-1);
	}
	return (sh->ret);
}

static t_bool	check_update_cmd(char **str)
{
	size_t	len;
	size_t	i;
	size_t	search;

	len = ft_strlen(str[0]);
	i = (-1);
	while (++i < len)
		if (str[0][i] == '=')
			return (FALSE);
	search = ((len > 0) ? 1 : 0);
	if (str[0][len - search] != '=')
	{
		storage_elem(str);
		return (TRUE);
	}
	return (FALSE);
}

int				builtin_getenv(t_shell *sh, char *cmd)
{
	int		i;

	i = 6;
	sh->ret = 0;
	while ((ft_isspace(cmd[i])) == 1 && cmd[i] != '\0')
		++i;
	if ((sh->elem = ft_strsub(cmd, i, (ft_strlen(cmd) - 6))) == NULL)
		ft_error_system();
	sh->has_update = check_update_cmd(&(sh->elem));
	check_value_env(sh);
	ft_strdel(&(sh->elem));
	return (sh->ret);
}
