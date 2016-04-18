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

static void	run_prompt(int val)
{
	ft_strcolor_fd("------------", B_BLACK, 1, TRUE);
	ft_strcolor_fd("➤  ", ((val == 0) ? B_GREEN : B_RED), 1, FALSE);
	ft_strcolor_fd("Ib_Shell$ ", B_CYAN, 1, FALSE);
}

static void	error_read(void)
{
	ft_strcolor_fd("read call system has failed.", B_RED, 2, TRUE);
	exit(EXIT_FAILURE);
}

void		run_shell(t_shell *sh)
{
	char	*cmd;
	int		val;
	int		id;

	cmd = NULL;
	while (42)
	{
		run_prompt(sh->ret);
		if ((get_next_line(0, &cmd)) == (-1))
			error_read();
		storage_all_cmds(sh, cmd);
		id = (-1);
		while (sh->all_cmd[++id] != NULL)
		{
			update_var_environment(&(sh->env));
			if ((val = determine_builtins(sh, sh->all_cmd[id])) == 0)
				val = execution_binary(sh->env, sh->all_cmd[id]);
			sh->ret = ((sh->ret == 0) ? val : sh->ret);
		}
		ft_tabdel(sh->all_cmd);
	}
}
