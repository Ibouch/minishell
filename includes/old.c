/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 22:13:17 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/26 22:13:21 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	del_all_cmd(char **all_cmd)	/* ft_tabdel(char **tab)*/
{
	int	i;

	i = (-1);
	while (all_cmd[++i] != NULL)
		ft_strdel(&(all_cmd[i]));
	free(all_cmd);
	all_cmd = NULL;
}

void	del_opt(char **opt)   /* ft_tabdel(char **tab)*/
{
	int	i;

	i = (-1);
	while (opt[++i] != NULL)
		ft_strdel(&(opt[i]));
	free(opt);
	opt = NULL;
}

void print_all_cmd(char **t)
{
	int i = 0;
	while (t[i])
		ft_putendl(t[i++]);
}

void	determine_prefixe(char	**cmd)
{
	char	*tmp;

	if (cmd != NULL)
		if ((ft_strncmp(*cmd, "/bin/", 5)) != 0)
		{
			if ((tmp = ft_strnew(ft_strlen(*cmd))) == NULL)
				ft_error_system();
			tmp = ft_strcpy(tmp, *cmd);
			ft_strdel(&(*cmd));
			*cmd = ft_strjoin("/bin/", tmp);
			ft_strdel(&(tmp));
		}
	/*
	**	Name of exe are in PATH env
	*/
}

void	clean_all_cmd(char **all_cmd)
{
	int		i;
	char	*tmp;

	i = (-1);
	while (all_cmd[++i] != NULL)
		if ((tmp = ft_strtrim(all_cmd[i])) != NULL)
		{
			ft_strdel(&(all_cmd[i]));
			all_cmd[i] = tmp;
		}
}

int	main(void)
{
	t_env	*e;
	int		id;

	if ((e = (t_env *)ft_memalloc(sizeof(t_env))) == NULL)
		ft_error_system();
	while (42)
	{
		ft_putendl("---------");
		ft_putstr("Ib_Shell$ ");
		if ((get_next_line(0, &(e->cmd))) == (-1))
		{
			ft_putendl_fd("read call system has failed.", 2);
			continue;
		}
		e->all_cmd = ft_strsplit(e->cmd, ';');
		ft_strdel(&(e->cmd));
		id = (-1);
		clean_all_cmd(e->all_cmd);
		while (e->all_cmd[++id] != NULL)
		{
			/* env; setenv; unsetenv; exit (fonction int pour savoir)*/
			if ((e->opt = ft_strsplit(e->all_cmd[id], ' ')) == NULL)
				ft_error_system();
			determine_prefixe(&(e->opt[0]));
			if ((execve(e->opt[0], e->opt, NULL)) == (-1))
			{
				ft_putstr_fd("Ishell: ", 2);
				ft_putstr_fd(e->all_cmd[id], 2);
				ft_putendl_fd(": command not found.", 2);
				del_opt(e->opt);
				continue;
			}
			del_opt(e->opt);
		}
		del_all_cmd(e->all_cmd);
	}
}
