/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_root.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:50:34 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/07 08:35:54 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/exec.h"

int	exec_root(t_param *prm, t_node *root, char *env[])
{
	int	pipe_pid;

	init_signal_parent();
	if (root->token_type == TK_DAMP)
	{
		exec_root(prm, root->left, env);
		if (g_return_value == 0)
			exec_root(prm, root->right, env);
	}
	else if (root->token_type == TK_DPIPE)
	{
		exec_root(prm, root->left, env);
		if (g_return_value != 0)
			exec_root(prm, root->right, env);
	}
	else
	{
		pipe_pid = fork();
		if (pipe_pid == 0)
		{
			init_signal_parent_during_heredoc();
			exec_pipe(prm, root, env);
		}
		else
			waitpid(pipe_pid, NULL, 0);
	}
	return (g_return_value);
}
