/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 01:59:00 by nuno              #+#    #+#             */
/*   Updated: 2025/07/03 21:35:34 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtins.h"

// function to find the env variable in the list
t_env_var	*find_env_var(t_env *env, char *key)
{
	t_env_var	*tmp;

	tmp = env->head;
	while (tmp)
	{
		if (ft_strncmp(tmp->key, key, ft_strlen(tmp->key)) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

// function to remove a variable from the list
void	remove_env_var(t_env *env, char *key)
{
	t_env_var	*tmp;
	t_env_var	*prev;

	tmp = env->head;
	prev = NULL;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, key) == 0)
		{
			if (prev)
				prev->next = tmp->next;
			else
				env->head = tmp->next;
			if (!tmp->next)
				env->last = prev;
			free_env_var(tmp);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

// function to unset an environment variable
void	unset_env_var(t_shell *shell, char *key)
{
	t_env_var	*env_var;

	if (!key || !*key)
	{
		ft_printf_fd(2, "minishell: unset: `': not a valid identifier\n");
		shell->exit_value = 1;
		return ;
	}

	env_var = find_env_var(shell->env, key);
	if (!env_var)
	{
		ft_printf_fd(2, "minishell: unset: `%s': variable not found\n", key);
		shell->exit_value = 1;
		return ;
	}
	else
	{
		remove_env_var(shell->env, key);
		shell->exit_value = 0;
	}
}

// function to unset multiple environment variables
void	unset_vars(t_cmd *cmd, t_shell *shell)
{
	int		i;
	char	**keys;

	if (!cmd || !cmd->args || !shell)
		return ;
	keys = cmd->args;
	i = 0;
	while (keys[i])
	{
		unset_env_var(shell, keys[i]);
		i++;
	}
}
