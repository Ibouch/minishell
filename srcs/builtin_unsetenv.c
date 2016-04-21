/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 19:40:47 by ibouchla          #+#    #+#             */
/*   Updated: 2016/04/21 19:40:50 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void		print_unset_error(char *error, t_bool update)
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
	ft_strcolor_fd("  $ unsetenv <NAME> || <PATTERN>", B_WHITE, 2, TRUE);
	if (update == TRUE)
		ft_strdel(&tmp);
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

int				builtin_unsetenv(t_shell *sh, char *cmd)
{
	int		i;
	char	*elem;
	t_bool	has_update;

	i = 8;
	sh->ret = 0;
	if ((ft_strcmp(cmd, "unsetenv")) == 0)
		return (print_environment(sh->env));
	while ((ft_isspace(cmd[i])) == 1 && cmd[i] != '\0')
		++i;
	if ((elem = ft_strsub(cmd, i, (ft_strlen(cmd) - 8))) == NULL)
		ft_error_system();
	has_update = check_update_cmd(&elem);
	if ((search_env_element(sh->env, elem)) == TRUE)
		remove_var_env(&(sh->env), elem);
	else
	{
		print_unset_error(elem, has_update);
		sh->ret = (-1);
	}
	ft_strdel(&elem);
	return (sh->ret);
}
