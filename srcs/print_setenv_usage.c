/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_setenv_usage.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 23:06:46 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/29 23:07:28 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	print_setenv_usage(void)
{
	ft_strcolor_fd("\nIb_Shell: [setenv] error expected.", B_RED, 2, TRUE);
	ft_strcolor_fd("Usage : ", B_BLUE, 2, FALSE);
	ft_strcolor_fd("  $ setenv <VAR=VALUE> || <VAR VALUE>\n", B_WHITE, 2, TRUE);
}
