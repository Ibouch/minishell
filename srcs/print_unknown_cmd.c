/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unknown_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 20:30:30 by ibouchla          #+#    #+#             */
/*   Updated: 2016/04/19 20:31:06 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	print_unknown_cmd(char *cmd)
{
	ft_strcolor_fd("Ib_Shell : ", B_RED, 2, FALSE);
	ft_strcolor_fd(cmd, B_WHITE, 2, FALSE);
	ft_strcolor_fd(" ✖ command unknown or not found.", B_RED, 2, TRUE);
}
