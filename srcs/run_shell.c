/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 18:48:47 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/28 18:49:32 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	run_prompt(void)
{
	ft_strcolor_fd("---------", B_YELLOW, 1, TRUE);
	ft_strcolor_fd("Ib_Shell$ ", B_GREEN, 1, FALSE);
}

static void	error_read(void)
{
	ft_strcolor_fd("read call system has failed.", B_RED, 2, TRUE);
	exit(EXIT_FAILURE);
}

void print_all_cmd(char **t)
{
	int i = 0;
	while (t[i])
		ft_putendl(t[i++]);
}

void		run_shell(t_shell *sh)
{
	char	*cmd;
	int		id;

	cmd = NULL;
	while (42)
	{
		run_prompt();
		if ((get_next_line(0, &cmd)) == (-1))
			error_read();
		storage_all_cmds(sh, cmd);
		id = (-1);
		while (sh->all_cmd[++id] != NULL)
		{
			if ((determine_builtins(sh, sh->all_cmd[id])) == 1)
				continue ;
			/*if ((sh->opt = ft_strsplit(sh->all_cmd[id], ' ')) == NULL)
				ft_error_system();
			determine_prefixe(&(sh->opt[0]));
			verify_access(sh->all_cmd[id]);
			if ((execve(sh->opt[0], sh->opt, NULL)) == (-1))
			{
				ft_putstr_fd("Ishell: ", 2);
				ft_putstr_fd(sh->all_cmd[id], 2);
				ft_putendl_fd(": command not found.", 2);
				del_opt(sh->opt);
				continue;
			}
			del_opt(sh->opt);
	*/	}
		//del_all_cmd(sh->all_cmd);
	}
}
