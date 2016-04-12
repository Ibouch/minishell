
#include <minishell.h>

t_bool	search_env_element(t_env *env, char *elem)
{
	while (env != NULL)
	{
		if ((ft_strncmp(env->str, elem, ft_strlen(elem))) == 0)
			return (TRUE);
		env = env->next;
	}
	return (FALSE);
}
