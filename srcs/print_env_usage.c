/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env_usage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 21:41:45 by ibouchla          #+#    #+#             */
/*   Updated: 2016/04/14 21:52:42 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	print_env_usage(void)
{
	ft_strcolor_fd("Usage : ", B_BLUE, 1, FALSE);
	ft_strcolor_fd("env [-i] [var=value] [binary [argument ...]]",
	B_WHITE, 1, TRUE);
}
