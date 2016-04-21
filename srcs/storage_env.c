/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 18:31:39 by ibouchla          #+#    #+#             */
/*   Updated: 2016/04/20 17:40:03 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	storage_data(char **data, struct passwd *uid)
{
	if ((data[0] = ft_strjoin("HOME=", uid->pw_dir)) == NULL)
		ft_error_system();
	if ((data[1] = ft_strjoin("USER=", uid->pw_name)) == NULL)
		ft_error_system();
	if ((data[2] = ft_strjoin("SHELL=", uid->pw_shell)) == NULL)
		ft_error_system();
}

static char	**get_home_and_user(void)
{
	struct stat		st;
	struct passwd	*uid;
	char			**data;

	if ((lstat("./", &st)) != 0)
	{
		ft_strcolor_fd("Error : stat call system has failed", B_RED, 2, TRUE);
		return (NULL);
	}
	if ((data = (char **)malloc(sizeof(char *) * 4)) == NULL)
		ft_error_system();
	if ((uid = getpwuid(st.st_uid)) == NULL)
	{
		if ((data[0] = ft_strdup("USER=UNKNOWN UID")) == NULL)
			ft_error_system();
		if ((data[1] = ft_strdup("HOME=UNKNOWN HOME")) == NULL)
			ft_error_system();
		if ((data[2] = ft_strdup("SHELL=UNKNOWN SHELL")) == NULL)
			ft_error_system();
	}
	else
		storage_data(data, uid);
	data[3] = NULL;
	return (data);
}

static void	create_my_environment(t_shell *sh)
{
	char	**data;

	data = get_home_and_user();
	env_addback(&(sh->env),
	"PATH=/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin:/usr/local/munki");
	env_addback(&(sh->env), ((data != NULL) ? data[0] : "HOME="));
	env_addback(&(sh->env), ((data != NULL) ? data[1] : "USER="));
	env_addback(&(sh->env), ((data != NULL) ? data[2] : "SHELL="));
	if (data != NULL)
		ft_tabdel(data);
}

void		storage_env(t_shell *sh, char **environ)
{
	int	i;

	i = (-1);
	if (*environ == NULL)
		create_my_environment(sh);
	else
		while (environ[++i] != NULL)
			env_addback(&(sh->env), environ[i]);
	auto_shlvl(sh, environ);
}
