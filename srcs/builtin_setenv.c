/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:52:59 by ibouchla          #+#    #+#             */
/*   Updated: 2016/04/22 15:53:02 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*get_new_env(char **arg)
{
	char	*new;
	size_t	len_value;
	size_t	len_name;

	len_value = ((arg[1]) == NULL) ? 0 : ft_strlen(arg[1]);
	len_name = ft_strlen(arg[0]);
	new = ft_strnew((len_name + len_value) + 1);
	if (new == NULL)
		ft_error_system();
	new = ft_strcpy(new, arg[0]);
	new[len_name] = '=';
	if (arg[1] != NULL)
		ft_strcat(new, arg[1]);
	ft_tabdel(arg);
	return (new);
}

static int	print_syntax_usage(void)
{
	ft_strcolor_fd("setenv: Variable name must contain alphanumeric characters."
	, H_RED, 2, TRUE);
	return (-1);
}

static int	check_syntax(char *s)
{
	int	i;

	i = (-1);
	while (s[++i] != '\0')
	{
		if ((ft_isalpha(s[i])) == 0)
			return (print_syntax_usage());
	}
	return (0);
}

static int	storage_elem_value(char **arg)
{
	int		i;
	char	*tmp;

	i = 0;
	if (arg[0] == NULL || ft_size_tab(arg) > 2)
		return (print_setenv_usage());
	if ((check_syntax(arg[0])) == (-1))
		return (-1);
	if (arg[1] != NULL)
	{
		while ((ft_isspace(arg[1][i])) == 1 && arg[1][i] != '\0')
			++i;
		((tmp = ft_strdup(arg[1] + i)) == NULL) ? ft_error_system() : (0);
		ft_strdel(&(arg[1]));
		arg[1] = tmp;
	}
	return (0);
}

int			builtin_setenv(t_shell *sh, char *cmd)
{
	int		i;
	char	**arg;
	char	*new;
	char	*name;

	i = 6;
	while ((ft_isspace(cmd[i])) == 1 && cmd[i] != '\0')
		++i;
	((arg = ft_strsplit((cmd + i), ' ')) == NULL) ? ft_error_system() : (0);
	if ((storage_elem_value(arg)) == (-1))
	{
		ft_tabdel(arg);
		return (-1);
	}
	new = get_new_env(arg);
	name = isolate_name(new);
	storage_new_env(sh, name, new);
	ft_strdel(&name);
	return (0);
}
