/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 13:15:24 by ibouchla          #+#    #+#             */
/*   Updated: 2016/04/12 13:15:42 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	builtin_help(void)
{
	ft_strcolor_fd("\n\t\t~~~\t", B_RED, 1, FALSE);
	ft_strcolor_fd("IB_SHELL HELP", B_WHITE, 1, FALSE);
	ft_strcolor_fd("\t~~~", B_RED, 1, TRUE);
	ft_strcolor_fd("\n\t\t*\t", B_RED, 1, FALSE);
	ft_strcolor_fd("[HELP]     : Explain how the shell run.", B_CYAN, 1, TRUE);
	ft_strcolor_fd("\t\t*\t", B_RED, 1, FALSE);
	ft_strcolor_fd("[CD]       : Change current directory.", B_CYAN, 1, TRUE);
	ft_strcolor_fd("\t\t*\t", B_RED, 1, FALSE);
	ft_strcolor_fd("[ENV]      : List all variable associated with her value \
from environment.", B_CYAN, 1, TRUE);
	ft_strcolor_fd("\t\t*\t", B_RED, 1, FALSE);
	ft_strcolor_fd("[GETENV]   : Get the value contained in the variable."
	, B_CYAN, 1, TRUE);
	ft_strcolor_fd("\t\t*\t", B_RED, 1, FALSE);
	ft_strcolor_fd("[SETENV]   : Create a new variable associated with her \
value in its environment.", B_CYAN, 1, TRUE);
	ft_strcolor_fd("\t\t*\t", B_RED, 1, FALSE);
	ft_strcolor_fd("[UNSETENV] : Delete a variable from its environment.",
	B_CYAN, 1, TRUE);
	ft_strcolor_fd("\t\t*\t", B_RED, 1, FALSE);
	ft_strcolor_fd("[EXIT]     : End a process.\n", B_CYAN, 1, TRUE);
	return (0);
}
