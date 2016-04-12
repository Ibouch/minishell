/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_get_or_unset.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 22:23:49 by ibouchla          #+#    #+#             */
/*   Updated: 2016/04/12 22:23:52 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void		print_error_get_or_unset(char *error, t_bool update)
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
	ft_strcolor_fd("$ unsetenv <NAME> || <PATTERN>", B_WHITE, 2, TRUE);
	ft_strcolor_fd("\t$ getenv   <NAME>\n", B_WHITE, 2, TRUE);
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

void			builtin_get_or_unset(t_env **env, char *cmd, int len,
				void f_builtin(t_env **, char *))
{
	int		i;
	char	*elem;
	t_bool	has_update;

	i = len;
	while ((ft_isspace(cmd[i])) == 1 && cmd[i] != '\0')
		++i;
	if ((elem = ft_strsub(cmd, i, (ft_strlen(cmd) - len))) == NULL)
		ft_error_system();
	ft_strdel(&cmd);
	has_update = check_update_cmd(&elem);
	if ((search_env_element(*env, elem)) == TRUE)
		f_builtin(env, elem);
	else
		print_error_get_or_unset(elem, has_update);
	ft_strdel(&elem);
}
