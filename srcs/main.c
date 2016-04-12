/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 18:21:53 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/28 18:21:57 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(void)
{
	extern char	**environ;
	t_shell		*sh;

	if ((sh = (t_shell *)ft_memalloc(sizeof(t_shell))) == NULL)
		ft_error_system();
	storage_env(sh, environ);
	run_shell(sh);
}
