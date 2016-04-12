/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_addback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 19:22:58 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/28 19:27:19 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	env_addback(t_env **alst, char *new_elem)
{
	t_env	*new;
	t_env	*tmp;

	if ((new = (t_env *)ft_memalloc(sizeof(t_env))) == NULL)
		ft_error_system();
	if ((new->str = ft_strdup(new_elem)) == NULL)
		ft_error_system();
	new->next = NULL;
	if (*alst != NULL)
	{
		tmp = *alst;
		while ((*alst)->next != NULL)
			*alst = (*alst)->next;
		(*alst)->next = new;
		*alst = tmp;
	}
	else
		*alst = new;
}
