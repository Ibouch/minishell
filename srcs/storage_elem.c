/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 19:38:48 by ibouchla          #+#    #+#             */
/*   Updated: 2016/04/10 19:38:51 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	storage_elem(char **str)
{
	char	*elem;

	elem = ft_strjoin(str[0], "=");
	ft_strdel(str);
	if ((str[0] = ft_strdup(elem)) == NULL)
		ft_error_system();
	ft_strdel(&elem);
}
