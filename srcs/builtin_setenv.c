/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:36:00 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/29 16:36:03 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*get_new_env(char *tab[2])
{
	size_t	i;
	char	*tmp;
	char	*new_env;

	if (tab[1] == NULL)
		return (ft_strdup(tab[0]));
	i = 0;
	while (((ft_isspace(tab[1][i])) == 1 || tab[1][i] == '=')
	&& tab[1][i] != '\0')
		++i;
	i = ((tab[1][i] == '\0') ? 0 : i);
	tmp = ft_strsub(tab[1], i, ft_strlen(tab[1]) - i);
	new_env = ft_strjoin(tab[0], tmp);
	ft_strdel(&tmp);
	if (new_env == NULL)
		ft_error_system();
	return (new_env);
}

static void	update_env(char **astr, char *tab[2])
{
	char	*new;

	ft_strdel(&(*astr));
	if ((new = get_new_env(tab)) == NULL)
		ft_error_system();
	*astr = new;
}

static int	check_only_elem(char *str)
{
	size_t	len;
	size_t	search;

	len = ft_strlen(str);
	search = ((len > 0) ? 1 : 0);
	if (str[len - search] != '=')
	{
		print_setenv_usage();
		return (-1);
	}
	return (0);
}

static int	storage_elem_value(char *tab[2], char *cmd)
{
	int		i;
	char	*tmp;

	i = 6;
	while ((ft_isspace(cmd[i])) == 1 && cmd[i] != '\0')
		++i;
	if ((tmp = ft_strsub(cmd, i, (ft_strlen(cmd) - 6))) == NULL)
		ft_error_system();
	if (tmp[0] == '=')
	{
		print_setenv_usage();
		ft_strdel(&tmp);
		return (-1);
	}
	ft_strdel(&cmd);
	i = 0;
	while (((ft_isspace(tmp[i])) == 0 && tmp[i] != '=') && tmp[i] != '\0')
		++i;
	i = ((ft_isspace(tmp[i])) == 1) ? --i : i;
	tab[0] = ((tmp[i] == '\0') ? tmp : ft_strsub(tmp, 0, ++i));
	tab[1] = ((tmp[i] == '\0') ? NULL : ft_strsub(tmp, i, ft_strlen(tmp) - i));
	if ((ft_isspace(tmp[i])) == 1)
		storage_elem(&tab[0]);
	ft_strdel(&tmp);
	return (0);
}

void		builtin_setenv(t_env **env, char *cmd)
{
	char	*tab[2];
	t_env	*begin;

	if ((storage_elem_value(tab, cmd)) == (-1))
		return ;
	if ((check_only_elem(tab[0])) == (-1))
		return ;
	begin = *env;
	if ((search_env_element(*env, tab[0])) == TRUE)
		while (*env != NULL)
		{
			if ((ft_strncmp((*env)->str, tab[0], ft_strlen(tab[0]))) == 0)
			{
				update_env(&((*env)->str), tab);
				break ;
			}
			*env = (*env)->next;
		}
	else
		env_addback(env, get_new_env(tab)); // LEAKS > mettre get_new_env dans une variable
	ft_strdel(&(tab[0]));
	if (tab[1] != NULL)
		ft_strdel(&(tab[1]));
	*env = begin;
}
