/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isolate_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 18:55:59 by ibouchla          #+#    #+#             */
/*   Updated: 2016/04/22 18:56:02 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*isolate_name(char *pattern)
{
	int		i;
	char	*name;

	i = 0;
	while (pattern[i] != '=' && pattern[i] != '\0')
		++i;
	i = (pattern[i] != '\0') ? ++i : i;
	name = ft_strsub(pattern, 0, i);
	if (name == NULL)
		ft_error_system();
	return (name);
}
