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
	if (SIGINT == val)
		write(1, "\n", 1);
	ft_strcolor_fd("------------", B_BLACK, 1, TRUE);
	ft_strcolor_fd("➤  ", ((val == 0) ? B_GREEN : B_RED), 1, FALSE);
	ft_strcolor_fd("Ib_Shell$ ", B_CYAN, 1, FALSE);
}

static void	error_read(void)
{
	ft_strcolor_fd("read call system has failed.", B_RED, 2, TRUE);
	exit(EXIT_FAILURE);
}

static void	start_shell(t_shell *sh)
{
	char	*cmd;

	cmd = NULL;
	run_prompt(sh->ret);
	signal(SIGINT, run_prompt);
	signal(SIGTSTP, SIG_IGN);
	if ((sh->rd = (get_next_line(0, &cmd))) == (-1))
		error_read();
	storage_all_cmds(sh, cmd);
}

void		run_shell(t_shell *sh)
{
	int		val;
	int		id;

	while (42)
	{
		start_shell(sh);
		id = (-1);
		while (sh->all_cmd[++id] != NULL)
		{
			if ((val = determine_builtins(sh, sh->all_cmd[id])) == 255)
				if ((val = exec_bin(sh, sh->all_cmd[id])) == -1 || val == 255)
					print_unknown_cmd(sh->all_cmd[id]);
			sh->ret = val;
		}
		ft_tabdel(sh->all_cmd);
		if (sh->rd == 0)
			break ;
	}
}
